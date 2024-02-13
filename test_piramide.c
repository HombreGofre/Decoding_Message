#include <stdio.h>

int main()
{
  int k, i, j;
  char opcion;
 
  printf("Introduce el número de filas que tendrá la pirámide: ");
  scanf("%i",&k);
  getchar();
 
  printf("\n");
  for(i=1;i<=k;i++)
  {
    for(j=1;j<=i;j++)
    {
      printf("%i ",j);
    }
    printf("\n");
  }
}
