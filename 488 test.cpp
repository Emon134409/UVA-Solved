#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int m,counter,out;


    counter=1;
    out=1;
    for(int x=1; x<=m+(m-1); x++)
    {

        for(int k=1; k<=counter; k++)
        {
            printf("%d",out);

        }
        if(x<m) counter++;
        else counter--;

        if(x<m) out++;
        else out--;
        printf("\n");

    }
}
