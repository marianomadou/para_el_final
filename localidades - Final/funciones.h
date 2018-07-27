#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "ArrayList.h"

typedef struct
{
    int id;
    char producto[51];
    char direccion[51];
    char localidad[51];
    char recibe[51];

}eProducto;

#endif // FUNCIONES_H_INCLUDED

int parser(char archivo[], ArrayList* arraylist);

eProducto* new_producto(void);

int mostrar(ArrayList* pList);
void imprimirLocalidades(ArrayList* listado);
int generarArchivoDeReparto(ArrayList* listado);

/// getters
int getId(eProducto* this);
char* getProducto(eProducto* this);
char* getDireccion(eProducto* this);
char* getLocalidad(eProducto* this);
char* getRecibe(eProducto* this);

/// setters
int setId(eProducto* empleado, int id);
int setProducto(eProducto* empleado, char nombre[]);
int setDireccion(eProducto* empleado, char nombre[]);
int setLocalidad(eProducto* empleado, char nombre[]);
int setRecibe(eProducto* empleado, char nombre[]);

/// Metodos de entrada
int getString(char* mensaje, char retorno[]);
