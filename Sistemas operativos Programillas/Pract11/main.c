#include <stdio.h>
#include <stdlib.h>


void printArray(char *array, int size) {
    printf("El resultado es: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%c", array[i]);
    }
}

int main() {
    int tamano;
    printf("Introduce size:\n");
    scanf("%d", &tamano);


    char *array = malloc(tamano * sizeof(*array));
    if (!array) {
        printf("Malloc fail");
        exit(EXIT_FAILURE);
    }

    printf("Introduce letras:\n");
    for (int i = 0; i < tamano; i++)
        scanf("%s", &array[i]);

    printArray(array, tamano);


    free(array);
}
