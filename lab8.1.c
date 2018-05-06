//program to find the biggest number among three using pointers
#include <stdio.h>

int main()
{
    int *p, largest, i;
    printf("Enter the values for a, b and c\n");

    for(i=0; i < 3; i++)
        scanf("%d",p+i);

    largest = *p;
    for(i=0; i< 3; i++ )
    {
        if(*(p+i)>largest)
        largest = *(p+i);
    }
    printf("The largest number is %d\n", largest);

    return 0;
}

