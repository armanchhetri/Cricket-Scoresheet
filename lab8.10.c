//program to print the given pattern
#include <stdio.h>
#include <string.h>

int main ()
{
    char s[]="UNIVERSITY";
    int i, j, c=0;
    for(i=1; i >= 0;  ){
        for(j=0; j<=i; j++)
            printf("%c", s[j]);
        printf("\n");
        c++;
        if(c>=5)
            i -=2;
        else
            i+=2;
    }
    return 0;
}
