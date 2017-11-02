
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

int arr[1005][1005];
int len[1005][1005];
int vis[1005][1005];

void clearr( std::queue< pair<int,int> > &q )
{
   std::queue< pair<int,int> > emp;
   std::swap( q, emp );
}

void graph(int r,int c,int s,int d)
{
    memset(vis,0,sizeof(vis));

    int fx[]= {+1,-1,0,0};
    int fy[]= {0,0,+1,-1};

    vis[s][d]=1;
    queue< pair<int,int> > q;
    q.push( pair<int,int>(s,d) );
    len[s][d]=0;

    while(!q.empty())
    {
        pair<int,int> top=q.front();
        q.pop();

        int nx,ny;
        for(int k=0; k<4; k++)
        {
            int nx=top.first  +fx[k]; //Add fx[k] with current row
            int ny=top.second +fy[k];
             //Add fy[k] with current col
            if(arr[nx][ny]!=-1 && nx>=0 && nx<r && ny>=0 && ny<c && vis[nx][ny]==0 )
            {
                vis[nx][ny]=1;
                int h=top.first;
                int j=top.second;
                len[nx][ny]=len[h][j]+1;
               // printf("[%d]",len[nx][ny]);
                q.push(pair<int,int>(nx,ny));
            }
        }

    }

    clearr(q);

}

int main()
{
    int r,c;
    int s1,s2,d1,d2;
    int nor;
    int nthr;
    int nob;
    int n;

    while(scanf("%d %d",&r,&c))
    {
        if(r==0 && c==0)
            break;

        memset(arr,0,sizeof(arr));

        scanf("%d",&nor);

        for(int i=0; i<nor; i++)
        {
            scanf("%d",&nthr);
            scanf("%d",&nob);

            for(int j=0; j<nob; j++)
            {
                scanf("%d",&n);
                arr[nthr][n]=-1;
            }
        }

        scanf("%d %d",&s1,&s2);
        scanf("%d %d",&d1,&d2);
        graph(r,c,s1,s2);

        printf("%d\n",len[d1][d2]);
    }

    return 0;
}
