
#include<stdio.h>

int main()
{
    int i,counter=0;
    for(i=1; i<=100; i++)
    {
        if(i%2==0 || i%3 ==0 || i%5==0 || i%7==0)
            counter++;
    }

    printf("%d",counter);
}
