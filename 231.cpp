
#include<bits/stdc++.h>

using namespace std;

int arr[99999999];
int t[99999999];


int ceilIndex(int input[], int T[], int ender, int s)
{
    int start = 0;
    int middle;
    int len = ender;
    while(start <= ender)
    {
        middle = (start + ender)/2;

        if(middle < len && input[T[middle]] > s && s >= input[T[middle+1]])
        {
            return middle+1;
        }
        else if(input[T[middle]] > s)
        {
            start = middle+1;
        }
        else
        {
            ender = middle-1;
        }
    }

}

int lis(int n)
{
    t[0]=0;
    int len=0;

    for(int i=1; i<n; i++)
    {

        if(arr[i]<=arr[t[len]])
        {
            t[len+1]=i;
            len++;
        }

        else if(arr[i]>arr[t[0]])
        {
            t[0]=i;

        }

        else
        {
            int index=ceilIndex(arr,t,len,arr[i]);
            t[index]=i;
         }

    }

    return len+1;
}

int main()
{
    int prime,data,i,counter=0;
    bool flag=false;

    while(scanf("%d",&prime) && prime != -1)
    {
        arr[0]=prime;
        i=1;

        while(scanf("%d",&data) && data !=-1)
        {
            arr[i++]=data;
        }

        int l= lis(i);

        if(!flag)
        {
            flag=true;
        }
        else printf("\n");
        printf("Test #%d:\n",++counter);
        printf("  maximum possible interceptions: %d\n",l);


    }
    return 0;
}
