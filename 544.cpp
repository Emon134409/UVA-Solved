
#include<bits/stdc++.h>

using namespace std;


void clearr( std::queue< int > &q ,map< string ,int > &m)
{
    std::queue< int > emp;
    map<string ,int > em;
    std::swap( q, emp );
    swap(m,em);
}



int main()
{
    freopen("544.txt","r",stdin);
    int n,r;
    int casee=1;
    string st,en;
    int w,asign;
    int level[205];
    map< string , int > m;
    priority_queue<int> q;
    int arr[205][205];


    while(scanf("%d %d",&n,&r) && (n!=0 || r!=0))
    {
        asign=0;
        memset(arr,-1,sizeof(arr));
        memset(level,-1,sizeof(level));
        for(int i=0; i<r; i++)
        {
            cin>>st>>en>>w;
            if(m.find(st)==m.end())
            {
                m[st]=asign++;
            }

            if(m.find(en)==m.end())
            {
                m[en]=asign++;
            }

            int pos1=m[st];
            int pos2=m[en];
            arr[pos1][pos2]=w;
            arr[pos2][pos1]=w;
        }
//
        cin>>st>>en;
        if(m.find(st)==m.end())
        {
            m[st]=asign++;
        }

        if(m.find(en)==m.end())
        {
            m[en]=asign++;
        }

        q.push(m[st]);
        level[m[st]]=INT_MAX;

        while(!q.empty())
        {
            int temp=q.front();
            q.pop();

            printf("temp=%d\n",temp);
            for(int j=0; j<n; j++)
            {
                if(arr[temp][j]!=-1)
                {
                    if(level[j]==-1)
                        q.push(j);
                    if(arr[temp][j]<level[temp] && level[j]<arr[temp][j])
                    {
                        level[j]=arr[temp][j];
                        printf("[%d-%d]==[%d]\n",temp,j,level[j]);
                    }
                    else if(arr[temp][j]>level[temp] && level[j]<level[temp])
                    {
                        level[j]=level[temp];
                        printf("[%d-%d]==[%d]\n",temp,j,level[j]);

                    }
                }
            }

        }
        if(level[m[en]]!=-1)
        {
            printf("Scenario #%d\n",casee++);
            printf("%d tons\n\n",level[m[en]]);

        }
        else
        {
            printf("Scenario #%d\n",casee++);
            printf("%d tons\n\n",0);
        }

//

        printf("%d\n",m.size());
        map<string ,int >::iterator iter;
        for (iter = m.begin(); iter != m.end(); iter++)
        {
            cout << iter->first << " "<<iter->second << endl;

        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }

          clearr(q,m);

    }
    return 0;
}
