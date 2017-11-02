
#include<bits/stdc++.h>

using namespace std;

int main()
{
    char k='a';

    printf("%c",++k);

    stack<  pair< int , int> > v;
      pair< int , int>  z;

    int m,n;

    while(scanf("%d %d",&m,&n)!=EOF)
    {
        v.push(make_pair(m,n));
    }



      while(!v.empty())
    {
        z=v.top();
        printf("%d %d\n",z.first,z.second);
        v.pop();

    }
}
