#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "funciones.h"
#include "ArrayList.h"


typedef struct{

    int idAlumno;
    int estado;
    int edad;
    int legajo;
    char nombre[40];
    char sexo[10];
    int horas;
    float sueldo;

}eAlumno;

/** \brief aloja memoria para estructura de alumno
 *
 * \return eAlumno* puntero a dir de memoria que se alojó
 */ eAlumno* emp_newStruct();


/** \brief pide ingresar un nombre para alumno
 *
 * \param s eAlumno* estructura alumno
 * \return void
 */ void emp_newNombre(eAlumno* this);

/** \brief pide ingresar una edad para alumno, entre 18 y 99.
 *
 * \param s eAlumno* estructura alumno
 * \return void
 */ void emp_newEdad(eAlumno* this);


/** \brief pide ingresar una legajo para alumno,
 *
 * \param s eAlumno* estructura alumno
 * \return void
 */ void emp_newLegajo(eAlumno* this);

/** \brief pide seleccionar opcion de sexo para alumno
 *
 * \param s eAlumno* estructura alumno
 * \return int numero de acuerdo a profesion para poder setear sexo
 */ int emp_newSexo(eAlumno* this);

/** \brief pide seleccionar opcion de horas para alumno
 *
 * \param s eAlumno* estructura alumno
 * \return int numero de acuerdo a profesion para poder setear horas
 */ void emp_newHoras(eAlumno* this);

//FUNCIONES SET

/** \brief setea nombre de alumno
 *
 * \param s eAlumno* estructura alumno, name char*.
 * \return void
 */ void emp_setNombre(eAlumno* this, char* nombre);

/** \brief setea nombre de alumno
 *
 * \param s eAlumno* estructura alumno, Profesion char*.
 * \return void
 */ void emp_setSexo(eAlumno* this, char* Profesion);


/** \brief setea salario de alumno
 *
 * \param s eAlumno* estructura alumno, int edad.
 * \return void
 */ void emp_setEdad (eAlumno* this, int edad);

/** \brief setea legajo de alumno
 *
 * \param s eAlumno* estructura alumno, int legajo.
 * \return void
 */ void emp_setLegajo (eAlumno* this, int legajo);


 /** \brief setea el id de un alumno
 *
 * \param s eAlumno* estructura alumno,  id int* puntero a id autoincremental
 * \return void
 */ void emp_setId(eAlumno* this,int* id);

/** \brief setea el estado de un alumno
 *
 * \param s eAlumno*
 * \param st int estado a setear
 * \return void
 */ void emp_setEstado(eAlumno* this,int st);

 int emp_setHoras(eAlumno* this, int horas);
 int emp_setSueldo(eAlumno* this, float sueldo);


// FUNCIONES GET

/** \brief devuelve el nombre del alumno
 *
 * \param s eAlumno* estructura empleado
 * \return char* nombre
 */ char* emp_getNombre (eAlumno* this);

 /** \brief devuelve sexo del alumno
 *
 * \param s eAlumno* estructura alumno
 * \return char* profesion
 */ char* emp_getSexo (eAlumno* this);

/** \brief devuelve el salario del alumno
 *
 * \param s eAlumno* estructura alumno
 * \return int salario
 */ int emp_getSalario(eAlumno* this);

/** \brief devuelve el estado del alumno
 *
 * \param s eAlumno* estructura alumno
 * \return int estado
 */ int emp_getEstado(eAlumno* this);

/** \brief devuelve el id del alumno
 *
 * \param s eAlumno* estructura alumno
 * \return int id
 */ int emp_getId(eAlumno* this);

/** \brief devuelve la edad del alumno
 *
 * \param s eAlumno*
 * \return int edad
 */ int emp_getEdad(eAlumno* this);
  int emp_getLegajo(eAlumno* this);

  int emp_getHoras(eAlumno* this);
  float emp_getSueldo(eAlumno* this);

// FUNCION DE FILTRADO
/** \brief evalua alumno en base a un criterio (mayor de 30)
 *
 * \param alumno void*
 * \return int [1] si pasa el filtro, [0] si no
 */ int funcionFiltrar(void* alumno);

 int calculoSueldo(void* alumno);


// FUNCIONES DE MUESTREO

/** \brief muestra una estructura de alumno
 *
 * \param eAlumno* e estructura a mostrar
 * \return void
 */ void emp_mostrarUno (eAlumno* e);

