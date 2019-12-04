#include <stdio.h>
#include <stdlib.h>


char *inputString(FILE* fp, size_t size){
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)* size);
    if(!str) return str;
    while(EOF != (ch = fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str) return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}


int main(/*int argc, char *argv[]*/)
{
    FILE *file;

    char registro[4];
    char nombre[20];
    char apellido1[25];
    char apellido2[25];


    char *nombreFichero;
    //nombreFichero = argv[0];
    printf("Introduce el nombre del fichero:\n");
    nombreFichero = inputString(stdin, 10);


    file = fopen(nombreFichero,"r");
    if(file == NULL) {
        perror("Fichero no existe");
        return(-1);
    }

    system("cls");
    while (feof(file) == 0)
    {
        fgets(registro,4,file);
        fgets(nombre,20,file);
        fgets(apellido1,25,file);
        fgets(apellido2,25,file);

        strtok(registro, "\n");
        strtok(nombre, "\n");
        strtok(apellido1, "\n");
        strtok(apellido2, "\n");

        //Registro: 10
        //Nombre: PEREZ CARMONA, JAVIER
        printf("Registro: %s\n", registro);
        printf("Nombre: %s %s, %s\n", apellido1,apellido2,nombre);
    }

    return 0;
}
