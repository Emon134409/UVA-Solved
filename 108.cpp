
#include<bits/stdc++.h>

using namespace std;

int arr[105][105];

int main()
{
    freopen("108.txt","r",stdin);
    int n,c_sum,t_sum;

    //ostream_iterator<int> out(cout," ");

     bool flag;

    while(scanf("%d",&n)!=EOF)
    {
        flag=false;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)
         {
                scanf("%d",&arr[i][j]);

                if(arr[i][j]>-1) flag=true;
         }
        }
        int kadanes[n+5];
        t_sum=INT_MIN;

        if(flag)
        for(int row=1; row<=n; row++)
        {
            memset(kadanes,0,sizeof(kadanes));
            for(int column=row; column<=n; column++)
            {

                for(int i=1; i<=n; i++)
                {
                    kadanes[i]=kadanes[i]+arr[i][column];
                }

                c_sum=kadanes[1];
                for(int i=2; i<=n; i++)
                {
                   c_sum=max(kadanes[i],kadanes[i]+c_sum);
                    t_sum=max(c_sum,t_sum);
                }
            }

        }

        else
        {
                for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    t_sum=max(t_sum,arr[i][j]);
        }
        printf("%d\n",t_sum);
    }

    return 0;
}
