
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
    cord v[100005];
    bool flag[100005];

    int n,m,l;
    int test1,test2,counter;

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
//
//        for(int j=0;j<l;j++)
//            printf("%d %d\n",v[j].x,v[j].y);
//
//        printf("\n\n");
//

        int temp=0,temp1;
        counter=0;

        bool flag1=false;

        for(int j=0; j<l;)
        {
            temp1=j;

            if(v[temp1].y<=temp)
            {
                j++;
                continue;
            }

            while(v[j+1].x<=temp && j+1<l )//&& v[j+1].y>temp)
            {
                if(v[j+1].y>v[temp1].y)
                {
                    temp1=j+1;
                }

                j++;
            }

            // cout<<v[temp1].x<<" "<<v[temp1].y<<endl;

            if(v[temp1].x>temp)
            {
                flag1=true;
                break;
            }
//
            else if(v[temp1].x>=m)
            {
                break;
            }

            else if(v[temp1].x<=temp && v[temp1].y>temp)
            {
              //  if(v[temp1].y<=m){
                flag[temp1]=1;
                counter+=1;
                temp=v[temp1].y;

                //}
            }

            if(temp>=m) break;

            j++;

        }

         if(temp<m) flag1=true;
         //if(v[counter-1].y<m) flag1=true;

        if(flag1 /*|| v[counter-1].y<m*/ ) printf("0\n");
        else
        {
            printf("%d\n",counter);
            for(int j=0; j<l; j++)
                if(flag[j])
                    printf("%d %d\n",v[j].x,v[j].y);

        }
        if(i<=n-2) printf("\n");
    }

    return 0;
}

