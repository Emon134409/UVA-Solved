
#include<cstdio>
#include<cmath>

#define SIZE_N 65000
#define SIZE_P 65000

using namespace std;

bool flag[SIZE_N+5];
int primes[SIZE_P+5];


//
//int primeFactor(int N)
//{
//    int i,val,count,sum;
//    val=sqrt(N)+1;
//    sum=1;
//
//    count=0;
//
//    for(i=0; primes[i]<val; i++)
//    {
//        if(N%primes[i]==0)
//        {
//
//            while(N%primes[i]==0)
//            {
//                N/=primes[i];
//
//            }
//            count++;
//        }
//    }
//    if(N>1) count++;
//    return count;
//}


void seive(int N)
{
    int i,j,total=0,val;

    for(i=2; i<=SIZE_N; i++) flag[i]=1;

    val=sqrt(SIZE_N)+1;

    for(i=2; i<val; i++)
        if(flag[i])
            for(j=i; j*i<=SIZE_N; j++)
                flag[i*j]=0;
    for(i=2; i<=SIZE_N; i++)
        if(flag[i])
            primes[total++]=i;

}

int bigmod (int a, int b, int c) { // Calculate a ^ b mod c
    long long ans = 1, mult = a;
    while (b) {
        if (b & 1) {
            ans = (ans * mult) % c;
        }
        mult = (mult * mult) % c;
        b >>= 1;
    }
    return (int) ans;
}





int main()
{
    int x;
  //  FILE *fp=fopen("10006.txt","r");

    for(int x=2;x<=65000;x++)
    {
//        scanf("%d",&x);
//
//        if(x==0) break;

        seive(x);
         int flag1=0;
        if(flag[x]==0)
        {
            for(int a=2;a<=x-1;a++)
            {
                if(bigmod(a,x,x)!=a)
                {
                    flag1=1;

                    break;
                }
            }

            if(flag1==0)
            printf("The number %d is a Carmichael number.\n",x);
        }
//        else printf("%d is normal.\n",x);
//        if(flag1==1) printf("%d is normal.\n",x);

    }
}
