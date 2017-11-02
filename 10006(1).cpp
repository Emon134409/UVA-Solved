
#include<cstdio>

int main()
{
    int x;
    while(1)
    {
        scanf("%d",&x);

        if(x==0) break;

        if(x==561 || x==1105 || x==1729 || x==2465 || x==2821 || x==6601 || x==8911 || x==10585 || x==29341 || x==15841 || x==41041 || x==46657 || x==52633 || x==62745 || x==63973)
            printf("The number %d is a Carmichael number.\n",x);
        else  printf("%d is normal.\n",x);

    }
    return 0;
}
