#include<cstdio>
#include<utility>
#include<cstring>
#include<queue>
using namespace std;

int arr[10][10];
int vis[10][10],len[10][10];

int pos(char ch)
{
    return (int)(ch)%97;
}


void clearr( queue< pair<int,int> > &q )
{
   queue< pair<int,int> > emp;
   swap( q, emp );
}

void graph(int r,int c,int s,int d)
{
    memset(vis,0,sizeof(vis));

    int fx[]= {-2,-2,2,2,-1,1,-1,1};
    int fy[]= {-1,1,-1,1,-2,-2,+2,2};

    vis[s][d]=1;

    queue< pair<int,int> > q;
    q.push( pair<int,int>(s,d) );
    len[s][d]=0;

    while(!q.empty())
    {
        pair<int,int> top=q.front();
        q.pop();

        int nx,ny;
        for(int k=0; k<8; k++)
        {
            int nx=top.first  +fx[k]; //Add fx[k] with current row
            int ny=top.second +fy[k];
             //Add fy[k] with current col
            if(nx>=0 && nx<r && ny>=0 && ny<c && vis[nx][ny]==0 )
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
    char ch1,ch2;
    int n1,n2;

    while(scanf("%c %d",&ch1,&n1)!=EOF)
    {
        scanf("%c",&ch2);
        scanf("%c %d",&ch2,&n2);
        graph(8,8,n1-1,pos(ch1));
        printf("To get from %c%d to %c%d takes %d knight moves.\n",ch1,n1,ch2,n2,len[n2-1][pos(ch2)]);
        scanf("%c",&ch1);
    }
    return 0;
}

