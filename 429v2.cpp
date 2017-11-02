#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include <sstream>
#include<string>

using namespace std;

string str[205];

void clearr( std::queue<string> &q )
{
   std::queue<string> emp;
   std::swap( q, emp );
}


int main()
{
    queue<string> q;

    int level[205];
    int n;
    scanf("%d",&n);
   getchar();
    getchar();

    bool bal=true;

    for(int i=0; i<n; i++)
    {
        if(bal)
        {
            bal=false;
        }
        else
        {
            printf("\n");
        }
       //getchar();
        int k=1;
        //char word[15];
        string word;

        while(cin>>word )
        {
            //cout<<word<<endl;
            if(word.compare("*")==0)
                break;
            // strcpy(str[k++],word);
            str[k++].assign(word);

        }

//        for(int j=1;j<=k;j++)
//        {
//            cout<<str[j]<<endl;
//        }

        //char word1[15];

        string word1;
        getchar();
        while(getline(cin,word))
        {

            if(!word.compare(""))
                break;

            istringstream iss(word);

                string sub;
                iss >> sub;
                word.assign(sub);
                iss >> sub;
                word1.assign(sub);

            memset(level,-1,sizeof(level));
            q.push(word);
            level[0]=0;
            bool flag=false;

            while(!q.empty())
            {
                string temp;
                int pos;
                //char temp[15];
                //strcpy(temp,q.front());
                temp.assign(q.front());
                q.pop();

                if(!flag)
                {
                    flag=true;
                    pos=0;
                }
                else
                {
                    for( pos=1; pos<=k; pos++)
                    {
                        //if(!strcmp(temp,str[pos]))
                        if(temp.compare(str[pos])==0)
                        {
                            break;
                        }
                    }
                }

                //if(!strcmp(temp,word1))
                if(!temp.compare(word1))
                {
                    printf("%s %s %d\n",word.c_str(),word1.c_str(),level[pos]);
                    break;
                }

                int len1=temp.length();

                for(int j=1; j<=k; j++)
                {

                    int len2=str[j].length();

                    if(len1==len2)
                    {
                        int counter=0,counter1=0;
                        for(int l=0; l<len1; l++)
                        {
                            if(temp[l]!=str[j][l])
                            {
                                counter++;
                            }

                        }

                        if(counter==1 && level[j]==-1)
                        {
                            q.push(str[j]);
                            level[j]=level[pos]+1;

              //              printf("%s %d\n",str[j].c_str(),level[j]);
                        }
                    }
                }
            }
                clearr(q);
        }

    }

    return 0;
}
