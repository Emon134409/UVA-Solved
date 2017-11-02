
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

int main()
{
    char str[205][15];

    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        int k=0;
        char word[15];
        while(scanf("%s",word) && strcmp(word,"*"))
        {
            strcpy(str[k++],word);
        }

        char word1[15];
        bool flag[15];
        memset(flag,0,sizeof(flag));
        while(scanf("%s %s",word,word1)!=EOF)
        {
            for(int j=0;j<k;j++)
            {
                int len1=strlen(word);
                int len2=strlen(str[j]);

                if(len1==len2)
                {
                    int counter=0,counter1=0;
                    for(int l=0;l<len1;l++)
                    {
                        if(word[l]!=str[j][l])
                        {
                            counter++;
                        }
                        if(word1[l]==str[j][l])
                    }

                    if(counter==1)
                    {

                    }
                }
            }
        }

    }

    return 0;
}
