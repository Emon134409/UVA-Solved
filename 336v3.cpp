
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

int main()
{
    int arr[35][35];

    int e1,e2,m,n,y;


    int casee=0;
    int node[35];
    int sco;
    int start,en;
    bool flag1,flag2;

    while(scanf("%d",&y) && y!=0)
    {
        sco=0;
        memset(arr,0,sizeof(arr));
        //memset(node,0,sizeof(node));
        for(int i=0;i<y;i++)
        {
            scanf("%d %d",&e1,&e2);
            flag1=flag2=true;

            for(int k=0;k<sco;k++)
            {
                if(e1==node[k])
                {
                    flag1=false;
                    start=k;
                }
                if(e2==node[k])
                {
                    flag2=false;
                    en=k;
                }
            }

            if(flag1)
            {
                soc++;
                start=soc;
            }
            if(flag2)
            {
                soc++;
                en=soc;
            }

            arr[start][en]=1;
            arr[en][start]=1;

            if(!node[e1] )
            {
                node[e1]=true;
                sco++;
            }

            if(!node[e2] )
            {
            	node[e2]=true;
                sco++;
            }


        }

		sco--;
                while(scanf("%d %d",&m,&n))
                {
                    if(m==0 && n==0) break;
                	queue<int> v;
                    int counter=0;
                    int level[500];
                    memset(level,-1,sizeof(level));

                    v.push(m);
                    level[m]=0;

                    while(!v.empty())
                    {
                        int u=v.front();
                        v.pop();

                        for(int i=0;i<500;i++)
                        {
                            if(arr[u][i]==1 && level[i]==-1 && level[u]<n)
                            {
                                level[i]=level[u]+1;
                                v.push(i);
								//if(level[i]<=n)
                               	counter++;
                            }

                        }
                    }
//                    printf("%d %d\n",sco,counter);

                    printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++casee,sco-counter,m,n);

                }

    }

    return 0;
}

