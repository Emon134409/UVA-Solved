
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    int n,l,u,counter,sqr;
    bool flag;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&l,&u);

        flag=0;
        int maximum,num;
        for(int j=l; j<=u; j++)
        {
            counter=0;
            sqr=(int)ceil(sqrt(j));
            for(int k=1; k<=sqr; k++)
            {
                if(j%k==0)
                {
                    if(k<sqr)
                        counter+=2;
                    else if(sqr*sqr==j) counter++;
                }
            }
            if(flag==0)
            {
                maximum=counter;
                num=j;
                flag=1;
            }
            else
            {
                if(counter>maximum)
                {
                    maximum=counter;
                    num=j;
                }
            }


        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,u,num,maximum);
    }
    return 0;
}
