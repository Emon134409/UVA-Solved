
#include<bits/stdc++.h>
using namespace std;

struct data
{
    int number;
    int pr;
};

data arr[25];
int res[25];
int t[25];

int compare(const void *a,const void *b)
{
    data *c=(data *)a;
    data *d=(data *)b;

    return c->number - d->number;
}


int ceilIndex(data input[], int T[], int ender, int s)
{
    int start = 0;
    int middle;
    int len = ender;
    while(start <= ender)
    {

        middle = (start + ender)/2;
        if(middle < len && input[res[T[middle]]-1].pr < s && s <= input[res[T[middle+1]]-1].pr)
        {

            return middle+1;
        }
        else if(input[res[T[middle]]-1].pr < s)
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
        if(arr[res[i]-1].pr>arr[res[t[len]]-1].pr)
        {
            t[len+1]=i;
            len++;
        }
        else if(arr[res[i]-1].pr<arr[res[t[0]]-1].pr)
        {
            t[0]=i;
        }
        else
        {
            int index=ceilIndex(arr,t,len,arr[res[i]-1].pr);
            t[index]=i;

            //printf("%d %d\n",index,t[index]);

        }

    }

    return len+1;
}


int main()
{
    freopen("111.txt","r",stdin);

    int n;
    int counter=0;

    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i].number);

        arr[i].pr= ++counter;
    }

    qsort(arr,n,sizeof(data),compare);

//    for(int i=0;i<n;i++)
//    {
//        printf("%d ",arr[i].number);
//    }
//
//    printf("\n");
//
//    for(int i=0;i<n;i++)
//    {
//        printf("%d ",arr[i].pr);
//    }
//     printf("\n");


    while(scanf("%d",&res[0])!=EOF)
    {
        for(int i=1; i<n; i++)
            scanf("%d",&res[i]);

        printf("%d\n",lis(n));
    }

    return 0;
}
