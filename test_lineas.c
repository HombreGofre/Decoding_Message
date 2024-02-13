#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int comparar_enteros(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	pyramid_heigth(int	num)
{ 
	//Formula to calculate the height of the pyramid given the quantity of numbers it has
	return (int)((sqrt(8 * (double)num + 1) - 1) / 2);
}

void	in_pyramid(int	*num, int	size)
{
	int	altura;
	int	i;
	int j;
	int k;
	int n;

	i = 1;
	j = 1;
	k = 1;
	n = 0;
	altura = pyramid_heigth(size);
	while (i <= altura)
	{
		while (j <= altura - i)
		{
			printf(" ");
			j++;
		}
		while (k <= i)
		{
			printf("%d ", num[n]);
			n++;
			k++;
		}
		i++;
		printf("\n");
		j = 1;
		k = 1;
	}
}

int main()
{
	FILE *archivo = fopen("coding_qual_input.txt", "r"); // Modo lectura
    char bufer[1000];	// Aquí vamos a ir almacenando cada línea
	int	num[1000];
	int	i;
	int	j;
	int	size;

	j = 0;
	size = 0;
    while (fgets(bufer, 1000, archivo))
    {
        // Aquí, justo ahora, tenemos ya la línea. Le vamos a remover el salto
		strtok(bufer, " ");
		i = atoi(bufer);
        //strtok(bufer, "\n");
		num[j] = i;
        // La imprimimos, pero realmente podríamos hacer cualquier otra cosa
        //printf("La línea es: '%s'\n", bufer);
		j++;
		size++;
    }
	printf("\n*****************************************************\n");
	qsort(num, j, sizeof(int), comparar_enteros);
	j = 0;
	/*while(num[j] != '\0')
	{
		printf("%d ", num[j]);
		j++;
	}*/
	in_pyramid(num, size);
	//system("leaks a.out");
    return 0;
}
