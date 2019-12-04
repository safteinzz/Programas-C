#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

void escribir(char* nombreFichero){
    fflush(stdin);
    char* linea;
    FILE *file = fopen(nombreFichero, "w+");
    int loop = 1;
    while (loop == 1)
    {
        system("cls");
        linea = inputString(stdin, 10);
        if(linea != NULL && linea[0] == '\0')
            loop = 0;
        else
            strcat(linea,"\n");
            fputs(linea, file);
    }
    fclose(file);
}

int main(/*int argc, char *argv[]*/){
    char deseaSobrescribir;

    char *nombreFichero;
    //nombreFichero = argv[0];
    printf("Introduce el nombre del fichero:\n");
    nombreFichero = inputString(stdin, 10);

    if( access( nombreFichero, F_OK ) != -1 ) { //EXISTE
        do{
            system("cls");
            printf("El fichero existe, desea sobrescribirlo (s/S - n/N)?\n");
            scanf("%c", &deseaSobrescribir);
            if(deseaSobrescribir == 's' || deseaSobrescribir == 'S'){
                escribir(nombreFichero);
                //break;
            }
            else if(deseaSobrescribir == 'n' || deseaSobrescribir == 'N'){
                exit(0);
            }
        } while (deseaSobrescribir != 's' && deseaSobrescribir != 'S');
    } else{ //NO EXISTE
        escribir(nombreFichero);
    }
    free(nombreFichero);
    return 0;
}
