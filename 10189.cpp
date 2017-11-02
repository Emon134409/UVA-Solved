#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char s[200][200];
    int n,i,j,k,l,a,b,co,t,u,v,x,y=1,sa,sb;
    while(scanf("%d %d",&a,&b)==2)
    {
        if(a==0&&b==0)
            break;
        getchar();
        if(y!=1)
            printf("\n");
        for(i=0; i<a; i++)
        {
            gets(s[i]);
        }

        int arr[15000] = {0};
        co =0;

        for(k=0; k<a-1; k++)
        {
            for(j=0; j<b; j++)
            {
                if(s[k][j]!='*')
                {
                    int cnt = 0;
                    if(s[k-1][j-1]=='*')
                    {
                        cnt++;
                    }
                    if(s[k-1][j]=='*')
                    {
                        cnt++;
                    }
                    if(s[k-1][j+1]=='*')
                    {
                        cnt++;
                    }
                    if(s[k][j-1]=='*')
                    {
                        cnt++;
                    }
                    if(s[k][j+1]=='*')
                    {
                        cnt++;
                    }
                    if(s[k+1][j-1]=='*')
                    {
                        cnt++;
                    }
                    if(s[k+1][j]=='*')
                    {
                        cnt++;
                    }
                    if(s[k+1][j+1]=='*')
                    {
                        cnt++;
                    }

                    arr[co++]= cnt;
                }
            }
        }

        for(sa=0; sa<b; sa++)
        {
            if(s[a-1][sa]!='*')
            {
                int cntt = 0;
                if(s[a-2][sa-1]=='*')
                {
                    cntt++;
                }
                if(s[a-2][sa]=='*')
                {
                    cntt++;
                }
                if(s[a-2][sa+1]=='*')
                {
                    cntt++;
                }
                if(s[a-1][sa-1]=='*')
                {
                    cntt++;
                }
                if(s[a-1][sa+1]=='*')
                {
                    cntt++;
                }
                arr[co++]= cntt;
            }
        }

        x = 0;

        printf("Field #%d:\n",y);

        for(u=0; u<a; u++)
        {
            for(t=0; t<b; t++)
            {
                if(s[u][t]=='*')
                    printf("*");
                else if(s[u][t]=='.')
                {
                    printf("%d",arr[x]);
                    x++;
                }
            }
            printf("\n");
        }

        y++;
    }
    return 0;
}
