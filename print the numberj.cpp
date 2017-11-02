
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    FILE *fp=fopen("10006.txt","w");
    for(int i=500;i<=1000;i++)
        fprintf(fp,"%d\n",i);
}

