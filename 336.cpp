
#include<cstdio>
#include<cstring>
#include<queue>
#include<list>

using namespace std;

int main()
{
    //vector<int> node[35];
    int e1,e2;
    int m,n;
    bool flag1,flag2;
    int k=0,cas=0;
    while(scanf("%d",&n) && n!=0)
    {
        list<int> v[35];
        k=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&e1,&e2);

            flag1=flag2=true;

            for(int j=0; j<k; j++)
            {
                if(*(v[j].begin())==e1)
                {
                    if(e1!=e2)
                        v[j].push_back(e2);

                    flag1=false;
                }
                if(*(v[j].begin())==e2 )
                {
                    if(e1!=e2)
                        v[j].push_back(e1);
                    flag2=false;
                }
            }

            if(flag1)
            {
                if(e1!=e2)
                {
                    v[k].push_back(e1);
                    v[k].push_back(e2);

                }
                else
                {
                    v[k].push_back(e1);
                }
                k++;
            }
            if(flag2)
            {
                if(e1!=e2)
                {
                    v[k].push_back(e2);
                    v[k].push_back(e1);

                    k++;
                }
            }


        }


        while(scanf("%d %d",&m,&n))
        {
            queue<int> ans;
            int counter=0;

            if(m==0 && n==0)
            {
                break;
            }
            int j;
            int level[35];
            memset(level,-1,sizeof(level));
            ans.push(m);

            bool hj=true;

            for(j=0; j<k; j++)
            {
                if(*(v[j].begin())==m)
                {
                    hj=false;
                    level[j]=0;

                    break;
                }
            }
            if(!hj)
            {
                k--;
            }


            while(!ans.empty())
            {
                int nn=ans.front();
                ans.pop();
                for(j=0; j<k; j++)
                {
                    if(*(v[j].begin())==nn)
                    {
                        break;
                    }
                }

                list<int>::iterator i=v[j].begin();
                i++;

                for(; i!=v[j].end(); i++)
                {
                    int l;
                    for(l=0; l<k; l++)
                    {
                        if(*(v[l].begin())==*i)
                        {
                            break;
                        }
                    }

                    if(level[l]==-1 && level[j]<n )//&& *i!=*(v[j].begin()))
                    {
                        counter++;
                        level[l]=level[j]+1;
                     //   printf("%d\n",level[l]);
                        ans.push(*i);
                    }
                }
            }
            //printf("%d %d\n",k,counter);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cas,k-counter,m,n);



            if(!hj)
            {
                k++;
            }

        }


//
//            for(int j=0;j<k;j++)
//            {
//                printf("%d\n",*(v[j].begin()));
//                for(list<int>::iterator i=v[j].begin();i!=v[j].end();i++)
//                {
//                    printf("%d ",*i);
//                }
//                printf("\n");
//            }


    }
    return 0;
}
