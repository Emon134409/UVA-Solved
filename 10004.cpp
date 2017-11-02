
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
    int node,edge,st,en;
    int arr[200+5][200+5];
    int color[205];



    while(scanf("%d",&node)&&node!=0)
    {
        queue<int> v;
        memset(arr,0,sizeof(arr));
        memset(color,-1,sizeof(color));

        scanf("%d",&edge);

        for(int i=0; i<edge; i++)
        {
            scanf("%d %d",&st,&en);
            arr[st][en]=1;
            arr[en][st]=1;
        }

        v.push(0);

        bool mai=true;

        while(!v.empty())
        {
            int u=v.front();
            v.pop();
            bool flag2=true;
            bool flag3=true;

            for(int i=0; i<node; i++)
            {
                if(arr[u][i]==1 && color[i]==2)
                {
                    flag2=false;
//                    printf("%d %d %d %d\n",i,u,color[i],tr);
//                    flag=false;

                }

                else if(arr[u][i]==1 && color[i]==3)
                {
                    flag3=false;
//                    printf("%d %d %d %d\n",i,u,color[i],tr);
//                    flag=false;

                }


                //color[u]=tr;
            }

            if(!flag2 && !flag3)
            {
                mai=false;
                break;
            }
            else if(!flag2 && flag3)
            {
                color[u]=3;
              //  printf("[%d]\n",u);

            }
            else if(!flag3 && flag2)
            {
                color[u]=2;
                //printf("[%d]\n",u);
            }
            else {
                color[u]=2;
            }

            for(int i=0; i<node; i++)
            {
                if(arr[u][i]==1 && color[i]==-1)
                {
                    v.push(i);
                }
            }


        }

        if(mai)
        {
            printf("BICOLORABLE.\n");
        }
        else
        {
            printf("NOT BICOLORABLE.\n");
        }



    }
    return 0;
}
