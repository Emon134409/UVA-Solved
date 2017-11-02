
#include<bits/stdc++.h>

using namespace std;

int arr[30];
int t[30];
int result[30];

int ceilIndex(int input[], int T[], int ender, int s)
{
    int start = 0;
    int middle;
    int len = ender;
    while(start <= ender)
    {
        middle = (start + ender)/2;

        if(middle < len && input[T[middle]] < s && s <= input[T[middle+1]])
        {
            return middle+1;
        }
        else if(input[T[middle]] < s)
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
        //cout<<arr[i]<<" "<<arr[t[len]]<<endl;
        if(arr[i]>arr[t[len]])
        {
            t[len+1]=i;
            result[i]=t[len];
            len++;
        }

        else if(arr[i]<arr[t[0]])
        {
            t[0]=i;

        }

        else
        {
            int index=ceilIndex(arr,t,len,arr[i]);
            t[index]=i;
            result[i]=t[index-1];
        }

    }

    return len+1;
}

int printlcs(int l)
{
    int index=t[l-1];

    while(1)
    {
        printf("%d",arr[index]);
        if(result[index]==-1) break;
        index=result[index];
    }
}

int main()
{

    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    memset(result,-1,sizeof(result));
    int l= lis(n);
    printf("%d\n",l);
    printlcs(l);
    return 0;
}
