#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char	*decode_file(const char *message_file)
{
	FILE	*file;
	int		size;
	int		**n;

	file = fopen(message_file, r);
	if (file == NULL)
		return 0;
	char buffer[1000];
	while (fgets(buffer, 1000, file))
	{
		strtok(buffer, " ");
		n = atoi(buffer);
		strtok(buffer, "\n");
	}

}

int main()
{
	const char	*message_file="encoded_message.txt";
	char		*decodded_message;

	decodded_message = decode_file(message_file);
	printf("%s\n", decodded_message);
	return 0;
}

/*
 *
 * Paso 1: Leer el contenido del archivo y almacenarlo en una lista.
 * Paso 2: Crear un diccionario para mapear los números a las palabras correspondientes.
 * Paso 3: Ordenar los números en orden ascendente y construir la pirámide de palabras.
 * Paso 4: Recuperar las palabras referentes a los números al final de cada línea de la pirámide.
 * Paso 5: Concatenar las palabras recuperadas para formar el mensaje decodificado.
 */
