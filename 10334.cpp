
#include<bits/stdc++.h>

using namespace std;

char *fibo[550];
char fib[550][200];

void fiboo()
{
    fibo[0]="0";
    fib[0][0]='0';
    fib[0][1]='\0';

    fibo[1]="1";
    fib[1][0]='1';
    fib[1][1]='\0';

    int l1=strlen(fibo[0]);
    int l2=strlen(fibo[1]);

    int l;

    for(long i=2; i<=550; i++)
    {
        char str[200];
        if(l1>=l2)l=l1;
        else l=l2;
        int ca=0;
        long j,k,m,p;

        for(j=l1-1,k=l2-1,m=0,p=0; p<l; j--,k--,m++,p++)
        {
            int s1;
            if(j<0)fibo[i-2][j]='0';
            s1=fibo[i-2][j]-48;
            int s2;
            if(k<0)fibo[i-1][k]='0';
            s2=fibo[i-1][k]-48;
            int ans=0;
            ans+=s1+s2+ca;
            if(ans>9)
            {
                str[m]=(ans-10)+48;
                ca=1;
            }
            else
            {
                str[m]=ans+48;
                ca=0;
            }
        }
        if(ca>0)
        {
            str[m]=ca+48;
            m++;
        }
        str[m]='\0';
        fibo[i]=new char[m+1];
        //fib[i]=new char[m+1];

        long y=0;
        for(long x=m-1; x>=0; x--,y++)
        {
            fibo[i][y]=str[x];
            fib[i][y]=str[x];


        }
        fibo[i][y]='\0';
        fib[i][y]='\0';



        l1=strlen(fibo[i-1]);
        l2=strlen(fibo[i]);
    }

}




int main()
{
    fiboo();
    int counter;

    char m[200];
    char n[200];

    while(scanf("%s %s",m,n)!=EOF)
    {

        counter=0;

        for(int i=1;; i++)
        {

            if(strcmp(fib[i],n)>0)
            {
//                       cout<<strcmp(fib[i],n)<<endl;
//            cout<<fib[i]<<" "<<n<<endl;
                break;
            }

            else if(strcmp(fib[i],m)>=0)
            {

                counter++;
            }
            //  cout<<fib[i]<<" ";


        }


        //printf("%d\n",strcmp(fib[8],n));
        printf("%d\n",counter);
    }
    return 0;
}
