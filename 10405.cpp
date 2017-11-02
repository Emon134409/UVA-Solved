
#include<bits/stdc++.h>

using namespace std;

string str1;
string str2;

int c[105][105],b[105][105];

int l;

int lcs(int m,int n)
{
    for(int i=1;i<=m ;i++) c[i][0]=0;
    for(int j=0;j<=n;j++) c[0][j]=0;

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
    {
        if( str1[i-1]==str2[j-1])
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
    freopen("10405.txt","r",stdin);

    while(cin>>str1>>str2)
    {

         if(str1.compare("\n") || str2.compare("\n"))
         {
             printf("0\n");
         }
         else{
        int m=str1.size();
        int n=str2.size();
        printf("%d\n",lcs(m,n));

         }
    }
}
