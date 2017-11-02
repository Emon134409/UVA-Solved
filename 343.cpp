
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int char_to_int(char ch);

long long int poww(long long int base,int pow)
{
    int i;
    long long result=1;
    for(i=0; i<pow; i++)
    {
        result*=base;
    }
    return result;
}


int main()
{
    string in1,in2;
    int  min_base1,min_base2;
    int l1,l2;
    bool flag;

    while(cin>>in1>>in2)
    {
         flag=0;
         l1=in1.size();
         l2=in2.size();

        min_base1=char_to_int(in1[0])+1;
        min_base2=char_to_int(in2[0])+1;



        for(int i=1; i<l1; i++)
        {
            if(min_base1<=char_to_int(in1[i])) min_base1=char_to_int(in1[i])+1;

        }
        for(int i=1; i<l2; i++)
        {
            if(min_base2<=char_to_int(in2[i])) min_base2=char_to_int(in2[i])+1;

        }

         if(min_base1<2) min_base1=2;
         if(min_base2<2) min_base2=2;

        long long int temp1,temp2;
        long long int decimal1,decimal2;

        int base_1,base_2;

        for(int i=min_base1; i<=36; i++)
        {
            decimal1=0;

            for(int x=0; x<l1; x++)
            {
                temp1=char_to_int(in1[x])*poww(i,l1-x-1);
                decimal1=decimal1+temp1;



            }

            for(int j=min_base2; j<=36; j++)
            {
                 decimal2=0;
                for(int y=0; y<l2; y++)
                {
                    temp2=char_to_int(in2[y])*poww(j,l2-y-1);
                    decimal2=decimal2+temp2;

                }


                if(decimal1==decimal2) {
                           base_1=i;
                           base_2=j;
                           flag=1;
                           break;
                }
            }
            if(flag==1) break;
        }

        if(flag==1)
        {
            cout<<in1<<" (base "<<base_1<<") = "<<in2<<" (base "<<base_2<<")"<<endl;

        }
        else
            cout<<in1<<" is not equal to "<<in2<<" in any base 2..36"<<endl;


    }
    return 0;
}

int char_to_int(char ch)
{
    if(ch>='0' && ch<='9') return ch-48;
    else
    {
        return ch-55;
    }
}

