#include<bits/stdc++.h>

using namespace std;


int inserted,deleted;

char str1[50],str2[50];
int m[50][50];
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
    if(i==0 && j==0)
    {
        //  number-1;
        return;
    }

    else if((i!=0&&j!=0)&&(str2[i-1]==str1[j-1]))
    {
        show(i-1,j-1);
    }
    else if(j>0 && m[i][j]==m[i][j-1]+1)
    {
        char ch1='D';
        char ch2=str1[j-1];
        //          flag[j]+=-1;

        show(i,j-1);
        //      int sum=0;
        //        for(int k=j-1; k>=1; k--)
        //        sum+=flag[k];

        int number=j+(inserted-deleted);

        if(number<10)
            printf("%c%c0%d",ch1,ch2,number);
        else
            printf("%c%c%d",ch1,ch2,number);

        deleted++;
    }

    else if(i>0 && m[i][j]==m[i-1][j]+1)
    {
        char ch1='I';
        char ch2=str2[i-1];
        //  flag[i]+=1
        //++;
        show(i-1,j);


        if(i<10)
            printf("%c%c0%d",ch1,ch2,i);
        else
            printf("%c%c%d",ch1,ch2,i);

        inserted++;

    }


    else //if((i>0 && j>0) && m[i][j]==m[i-1][j-1]+1)
    {
        char ch1='C';
        char ch2=str2[i-1];
        show(i-1,j-1);
        // int sum=0;
        //for(int k=j-1; k>=1; k--)
        //  sum+=flag[k];

        int number=j+(inserted-deleted);

        if(i<10)
            printf("%c%c0%d",ch1,ch2,i);
        else
            printf("%c%c%d",ch1,ch2,i);

    }

}

int main()
{
    freopen("164.txt","r",stdin);
    while(scanf("%s",str1))
    {
        if(!strcmp(str1,"#")) break;
        scanf("%s",str2);
//        counter=0;

        inserted=deleted=0;
       // memset(flag,0,sizeof(flag));

        l1=strlen(str1);
        l2=strlen(str2);

        edit_distance();
        show(l2,l1);

//        for(int i=number; i>=0; i--)
//        {
//            if(dam[i].number<10)
//            {
//                printf("%c%c0%d",dam[i].ch1,dam[i].ch2,dam[i].number);
//
//            }
//            else
//                printf("%c%c%d",dam[i].ch1,dam[i].ch2,dam[i].number);
//        }

        printf("E");
        printf("\n");


    }


    return 0;
}
