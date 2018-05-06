#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
    FILE *fptr;
    fptr=fopen("stting.txt","w+");
    char str[40];
    if(fptr==NULL)
    {
        printf("file cannot be opened");
        exit(1);
    }
    printf("enter the string:\n");
    while(strlen(gets(str))!=0)
    {
        fputs(str,fptr);
        fputs("\n",fptr);
    }
    rewind(fptr);
    printf("the contents are:\n");
    while(fgets(str,39,fptr)!=NULL)
    printf("%s",str);
    fclose(fptr);
    return 0;

}