/** \brief muestra una lista
 *
 * \param lista ArrayList*
 * \return void
 */ void main_mostrarLista(ArrayList* lista);

 void main_mostrarListaConSueldo(ArrayList* lista);

  /** \brief muestra una estructura de alumno ordenada por edad (>30)
 *
 * \param eAlumno* e estructura a mostrar
 * \return void
 */ int funcion_ordenarEdad(void*, void*);

// FUNCIONES DE VALIDACION DE STRINGS

/** \brief verifica si un dato ingresado está vacío o no
 * \param char value es el valor a analizar
 * \return [1] si cumple, [0] si no
 */ int string_isNull (char value);

/**
 * \brief Verifica si el valor recibido es numérico
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */ int string_esNumerico(char array[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */ int string_esSoloLetras(char array[]);

 /**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */ int string_esAlfanumerico(char array[]);

 /**
 * \brief Verifica si el valor recibido contiene solo letras, números, espacios, y los sig. simbolos: . , : - " & |.
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */ int string_esDescriptivo(char array[]);

/** \brief pide un string numerico, lo valida como tal, muestra error o lo transforma a entero y verifica que este entre x rango
 *
 * \param mensaje el item a validar "Ingrese *mensaje*:"
 * \param min, max rango
 * \return int numero validado
 */ int validarDatoMaxMin(int dato, char mensaje[], int min, int max);

 // FUNCIONES GET
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */ void string_get(char mensaje[],char input[]);

 /**
 * \brief Solicita un texto numerico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return [1] si cumple, [0] si no
 */ int string_getNumerico(char mensaje[],char input[]);

 /**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return [1] si cumple, [0] si no
 */ int string_getLetras(char mensaje[],char input[]);

 /**
 * \brief Solicita un texto alfanumérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return [1] si cumple, [0] si no
 */ int string_getAlfaNumerico(char mensaje[],char input[]);

/**
 * \brief Verifica si la cadena ingresada es numerica y de no serlo muestra mensaje de error
 * \param str Array con la cadena a ser analizada
 * \return int valor cambiado a entero
 */ int entero_get(char mensaje[]);

/** \brief valida un entero dentro de un rango
 *
 * \param int dato a evaluar
 * \param mensaje[] char visual de que es lo que se ingreso
 * \param min int, max int
 * \return int [1] si esta dentro del rango, [0] si no
 */ int entero_validaRango(int dato, char mensaje[], int min, int max);

// FUNCIONES GENERICAS

/** \brief muestra un menu principal generico
 * \param void
 * \return int opcion ingresada
 */ int generic_menu (void);

/** \brief agrega un "\n", pausa la aplicacion,
 * y limpia la pantalla al finalizar un case en el main
 * \param void
 * \return void
 */ void finFuncion (void);

 /** \brief pide respuesta por si o por no
 * \param void
 * \return int [1] por si, [0] por no.
 */ int generic_confirmar(void);

/** \brief pide los datos para dar de alta un nuevo empleado
 *
 * \param socio ArrayList* lista de empleados
 * \param id int* puntero a id auto-incremental
 * \return void
 */ void generic_alta(ArrayList* lista, int* id);

 /** \brief ingresa datos desde un archivo hacia un array de estructuras
 * \param l ArrayList*
 * \return int ultimo id de empleado para poder igresar uno nuevo en caso de que sea necesario
 */ int parseCargaDeDatos(ArrayList* lista,char filename[]);

 /** \brief egresa datos desde un array de estructura hacia un archivo .csv
 * \param l ArrayList*
 * \return void
 */ void parseGuardarDatos(ArrayList* lista,char filename[]);

/** \brief egresa datos desde un array de estructura hacia un archivo .csv
* \param l ArrayList*
* \return void
*/ void parseGuardarDatosSueldos(ArrayList* lista,char filename[]);


 /** \brief ingresa datos desde un archivo .dat hacia un array de estructuras
 * \param l ArrayList*
 * \return int ultimo id de empleado para poder igresar uno nuevo en caso de que sea necesario
 */ int ParseCargadeDatosBin(char nombrearchivo[], ArrayList* this);

/** \brief egresa datos desde un array de estructura hacia un archivo .dat
* \param l ArrayList*
* \return void
*/ int parseGuardarDatosBin(ArrayList* this,char nombrearchivo[]);

#endif // FUNCIONES_H_INCLUDED

