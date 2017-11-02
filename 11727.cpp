#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int arr[3];
    int t;
    int minimum,maximum;

    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
        minimum=0;
        maximum=0;

        for(int j=1; j<3; j++)
        {
            if(arr[j]<arr[minimum]) minimum=j;
            if(arr[j]>arr[maximum]) maximum=j;
        }

        for(int j=0; j<3; j++)
        {
            if(j!=minimum && j!=maximum)
            {
                printf("Case %d: %d\n",i+1,arr[j]);
                break;
            }

        }

    }
}
