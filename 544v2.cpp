
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int no;
    int key;

    bool operator<(const node& rhs) const
    {
        return a < rhs.a;
    }
};

int main()
{
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
                level[m[st]]=INT_MAX;
            }

            if(m.find(en)==m.end())
            {
                m[en]=asign++;
                level[m[en]]=INT_MAX;
            }

            int pos1=m[st];
            int pos2=m[en];
            arr[pos1][pos2]=w;
            arr[pos2][pos1]=w;
        }

          cin>>st>>en;
        if(m.find(st)==m.end())
        {
            m[st]=asign++;
            level[m[st]]=INT_MAX;
        }

        if(m.find(en)==m.end())
        {
            m[en]=asign++;
            level[m[en]]=INT_MAX;
        }

        level[m[en]]=0;


    }
    return 0;
}
