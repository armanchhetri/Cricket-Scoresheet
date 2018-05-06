#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr;
    char ch;

    fptr = fopen("file.txt","w");
    if(fptr == NULL)
    {
        printf("file cannot be opened");
        exit(1);
    }

    while((ch=getc(stdin)) != '\n')
    {
        fputc(ch,fptr);
    }
    fclose(fptr);
    return 0;
}
