#include <stdio.h>
#include <math.h>

// IMPORTANT - When compiling a function from the 'math.h' library, it is necessary to add 
// the following formula: ' gcc example.c-lm ' . It is required to include '-lm' 
// as a compilation command to link the possible functions from the library with it.

int piramide_alt(int	num)
{
	 return (int)((sqrt(8 * (double)num + 1) - 1) / 2);
}

int main() {
    int altura;
    int numero = 1;
	int	cantidad = 300;

	altura = piramide_alt(cantidad);
    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= altura - i; j++) {
            printf("  ");  // Imprime espacios para alinear los números
        }

        for (int k = 1; k <= i; k++) {
            printf("%2d  ", numero);  // Imprime el número con dos dígitos y espacios
            numero++;
        }

        printf("\n");
    }

    return 0;
}
