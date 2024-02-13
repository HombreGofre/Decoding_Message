#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Función de decodificación
char* decode(const char* message_file) {
    // Abre el archivo de mensajes
    FILE* file = fopen(message_file, "r");
    if (file == NULL) {
        return "File not found.";
	}
	fseek(file, 0, SEEK_END);
	long file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* encoded_message = (char*)malloc(file_size + 1);
	fread(encoded_message, 1, file_size, file);
	fclose(file);
	encoded_message[file_size] = '\0';

    // Lógica de decodificación
    int pyramid_numbers[3] = {1, 3, 6};  // Números de la pirámide
    int pyramid_size = 3;
    char* decoded_message = (char*)malloc(file_size + 1);
    decoded_message[0] = '\0';  // Inicializamos la cadena vacía

	char* token = strtok(encoded_message, " ");
    int pyramid_index = 0;

    while (token != NULL && pyramid_index < pyramid_size) {
        int current_number = atoi(token);

        if (current_number == pyramid_numbers[pyramid_index]) {
            strcat(decoded_message, token);
            strcat(decoded_message, " ");
            pyramid_index++;
        }

        token = strtok(NULL, " ");
    }

    // Eliminamos el espacio adicional al final del mensaje
    decoded_message[strlen(decoded_message) - 1] = '\0';

    // Liberamos la memoria utilizada por el mensaje codificado
    free(encoded_message);

    // Devolvemos el mensaje decodificado
    return decoded_message;
}

int main() {
    // Llama a la función decode con el nombre del archivo de mensajes
    const char* message_file = "encoded_message.txt";
    char* decoded_message = decode(message_file);

    // Imprime el mensaje decodificado
    printf("%s\n", decoded_message);

    // Libera la memoria utilizada por el mensaje decodificado
    free(decoded_message);

    return 0;
}
