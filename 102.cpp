
#include<bits/stdc++.h>

using namespace std;


int main()
{
    int arr[9];
    int ans[9];

    string str[9]= {"GBC","GCB","BGC","BCG","CBG","CGB"};

    while(scanf("%d %d %d %d %d %d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6],&arr[7],&arr[8],&arr[9])!=EOF)
    {
        //memset(ans,0,sizeof(ans));

        ans[0]=arr[4]+arr[7]+arr[0]+arr[6]+arr[2]+arr[5];
        ans[1]=arr[4]+arr[7]+arr[2]+arr[8]+arr[0]+arr[3];
        ans[2]=arr[3]+arr[6]+arr[1]+arr[7]+arr[2]+arr[5];
        ans[3]=arr[3]+arr[6]+arr[2]+arr[8]+arr[1]+arr[4];
        ans[4]=arr[5]+arr[8]+arr[0]+arr[6]+arr[1]+arr[4];
        ans[5]=arr[5]+arr[8]+arr[1]+arr[7]+arr[0]+arr[3];

        int temp=0;

        for(int i=1; i<=5; i++)
        {
            if(ans[i]<ans[temp])
            {
                temp=i;
            }

            else if(ans[i]==ans[temp])
            {
                if(str[i].compare(str[temp])<0)
                {
                    temp=i;
                }

            }
        }
         printf("%s %d\n",str[temp].c_str(),ans[temp]);


    }

    return 0;
}

