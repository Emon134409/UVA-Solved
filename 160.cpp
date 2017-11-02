
#include<bits/stdc++.h>

using namespace std;

#define size 100

struct prime
{
    int number;
    int counter;
    bool flag;

} primes[size+5];


int h;
void init(int t)
{
    h=-1;
    for(int i=0; i<t; i++)
    {
        // primes[i].flag=1;
        primes[i].counter=0;
        // primes[i].ender=0;
    }

}

int seive()
{
    int i,j,total=0,val;

    for(i=2; i<=size; i++)
    {
        primes[i].flag=1;
        // primes[i].counter=0;
    }

    val=sqrt(size)+1;

    for(i=2; i<val; i++)
        if(primes[i].flag)
            for(j=i; j*i<=size; j++)
                primes[i*j].flag=0;

    for(i=2; i<=size; i++)
        if(primes[i].flag)
            primes[total++].number=i;

    return total;
}


void divisor(int N,int total)
{
    int i,val,counter,sum,temp;
    val=sqrt(N)+1;
    sum=1;

    bool slah=false;

    for(i=0; primes[i].number<=val; i++)
    {

        if(N%primes[i].number==0)
        {
            counter=0;

            while(N%primes[i].number==0)
            {
                slah=true;
                N/=primes[i].number;
                counter++;
            }
            //cout<<counter<<endl;

            primes[i].counter=primes[i].counter+counter;

            if(i>h) h=i;
            if(N>1 && slah)
            {
                temp=N;
            }

        }
//        else
//              primes[i].counter=1;
    }

    if(N>1 && slah)
    {
        for( i=0; i<total; i++)
            if(primes[i].number==temp)
            {
                if(i>h)
                    h=i;
                primes[i].counter=primes[i].counter+1;
                break;

            }
    }


}


int main()
{
    int n;

    int t= seive();

    int mult;

    while(scanf("%d",&n) && n!=0)
    {
        //mult=1;
        init(t);
        for(int i=n; i>1; i--)
        {
            if(i%2==1)
            {
                for(int j=0; j<t; j++)
                    if(primes[j].number==i)
                    {
                        if(j>h) h=j;

                        primes[j].counter=primes[j].counter+1;
                        break;

                    }

            }

            else divisor(i,t);


        }
        printf("%3d! =",n);
        for(int i=0; i<=h; i++)
        {
            printf(" %d",primes[i].counter);
        }

        printf("\n");


    }

    return 0;

}





