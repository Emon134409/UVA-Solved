#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int gcd(int a,int b)
{
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

 int C(int n,int m)
{
    int M[10000],N[10000];
    int maximum=max(m,n-m);
    int minimum=min(m,n-m);
    int i,j;
    int counter1=0,counter2=0;

    for( i=n; i>maximum; i--)
    {
        M[counter1]=i;
        counter1++;
    }

    for( j=minimum; j>=1; j--)
    {
        N[counter2]=j;
        counter2++;
    }

    for(i=0; i<counter1; i++)
    {
        for( j=0; j<counter2; j++)
        {
            int g=gcd(M[i],N[j]);
            if((M[i] % N[j]==0) )
            {
                if(N[j]!=-1)
                {
                    M[i]=M[i]/N[j];
                    N[j]=-1;
                    break;
                }
            }
            else if(g!=1)
            {
                M[i]/=g;
                N[j]/=g;
            }
        }
    }

    for(i=0; i<counter1; i++)
    {
        for( j=0; j<counter2; j++)
        {
            int g=gcd(M[i],N[j]);
            if((M[i] % N[j]==0) )
            {
                if(N[j]!=-1)
                {
                    M[i]=M[i]/N[j];
                    N[j]=-1;
                    break;
                }
            }
            else if(g!=1)
            {
                M[i]/=g;
                N[j]/=g;
            }
        }
    }


    for(i=0; i<counter1; i++)
    {
        for( j=0; j<counter2; j++)
        {
            int g=gcd(M[i],N[j]);
            if((M[i] % N[j]==0) )
            {
                if(N[j]!=-1)
                {
                    M[i]=M[i]/N[j];
                    N[j]=-1;
                    break;
                }
            }
            else if(g!=1)
            {
                M[i]/=g;
                N[j]/=g;
            }
        }
    }

    int a=1,b=1;

    for(i=0; i<counter1; i++)
    {
        a*=M[i];
        if(N[i]!=-1 && i<counter2)
        {
            b*=N[i];
        }
    }

    return a/b;


}

int main()
{

    int n,m;
    while(scanf("%d %d",&n,&m) && n!=0 && m!=0)
    {
        int ans=C(n,m);
        printf("%d\n",ans);
    }
    return 0;
}
