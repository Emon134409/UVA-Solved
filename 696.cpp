
#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>

using namespace std;

struct data
{
    char str[55];
    int number;
};

int compare(const void *a,const void *b)
{
       data *x=(data *)a;
       data *y=(data *)b;
      int age =x->number - y->number;
    return age != 0 ? age : x->number - y->number;
}

int main()
{
  //  freopen("696.txt","r",stdin);
    int number,n,m,counter;
    data obj[105];


    scanf("%d",&number);

    for(int i=0; i<number; i++)
    {
        scanf("%d %d",&n,&m);
        for(int j=0; j<m; j++)
        {
            cin>>obj[j].str;
            counter=0;
            for(int k=0; k<n-1; k++)
            {
                if(obj[j].str[k]=='A') continue;

                for(int l=k+1; l<n; l++)
                {
                    if(obj[j].str[k]>obj[j].str[l]) counter++;
                }
            }
            obj[j].number=counter;
        }

       qsort(obj,m,sizeof(data),compare);

       for(int i=0;i<m;i++)
       {
          printf("%s\n",obj[i].str);
       }
       if(i<number-1)
       printf("\n");


    }

    return 0;
}
