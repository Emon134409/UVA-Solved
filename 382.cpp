
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    int n;
    int arr[105];
    int counter=0;
    while(scanf("%d",&n))
    {
        if(n==0) break;
        arr[counter++]=n;

    }

    printf("PERFECTION OUTPUT\n");
    int sum;
    for(int i=0; i<counter; i++)
    {
        sum=0;
        int sqr=(int)sqrt(arr[i]);
        for(int j=2; j<=sqr; j++)
        {
            if(arr[i]%j==0)
            {
                if(j<=sqr)
                {
                    sum=sum+j;
                    if(j!=1)
                        sum=sum+arr[i]/j;
                }
            }

        }

        if(arr[i]!=1) sum++;
        if(sum==arr[i]) printf("%5d  PERFECT\n",arr[i]);
        else if(sum<arr[i]) printf("%5d  DEFICIENT\n",arr[i]);
        else printf("%5d  ABUNDANT\n",arr[i]);
    }

    printf("END OF OUTPUT\n");
    return 0;
}
