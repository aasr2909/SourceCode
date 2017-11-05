/*Bimax Angélica Alejandra Serrano Rubio*/

/*Declaración de bibliotecas*/
#include <stdio.h>
#include "options.h"
#include "files.h"
#include "memory.h"
#include "bimax.h"

/*Funcion principal*/
int main(int argc, char *argv[])
{
    /*Contiene el nombre del archivo*/
    char fileName[80];
    /*Contiene el archivo de salida*/
    char Output[80];
    strcpy(Output,"Biclusters.txt");
    /*Número mínimo de filas*/
    int minRows=1;
    /*Número mínimo de columnas*/
    int minCols=1;

    /*Obtiene los parametros de la consola*/
    ReadParameters(argc, argv, fileName, Output, &minRows, &minCols);

    /*Valida que el número mínimo de filas y columnas sea mayor igual a 0*/
    //ValidEntries(&minRows, &minCols);

    /*Lectura del archivo de la matriz de expresión génica*/
    int **matrix;
    int noRows=0;
    int noCols=0;
    matrix=readMatrixTxt(fileName, &noRows, &noCols);

    /*Se revisan las dimensiones de la matriz*/
    if(noRows>0 && noCols>0)
        /*Algoritmo BIMAX*/
        Bimax(matrix, noCols, noRows, minCols, minRows, Output);
    else
        printf("\nError - La dimensiones de la matríz deben ser mayores a 0\n");

    /*Libera la memoria de la matriz*/
    freeMatrixBloques(matrix, noRows);

    return 0;
}
