
#include<bits/stdc++.h>
using namespace std;

int m[15][15];
int s[15][15];

void chain_order(int p[],int n)
{

    for(int l=2; l<=n; l++)
    {
        for(int i=1; i<=n-l+1; i++)
        {
            int j=i+l-1;

            m[i][j]=INT_MAX;

            for(int k=i; k<=j-1; k++)
            {
                int q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);

                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }

            }
        }

    }

}

void print_MCM(int i,int j)
{
    if(i==j) printf("A%d",i);
    else
    {
        printf("(");
        print_MCM(i,s[i][j]);
        printf(" * ");
         print_MCM(s[i][j]+1,j);
         printf(")");
    }


}

int main()
{
    freopen("348.txt","r",stdin);

    int p[15];
    int n,i;
    int l,k;

        for(int i=0; i<=14; i++)
        m[i][i]=0;


    while(scanf("%d",&n) && n!=0)
    {
        int j=0;

        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&l,&k);
            if(j<1)
            {
                p[j]=l;
                j++;
            }
            p[j]=k;

            j++;
        }

        chain_order(p,n);

       // printf("%d\n",s[1][n]);
        print_MCM(1,n);
        printf("\n");
    }



    return 0;
}
