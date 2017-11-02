
#include<bits/stdc++.h>
using namespace std;

int tower1[105],tower2[105];
int c[105][105],b[105][105];

int lcslenght(int m,int n)
{
    for(int i=1; i<=m ; i++) c[i][0]=0;
    for(int j=0; j<=n; j++) c[0][j]=0;

    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            if( tower1[i-1]==tower2[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;

                b[i][j]=1;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }

            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }
        }

    return c[m][n];

}


int main()
{
    freopen("10066.txt","r",stdin);

    int n,m;
    int testcase=0;

    bool flag=false;
    while(scanf("%d %d",&n,&m) && (n!=0 && m!=0))
    {
        for(int i=0; i<n; i++)
            scanf("%d",&tower1[i]);

        for(int i=0; i<m; i++)
            scanf("%d",&tower2[i]);

//        for(int i=0; i<m; i++)
//            printf("%d\n",tower2[i]);

        if(flag)
        {
            printf("\n");

        }
        flag=true;
        printf("Twin Towers #%d\n",++testcase);
        printf("Number of Tiles : %d\n",lcslenght(n,m));

    }

    return 0;
}
