
#include<bits/stdc++.h>

using namespace std;

int main()
{
   freopen("1.txt","r",stdin);

    char p[5];
   // gets
    char ch;
    int counter=0;
    while(scanf("%c",&ch)!=EOF)
    {
          if(ch=='I' || ch=='C' || ch=='D')
            counter++;
    }

    printf("%d\n",counter);

    return 0;
}
