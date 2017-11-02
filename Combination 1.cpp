
#include<bits/stdc++.h>
using namespace std;

int n,k;
int number[3];

void combination(int at,int left)
{
            if(left==0)//>n-at+1)
             return;

            if(at==n+1)
            {
                cout<<endl;
                for(int i=1;i<=k;i++)
                    printf("%d ",number[i]);
                printf("\n");

                return;
            }

           // if(left)
            //{
                number[k-left+1] = at;
                combination(at+1,left-1);
          //  }
        //  cout<<at<<" "<<left<<endl;
            combination(at+1,left);
}

int main()
{
    n=3;
    k=2;
    combination(1,k);
    return 0;
}
