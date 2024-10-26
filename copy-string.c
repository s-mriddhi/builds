#include <stdio.h>
int main()
{
    char str1[20];
    scanf("%s",str1);
   
    char str2[20];
    for(int j=0; str1[j]!='\0';j++)
    {
      str2[j] = str1[j];
    }
     printf("The copied string is %s.",str2);
}