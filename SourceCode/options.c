/*Bimax Angélica Alejandra Serrano Rubio*/

/*Declaración de bibliotecas*/
#include "options.h"

/*Funcion que imprime la ayuda del programa*/
void PrintHelp(int exval)
{
    printf("%s,%s show working \n", PACKAGE, VERSION);
    printf("%s [-h] [-V] [-G FILE] [-r NUMBER] [-c NUMBER] [-o FILE] [-w] \n\n", PACKAGE);

    printf("  -h              print this help and exit\n");
    printf("  -V              print version and exit\n\n");

    printf("  -G              set Gene Expression Matrix file\n");
    printf("  -r              set the minimum numbers of rows (default 1)\n");
    printf("  -c              set the minimum numbers of cols (default 1)\n");

    printf("  -o FILE         set output biclusters file (default Biclusters.txt)\n");

    printf("\n\n");
    exit(exval);
}

/*Funcion que lee los parámetros de entrada*/
int ReadParameters(int argc, char **argv, char *FileName, char *Output, int *minRows, int *minCols)
{
    /*Almacena la opcion*/
    int opt;

    printf("\n\n");

    /*Si no se reciben parametros*/
    if(argc == 1)
    {
        fprintf(stderr, "\n\nThis program need arguments...\n\n");
        PrintHelp(1);
    }

    /*Mientras se reciban parametros*/
    while((opt = getopt(argc, argv, "hVG:r:c:o:s:")) != -1)
    {
        switch(opt)
        {
        /*Muestra la ayuda del sistema*/
        case 'h':
            PrintHelp(0);
            break;
        case 'V':
            /*Imprime la version del sistema*/
            printf("\n%s %s\n\n", PACKAGE, VERSION);
            exit(0);
            break;
        case 'G':
            /*Nombre del archivo de matriz de expresión génica con el formato especifico*/
            printf("\nParameters:\n");
            printf("Gene Expression Matrix: filename %s\n",  optarg);
            strcpy(FileName, optarg);
            break;
        case 'r':
            /*Selecciona el mínimo numero de filas en un bicluster*/
            printf("Minimum number of rows: %s\n", optarg);
            *minRows=atoi(optarg);
            break;
        case 'c':
            /*Selecciona el mínimo numero de columnsas en un bicluster*/
            printf("Minimum number of cols: %s\n", optarg);
            *minCols=atoi(optarg);
            break;
        case 'o':
            /*Selelcciona el nombre del archivo de salida*/
            printf("Output: Filename output %s\n", optarg);
            strcpy(Output,optarg);
            break;
        case ':':
            fprintf(stderr, "%s: Error - Option `%c' needs a value\n\n", PACKAGE, optopt);
            PrintHelp(1);
            break;
        case '?':
            fprintf(stderr, "%s: Error - No such option: `%c'\n\n", PACKAGE, optopt);
            PrintHelp(1);
        }
    }

    /*Imprime todas las opciones*/
    for(; optind < argc; optind++)
        printf("argument: %s\n", argv[optind]);

    printf("\n\n");

    return 0;
}
