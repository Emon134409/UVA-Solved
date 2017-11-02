
#include<bits/stdc++.h>

using namespace std;

struct data
{
    char ch1;
    char ch2;
    int number;
};

string str1,str2;
int m[25][25];

int flag[25];

data dam[25];

int l1,l2;

void edit_distance()
{


    m[0][0]=0;

    for(int i=1; i<=l1; i++)
        m[0][i]=i;

    for(int i=1; i<=l2; i++)
        m[i][0]=i;


    for(int i=1; i<=l2; i++)
        for(int j=1; j<=l1; j++)
        {
            if(str2[i-1]==str1[j-1])
                m[i][j]=m[i-1][j-1];
            else
            {
                m[i][j]=min(m[i-1][j-1]+1,min(m[i-1][j]+1,m[i][j-1]+1));
            }
        }

//    for(int i=0; i<=l2; i++)
//    {
//        for(int j=0; j<=l1; j++)
//        {
//            printf("%d ",m[i][j]);
//        }
//
//        printf("\n");
//    }

}


void print()
{
    memset(flag,0,sizeof(flag));

    int i=l2,j=l1;
    int temp=m[l2][l1];
    int counter=0;

    //  printf("%d %d\n",i,j);

    while(i>0 || j>0)
    {
        // printf("%c %c ",str1[j-1],str2[i-1]);
        // printf("%d\n",m[i][j]);

        if(i!=0 && j!=0)
            if(str2[i-1]==str1[j-1])
            {
                //printf("%d %d\n",i,j);
                //     printf("[%c %c]\n",str2[i-1],str1[j-1]);
                i=i-1;
                j=j-1;

                continue;
            }



        //else
        //{
        // printf("%d ",j);
        //printf("%c ",str1[j-1]);
        //  temp=min(m[i-1][j-1],min(m[i-1][j],m[i][j-1]));
        //printf("%d %d ",i,j);
        // printf("%c %c",str1[j-1],str2[i-1]);
        //    printf("%d ",temp);

        if(i>0 && m[i][j]==m[i-1][j]+1)
        {
            dam[counter].ch1='I';
            dam[counter].ch2=str2[i-1];
            flag[j]+=1;

            i=i-1;
        }

        else if(j>0 && m[i][j]==m[i][j-1]+1)
        {
            dam[counter].ch1='D';
            dam[counter].ch2=str1[j-1];
            flag[j]=-1;
            //dam[counter].number=j;
            j=j-1;
        }

        else if( m[i][j]==m[i-1][j-1]+1)
        {
            dam[counter].ch1='C';
            dam[counter].ch2=str2[i-1];
            i=i-1;
            j=j-1;
        }
        // printf("%d\n",temp);

        counter++;
    }


//        if(j==0 && i>0)
//        {
//
//            j++;
//        }



//   }

//    for(int i=1;i<=l1;i++)
//        printf("%d",flag[i]);

    // printf("\n");

    for(int i=counter-1; i>=0; i--)
    {
        printf("%c%c",dam[i].ch1,dam[i].ch2);
    }

    printf("\n");

}

int main()
{
    freopen("164.txt","r",stdin);
    while(cin>>str1>>str2 && str1.compare("#"))
    {
        l1=str1.size();
        l2=str2.size();

        edit_distance();
        print();
    }


    return 0;
}
