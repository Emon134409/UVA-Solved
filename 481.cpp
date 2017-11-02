

#include<bits/stdc++.h>

using namespace std;

int arr[999999];
int t[999999];
int result[999999];

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

bool flag=false;

void printlcs(int index)
{
    if (flag) return;
    if(result[index]==-1)
    {
        flag=true;
    }
    printlcs(result[index]);
    printf("%d\n",arr[index]);

}

int main()
{
    memset(result,-1,sizeof(result));
    int data,i=0;

    while(scanf("%d",&data)!=EOF)
    {
        arr[i++]=data;
    }

    int l= lis(i);
    printf("%d\n",l);
    printf("-\n");
    printlcs(t[l-1]);
    return 0;
}
