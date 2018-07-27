#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"

/** \brief LEE UN ARCHIVO CSV Y LO DEVUELVE A UN ARRAYLIST
 *
 * \param archivo[] char
 * \param listado ArrayList*
 * \return int
 *
 */
int parser(char archivo[], ArrayList* listado)
{
    int returnAux = -1;
    FILE* fp;
    char id[5];
    char producto[51];
    char direccion[51];
    char localidad[51];
    char recibe[51];
    int read;

    eProducto* p;
	if (listado != NULL)
	{
		fp = fopen(archivo,"r");
		if(fp != NULL)
		{
			while(!feof(fp))
			{
				read = fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",id,producto,direccion,localidad,recibe);
				if(read == 5)
				{
					p = new_producto();

					setId(p,atoi(id));
					setProducto(p,producto);
					setDireccion(p,direccion);
					setLocalidad(p,localidad);
					setRecibe(p,recibe);

					al_add(listado, p);
				}
				else
				{
					break;
				}
			}//while(!feof(fp))
			returnAux = 0;
		}
		else
		{
			printf("NO SE PUDO LEER EL ARCHIVO!");

		}
		fclose(fp);
	}


    return returnAux;
}

/** \brief CONSTRUCTOR
 *
 * \param void
 * \return eProducto*
 *
 */
eProducto* new_producto(void)
{
    eProducto* producto;

    producto = (eProducto*) malloc(sizeof(eProducto));

    return producto;
}

/** \brief Muestra el contenido del ArrayList
 *
 * \param pList ArrayList*
 * \return int 0 SI LA LISTA EXISTE Y CONTIENE ELEMENTOS
 *             -1 SI LA LISTA NO EXISTE O NO HAY ELEMENTOS EN LA LISTA
 */
int mostrar(ArrayList* pList)
{
    int returnAux = -1;
    eProducto* pProducto;
    int i;
    int length;

    if(pList != NULL)
    {
        length = pList->len(pList);

        if(length > 0)
        {
            printf("\n\n%4s|%20s|%20s|%15s|%12s\n\n","ID","PRODUCTO","DIRECCION","LOCALIDAD","RECIBE");

            for(i=0;i < length;i++)
            {
                pProducto = pList->get(pList,i);
                //printf("%d,%s,%s,%s,%s\n\n",getId(pProducto),getProducto(pProducto),getDireccion(pProducto),getLocalidad(pProducto),getRecibe(pProducto));
                printf("%4d|%20s|%20s|%15s|%12s\n\n",getId(pProducto),getProducto(pProducto),getDireccion(pProducto),getLocalidad(pProducto),getRecibe(pProducto));
            }

            returnAux = 0;
        }
        else
        {
            printf("\n\nNO HAY DATOS CARGADOS!!\n");
        }

    }

    return returnAux;
}

/** \brief IMPRIME LAS LOCALIDADES DISPONIBLES
 *
 * \param listado ArrayList*
 * \return void
 *
 */
void imprimirLocalidades(ArrayList* listado)
{
    eProducto* pProd;
    eProducto* eAux;
    ArrayList* alAuxiliar;
    char* A;
    char* B;
    int i;
    int j;
    int lengthA;
    int lengthB;
    int flag;

    if (listado != NULL)
    {
        alAuxiliar = al_newArrayList();
        lengthA = al_len(listado);
        for (i=1;i<lengthA;i++)
        {
            flag = 0;
            pProd = al_get(listado,i);
            A = getLocalidad(pProd);
            //printf("%s",A);
            lengthB = al_len(alAuxiliar);
            if(lengthB != 0)
            {
                for(j=0;j<lengthB;j++)
                {
                    eAux = al_get(alAuxiliar,j);
                    B = getLocalidad(eAux);
                    //printf("%s\n",B);
                    if (strcmp(A,B) == 0)
                    {
                        flag = 1;
                    }
                }
            }

            if (flag == 0)
            {
                al_add(alAuxiliar,pProd);
            }

        }
        lengthB = al_len(alAuxiliar);
        for (i=0;i<lengthB;i++)
        {
            pProd = al_get(alAuxiliar,i);
            printf("%s \n", getLocalidad(pProd));
        }
    }
}

