#include<cstdio>

int ncr[10][10];

int main()
{
    int i,j;

    ncr[0][0] = 1;

    int limncr = 10;

    for(i = 1; i <= limncr; i++)
        for(j = 0; j <= limncr; j++)
        {
            if(j > i) ncr[i][j] = 0;
            else if(j == i || j == 0) ncr[i][j] = 1;
            else ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];

        }
    int n,r;
    while(scanf("%d %d",&n,&r)!=EOF)
    {
        printf("%d\n",ncr[n][r]);
    }
    return 0;

}

