
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

bool printlcs(int i,int j)
{
    bool flag;

    if(i==0 || j==0){
        return false;
    }

    if(b[i][j]==1)
    {

        flag= printlcs(i-1,j-1);
        if(flag)
        printf(" ");
        printf("%s",str1[i-1].c_str());
        return true;

    }

    else if(b[i][j]==2) printlcs(i-1,j);

    else printlcs(i,j-1);
}

int main()
{

    freopen("531.txt","r",stdin);
    string a;
    int l1,l2;

    bool flag;

    while(1)
    {
        flag=false;
        l1=0;
        l2=0;

        while(cin>>a)
        {
            if(a.compare("#")==0) break;
            getchar();
            flag=true;
            str1[l1++]=a;
        }

        if(!flag) break;

        while(cin>>a)
        {
            if(a.compare("#")==0)
                break;

             getchar();
            str2[l2++]=a;
        }

        lcs(l1,l2);

        printlcs(l1,l2);

        printf("\n");

//        for(int j=0;j<i;j++)
//            printf("%s\n",str2[j].c_str());
    }

    return 0;
}