/** \brief PIDE 3 LOCALIDADES Y GENERA UN ARCHIVO CON TODOS LOS PEDIDOS A ESAS LOCALIDADES
 *
 * \param listado ArrayList*
 * \return int
 *
 */
int generarArchivoDeReparto(ArrayList* listado)
{
    int returnAux = -1;
    FILE* fp;
    eProducto* pProd;
    char localidadUno[51];
    char localidadDos[51];
    char localidadTres[51];
    char* stringAux;
    int i;
    int length;

    if(listado != NULL)
    {
        getString("Ingrese una localidad: ",localidadUno);
        getString("Ingrese segunda localidad: ",localidadDos);
        getString("Ingrese tercera localidad: ",localidadTres);
        fp = fopen("entregas.csv","w");
        length = al_len(listado);
        for (i=0;i<length;i++)
        {
            pProd = al_get(listado,i);
            stringAux = getLocalidad(pProd);
            if (strcmp(stringAux,localidadUno) == 0 || strcmp(stringAux,localidadDos) == 0 || strcmp(stringAux,localidadTres) == 0)
            {
                fprintf(fp,"%d,%s,%s,%s,%s\n",getId(pProd),getProducto(pProd),getDireccion(pProd),getLocalidad(pProd),getRecibe(pProd));
            }
        }

        fclose(fp);

        returnAux = 0;

    }

    return returnAux;
}

/// getters
int getId(eProducto* this)
{
    int id = NULL;

    if(this != NULL)
    {
        id = this->id;
    }

    return id;
}

char* getProducto(eProducto* this)
{
    char* producto = NULL;

    if(this != NULL)
    {
        producto = this->producto;
    }

    return producto;
}

char* getDireccion(eProducto* this)
{
    char* direccion = NULL;

    if(this != NULL)
    {
        direccion = this->direccion;
    }

    return direccion;
}

char* getLocalidad(eProducto* this)
{
    char* localidad = NULL;

    if(this != NULL)
    {
        localidad = this->localidad;
    }

    return localidad;
}

char* getRecibe(eProducto* this)
{
    char* recibe = NULL;

    if(this != NULL)
    {
        recibe = this->recibe;
    }

    return recibe;
}

/// setters
int setId(eProducto* producto, int id)
{
    int returnAux = -1;

    if(producto != NULL)
    {
        producto->id = id;

        returnAux = 0;
    }

    return returnAux;
}

int setProducto(eProducto* p, char producto[])
{
    int returnAux = -1;

    if(p != NULL)
    {
        strcpy(p->producto, producto);
        returnAux = 0;
    }

    return returnAux;
}

int setDireccion(eProducto* producto, char direccion[])
{
    int returnAux = -1;

    if(producto != NULL)
    {
        strcpy(producto->direccion, direccion);
        returnAux = 0;
    }

    return returnAux;
}
int setLocalidad(eProducto* producto, char localidad[])
{
    int returnAux = -1;

    if(producto != NULL)
    {
        strcpy(producto->localidad, localidad);
        returnAux = 0;
    }

    return returnAux;
}
int setRecibe(eProducto* producto, char recibe[])
{
    int returnAux = -1;

    if(producto != NULL)
    {
        strcpy(producto->recibe, recibe);
        returnAux = 0;
    }

    return returnAux;
}



/// metodos de entrada
int getString(char* mensaje, char this[])
{
    int returnAux = 0;
    int i;

    printf(mensaje);
    fflush(stdin);
    gets(this);
    for(i=0;this[i] != '\0';i++)
    {
        if(this[i] >= '0' && this[i] <= '9')
        {
            returnAux = -1;
            break;
        }
    }
    return returnAux;
}
