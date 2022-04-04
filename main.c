#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "header.h"
#define MAXCHAR 1000



void showContents(FILE *myFile);
void showContentsAsStruct(FILE *pFile);
void printValues(Libro nuevos_libros[]);

FILE * openingFile(char *filename){
    FILE *fp;
    FILE *fp1;
    fp = fopen(filename,"r");
    fp1 = fopen(filename,"r");

    return fp;
}



int main(int argc, char *argv[] ){
    char* archivo_csv;
    archivo_csv = argv[1];
    FILE *fp = openingFile(argv[1]);
    FILE *fp1 = openingFile(argv[1]);

//DEBUG CODE
    //showContents(fp);
    Libro *libros;

    libros = getLibros(fp);
    //showContentsAsStruct(fp1);
    menu(libros, registryCount, archivo_csv);
    printValues(libros);
    return 0;

}
void showContentsAsStruct(FILE *pFile) {
    Libro *libros;
    //paso el contenido del file a un array de personas
    libros = getLibros(pFile);

    //accedo a la cantidad de registro que lei
    for (int i = 0; i < registryCount; ++i) {
        //puedo solo imprimir su mail por ejemplo
        printf("%s\n", libros[i].autor);
    }

}
void showContents(FILE *myFile) {
    char row[MAXCHAR];
    char *token;
    //muestra el contenido del archivo
    fgets(row, MAXCHAR, myFile);
    while (!feof(myFile)){
        //obtiene la linea siguiente
        fgets(row, MAXCHAR, myFile);
        token = strtok(row, ",");
        //print id first
        printf("Row: %s \n", token);
        for (int i = 0; i < 8; ++i) {
            printf("Token %d: %s\n", i, token);
            token = strtok(NULL, ",");
        }

    }
}
void printValues(Libro libro[]){
    printf("\n");
    //printf("%d\n",tope );

    for(int i=0; i<registryCount; i++)
    {
        /* code */
        printf("titulo: %s, autor: %s, anio: %s, estante_numero: %s, estante_seccion: %s, piso: %s, edificio: %s, sede: %s\n",libro[i].titulo,libro[i].autor, libro[i].anio, libro[i].estante_numero,libro[i].estante_seccion, libro[i].piso, libro[i].edificio, libro[i].sede);
        printf("\n");
    }
}