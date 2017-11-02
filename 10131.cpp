
#include<bits/stdc++.h>

using namespace std;

struct data
{
    int age;
    int iq;
};

data arr[1005];
int length[1005];
int pred[1005];

int index;

int lis(int len)
{
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<i;j++)
        {
                if(arr[i].age>arr[j].age && arr[i].iq<arr[j].iq)
                {
                        if(length[j]+1>length[i])
                        {
                              length[i]=length[j]+1;
                              pred[i]=j;
                        }
                }
        }
    }

    int maxx=length[0];

    for(int i=1;i<len;i++)
    {
         if(length[i]>maxx){
                maxx=length[i];
                index=i;
         }
    }

    return maxx+1;

}

bool flag=false;

void printlcs(int index)
{
    if (flag) return;
    if(pred[index]==-1)
    {
        flag=true;
    }
    printlcs(pred[index]);
    printf("%d\n",index+1);

}

int main()
{
    freopen("10131.txt","r",stdin);

    int len=0;
    int x,y;

    memset(length,0,sizeof(length));
    memset(pred,-1,sizeof(length));

    while(scanf("%d %d",&x,&y)!=EOF)
    {
        arr[len].iq=y;
        arr[len].age=x;
        len++;
    }

    printf("%d\n",lis(len));
    printlcs(index);
    return 0;
}
