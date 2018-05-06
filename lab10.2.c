#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char ch;

    int noc=0;
    fptr = fopen("file.txt","r");
    if(fptr == NULL)
    {
        printf("cannot open file");
        exit(1);
    }

    while(1)
    {
       ch=fgetc(fptr);
       if(ch == EOF)
            break;
       noc++;
       printf("%c",ch);
    }
    printf("\n");
    printf("Number of characters= %d\n",noc);
    fclose(fptr);
    return 0;
}
