#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
    ArrayList* arraylist = al_newArrayList();
    int opcion;



    do
    {
        printf("---NOMBRE_DEL_PROGRAMA---\n");
        printf("\n1. Cargar archivo\n");
        printf("2. Imprimir entregas\n");
        printf("3. Imprimir localidades\n");
        printf("4. Generar archivo de reparto\n");
        printf("9.Salir\n");

        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                parser("DATA_FINAL_V3.csv", arraylist);
                break;
            case 2:
                mostrar(arraylist);
                break;
            case 3:
                imprimirLocalidades(arraylist);
                break;
            case 4:
                imprimirLocalidades(arraylist);
                generarArchivoDeReparto(arraylist);
                break;
            default:
                opcion = 9;
                break;
        }

        system("pause");
        system("cls");
    }while(opcion != 9);

    return 0;
}
