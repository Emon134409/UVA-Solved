
#include<bits/stdc++.h>
using namespace std;

#define size 99940774

struct prime
{
    int number;
    int counter;

} v[75+5];

bool flag[size+5];
int prime[size+5];



void seive()
{

    int i,j,total=0,val;

    for(i=2; i<=size; i++)
        flag[i]=1;

    val=sqrt(size)+1;

    for(i=2; i<val; i++)
        if(flag[i])
            for(j=i; j*i<=size; j++)
                flag[i*j]=0;

    for(i=2; i<=size; i++)
        if(flag[i])
            prime[total++]=i;

}

int j;

int divisor(int N)
{
    int temp,i,val,counter,sum;
    j=0;
    val=sqrt(N)+1;
    sum=1;

    bool flah=false;
    bool slah=false;
     for(i=0; prime[i]<val; i++)
    {
        if(N%prime[i]==0)
        {
            counter=0;

            while(N%prime[i]==0)
            {
                N/=prime[i];
                 slah=true;
                counter++;
            }
            v[j].number=prime[i];
            v[j].counter=counter;
            flah=true;

               if(N>1 && slah)
            {
                temp=N;
            }

            j++;
        }

    }

    if(!flah)
    {
        v[j].number=N;
        v[j].counter=1;
        j++;
    }

   if(N>1 && slah)
    {
        v[j].number=temp;
        v[j].counter=1;
        j++;
    }

}

int main()
{
    seive();

    int n;

    while(scanf("%d",&n) && n!=0)
    {
        if(n<0) divisor(-1*n);
        else
            divisor(n);
        printf("%d = ",n);
        if(n>=0)
        {
            for(int k=0; k<j; k++)
                for(int i=0; i<v[k].counter; i++)
                {
                    if(k==0 && i==0)
                        printf("%d",v[k].number);
                    else printf(" x %d",v[k].number);
                }
        }
        else
        {
            printf("-1");
            for(int k=0; k<j; k++)
                for(int i=0; i<v[k].counter; i++)
                {

                    //  printf("%d",v[k].number);
                    printf(" x %d",v[k].number);
                }
        }

        printf("\n");

    }

    return 0;
}
