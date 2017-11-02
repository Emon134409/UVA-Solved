#include<bits/stdc++.h>

using namespace std;

string str1[105];
string str2[105];

int c[105][105],b[105][105];

int l;

void lcs(int m,int n)
{
    for(int i=1;i<=m ;i++) c[i][0]=0;
    for(int j=0;j<=n;j++) c[0][j]=0;

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
    {
        if( str1[i-1].compare(str2[j-1])==0)
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

}

int main()
{
    string a;



    return 0;
}
