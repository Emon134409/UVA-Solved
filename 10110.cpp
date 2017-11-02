#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;


int main()
{
    unsigned int n;
    int counter;
    while(scanf("%u",&n) && n!=0 )
    {
        counter=0;
        int sqr=(int)ceil(sqrt(n));
        for(int i=1; i<=sqr; i++)
        {
            if(n%i==0)
            {
                if(i<sqr)
                    counter+=2;
                else if(sqr*sqr==n) counter++;
            }

        }

        if(counter%2==0) printf("no\n");
        else printf("yes\n");
    }

    return 0;

}
