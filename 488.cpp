
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{

    int t,a,f,counter,out;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d %d",&a,&f);

        for(int j=0; j<f; j++)
        {
            counter=1;
            out=1;
            for(int x=1; x<=a+(a-1); x++)
            {

                for(int k=1; k<=counter; k++)
                {
                    printf("%d",out);

                }
                if(x<a) counter++;
                else counter--;

                if(x<a) out++;
                else out--;
                printf("\n");

            }
            if(i<t-1)
                printf("\n");
            else
                {
                    if(j<f-1)
                        printf("\n");
                }
        }
    }

    return 0;
}
