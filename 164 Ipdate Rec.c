


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
int temp,counter=0;

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

void show(int i,int j)
{
    if(i==0 && j==0) return;

    else if((i!=0&&j!=0)&&(str2[i-1]==str1[j-1]))
    {
        show(i-1,j-1);
    }

    if(i>0 && m[i][j]==m[i-1][j]+1)
    {
        dam[counter].ch1='I';
        dam[counter].ch2=str2[i-1];
        flag[j]+=1;
        counter++;
        show(i-1,j);

    }

    else if(j>0 && m[i][j]==m[i][j-1]+1)
    {
        dam[counter].ch1='D';
        dam[counter].ch2=str1[j-1];
        flag[j]+=-1;
        counter++;
        show(i,j-1);
    }
    else if( m[i][j]==m[i-1][j-1]+1)
    {
        dam[counter].ch1='C';
        dam[counter].ch2=str2[i-1];
        counter++;
        show(i-1,j-1);
    }

//    int sum=0;
//    for(int k=j-1;k>=0;k--)
//        sum+=flag[]

}

int main()
{
    freopen("164.txt","r",stdin);
    while(cin>>str1>>str2)
    {
        counter=0;
        memset(flag,0,sizeof(flag));

        l1=str1.size();
        l2=str2.size();

        edit_distance();
        show(l2,l1);

        for(int i=counter-1; i>=0; i--)
        {
            printf("%c%c",dam[i].ch1,dam[i].ch2);
        }

        printf("\n");

    }


    return 0;
}
