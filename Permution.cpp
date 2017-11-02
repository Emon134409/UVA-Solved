
#include<bits/stdc++.h>
using namespace std;

int used[20], number[20];
//call with: permutation(1, n)
//make sure, all the entries in used[] is 0
void permutation(int at, int n)
{
    if(at == n + 1)
    {
        printf("\n");
        for(int i = 1; i <= n; i++)
            printf("%d ", number[i]);
        printf("\n");
        return;

    }
    for(int i = 1; i <= n; i++)
        if(!used[i])
        {

            used[i] = 1;
            number[at] = i;

            printf("%d ",at);
            permutation(at + 1, n);
            used[i] = 0;

        }
}

int main()
{
    memset(used,0,sizeof(used));
    permutation(1,3);
}
