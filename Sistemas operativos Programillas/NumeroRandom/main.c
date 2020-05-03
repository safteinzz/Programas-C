#include <assert.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Retorna un número entero aleatorio entyre los límites MIN y MAX, inclusive. */
/* La aleatoriedad se obtiene del fichero /dev/random */
int random_number (int min, int max)
{
	/* Almacenamos el dscriptor de fichero obtenido al abrir /dev/random en una vari8able estática */
	/* de esta forma no es necesario abrir el fichero cada vez que llamemos a la función */
	static int dev_random_fd = -1;
	char* next_random_byte;
	int bytes_to_read;
	unsigned random_value;

	/* Nos aseguramos que MAX sea mayor que MIN. */
	assert (max > min);

	/* Si es la primera vez que llamamos a la función, abrimos el fichero /dev/random */
	if (dev_random_fd == -1) {
		dev_random_fd = open ("/dev/random", O_RDONLY);
		assert (dev_random_fd != -1);
	}

	/* Leemos el suficiente número de bytes para disponer de una variable entera */
	next_random_byte = (char*) &random_value;
	bytes_to_read = sizeof (random_value);
	/* Bucle para leer un número significativo de bytes de forma que aseguremos aleatoriedad. */
	do {
		int bytes_read;
		bytes_read = read (dev_random_fd, next_random_byte, bytes_to_read);
		bytes_to_read -= bytes_read;
		next_random_byte += bytes_read;
	} while (bytes_to_read > 0);
	/* Calculamos un número aleatorio en el rango adecuado */
	return min + (random_value % (max - min + 1));
}

int main()
{
    int numMin;
    int numMax;
    int numReturn;
    printf("Introduce el numero minimo: ");
    scanf("%d", &numMin);
    printf("Introduce el numero maximo: ");
    scanf("%d", &numMax);
    numReturn = random_number(&numMin, &numMax);
    printf("\nEl numero resultante es: %d", numReturn);

    return 0;
}
