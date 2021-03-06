/*Bimax Angélica Alejandra Serrano Rubio*/

/*Declaración de bibliotecas*/
#include <stdio.h>
#include "options.h"
#include "files.h"
#include "memory.h"
#include "bimax.h"
#include "tiempo.h"

/*Funcion principal*/
int main(int argc, char *argv[])
{
    /*Variables para medir el tiempo*/
    struct timeval inicio2, fin2;
    double tiempo;

    // Medir tiempo usando gettimeofday() de la libreria sys/time.h
    printf("Inicio de contador de tiempo\n\n");
    gettimeofday(&inicio2, NULL);

    /*Contiene el nombre del archivo*/
    char fileName[80];
    /*Contiene el archivo de salida*/
    char Output[80];
    strcpy(Output,"Biclusters.txt");
    /*Número mínimo de filas*/
    int minRows=1;
    /*Número mínimo de columnas*/
    int minCols=1;
    /*Opción de impresión*/
    int type=2;

    /*Obtiene los parametros de la consola*/
    ReadParameters(argc, argv, fileName, Output, &minRows, &minCols, &type);

    /*Valida que el número mínimo de filas y columnas sea mayor igual a 0*/
    //ValidEntries(&minRows, &minCols);

    /*Lectura del archivo de la matriz de expresión génica*/
    int **matrix;
    int noRows=0;
    int noCols=0;
    matrix=readMatrixTxt(fileName, &noRows, &noCols);

    /*Se revisan las dimensiones de la matriz*/
    if(noRows>0 && noCols>0)
    {
        /*Algoritmo BIMAX*/
        Bimax(matrix, noCols, noRows, minCols, minRows, Output, type);
    }
    else
        printf("\nError - La dimensiones de la matríz deben ser mayores a 0\n");

    /*Libera la memoria de la matriz*/
    freeMatrixBloques(matrix, noRows);

    gettimeofday(&fin2, NULL);
    // Calcular tiempo en milisegundos
    tiempo = diferencia_milisegundos(&inicio2, &fin2);
    printf("\nTiempo de ejecucion : %f milisegundos\n", tiempo);

    return 0;
}
