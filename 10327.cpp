
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int arr[1005];
    int n;
    int counter;
    while(scanf("%d",&n)!=EOF)
    {
        counter=0;
        for(int i=0; i<n; i++)
            scanf("%d",&arr[i]);

        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(arr[i]>arr[j]) counter++;
            }

        }
        printf("Minimum exchange operations : %d\n",counter);
    }
}
