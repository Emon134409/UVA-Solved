#include<bits/stdc++.h>

using namespace std;


int inserted,deleted;

char str1[100],str2[100];
int m[100][100];
int l1,l2,counter;

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

        printf("%d\n",m[l2][l1]);
}

void show(int i,int j)
{
    if(i==0 && j==0)
    {
        return;
    }

    else if((i!=0&&j!=0)&&(str2[i-1]==str1[j-1]))
    {
        show(i-1,j-1);
    }
    else if(j>0 && m[i][j]==m[i][j-1]+1)
    {
        show(i,j-1);
        int number=j+(inserted-deleted);
        printf("%d Delete %d\n",++counter,number);
        deleted++;
    }

    else if(i>0 && m[i][j]==m[i-1][j]+1)
    {

        show(i-1,j);
        printf("%d Insert %d,%c\n",++counter,i,str2[i-1]);

        inserted++;

    }


    else //if((i>0 && j>0) && m[i][j]==m[i-1][j-1]+1)
    {

        show(i-1,j-1);
        int number=j+(inserted-deleted);
        printf("%d Replace %d,%c\n",++counter,number,str2[i-1]);

    }

}

int main()
{
    bool flag=false;
   //freopen("526.txt","r",stdin);
    while(gets(str1))
    {
        //getchar();
        gets(str2);
       // getchar();

        counter=inserted=deleted=0;

        l1=strlen(str1);
        l2=strlen(str2);

        if(flag==false)
        {
             flag=true;
        }
        else printf("\n");
        edit_distance();
        show(l2,l1);



    }


    return 0;
}
