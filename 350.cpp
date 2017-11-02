
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    int z,i,m,l;

    int arr[9998+5];


    int casee=0;

    while(1){

        scanf("%d %d %d %d",&z,&i,&m,&l);
           memset(arr,-1,sizeof(arr));

        if(z==0 && i==0 && m==0 && l==0)
        {
            break;
        }

        int len=0;

        while(1){

            int ran=(z*l+i)%m;
            if(arr[ran]==1)
            {
                break;
            }
            else
            arr[ran]=1;
            len++;

            l=ran;

        }

        printf("Case %d: %d\n",++casee,len);

    }
    return 0;
}
