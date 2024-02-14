#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int	int_compare(const void *a, const void *b)
{
	/*
	 * This functión compares two intergers and check if they are equal, greater or less
	 * It is used as a variable in qsort functión to sort an array
	 */
	return (*(int *)a - *(int *)b);
}

void	*get_words(FILE	*file, char	*buffer, int	*num)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	j = 0;
	int p = 0;
	while (fgets(buffer, 1000, file)); // words 'gets(puntero destino, tamaño, archivo)'
	{
		strtok(buffer, " "); //get number without word
		i = atoi(buffer);	//get number with atoi function (ascii to interger)
		num[j] = i;
		printf("%d ", num[j]);
		j++;
	}
}

int main()
{
	FILE	*file;
	char	buffer[1000];
	int		num[1000];
	int		*aux;
	int		i;

	file = fopen("coding_qual_input.txt", "r");	//open file only in read_only mode
	get_words(file, buffer, num);
	//aux = num;
	qsort(num, i, sizeof(int), int_compare); //sort an array 
	printf("\n**************************************\n");
}
