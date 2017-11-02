
#include<bits/stdc++.h>
using namespace std;

struct cord
{
    int x,y;

};


int compare(const void *a , const void *b)
{
    cord *temp1=(cord *)a;
    cord *temp2=(cord *)b;

    if(temp1->x!=temp2->x)
        return temp1->x - temp2->x;
    return temp2->y - temp1->y;
}

int main()
{
    freopen("10020.txt","r",stdin);
    cord v[5005];
    bool flag[5005];

    int n,m,l;
    int test1,test2;

    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        getchar();
        scanf("%d",&m);
        memset(flag,0,sizeof(flag));
        l=0;
        while(scanf("%d %d",&test1,&test2) && (test1!=0 || test2!=0))
        {
            v[l].x=test1;
            v[l++].y=test2;
        }

        qsort(v,l,sizeof(cord),compare);

        int counter=0,temp=0,temp1;

        for(int j=0; j<l;)
        {
              temp1=j;
             while(v[j+1].x<=temp )//&& v[j+1].y>temp)
             {
                 if(v[j+1].y>v[temp1].y)
                    temp1=j+1;
                 j++;
             }
             flag[temp1]=1;
            // counter++;
             temp=v[temp1].y;

             if(temp>m) break;
        }


        if(temp<m) printf("0");
        else
        {
             printf("%d\n",counter);
            for(int j=0; j<l; j++)
                if(flag[j])
                printf("%d %d\n",v[j].x,v[j].y);

              printf("\n");
        }


    }

    return 0;
}

