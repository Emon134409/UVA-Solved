
#include<bits/stdc++.h>

using namespace std;

struct team
{
    string name;
    int play;
    int win;
    int loose;
    int draw;
    int point;
    int goalF;
    int goalA;
};

int compare(const void *a,const void *b)
{
    team *c = (team *)a;
    team *d = (team *)b;

    if(c->point!=d->point)
    {
        return d->point-c->point;
    }
    else
    {
        if(c->win!=d->win)
            return d->win-c->win;
        else
        {
            if((c->goalF-c->goalA)!=(d->goalF-d->goalA))
                return (d->goalF-d->goalA)-(c->goalF-c->goalA);
            else
            {
                if(c->goalF!=d->goalF)
                    return d->goalF-c->goalF;
                else
                {
                    if(c->play!=d->play)
                        return c->play-d->play;
                    else
                    {
                        string a,b;
                        int l=0;

                        for(int k=0; k<c->name.size(); k++)
                        {

                                a.resize(l+1);
                                a[l++]=tolower(c->name[k]);

                        }

                        l=0;

                        for(int k=0; k<d->name.size(); k++)
                        {
                                b.resize(l+1);
                                b[l++]=tolower(d->name[k]);

                        }

                            return a.compare(b);
                        // cout<<c->name<<" "<<d->name<<endl;
                       // return c->name.compare(d->name);

                    }
                }
            }
        }
    }
}

int main()
{
   // freopen("10194.txt","r",stdin);

    team tem[35];

    string scorecard[1005];
    string title;

    int n,t,g,k,l;

    string first;
    char home[3];
    string second;
    char away[3];
    string dummy;

    cin>>n;
    //scanf("%d",&n);
      getline(cin,dummy);
    for(int i=0; i<n; i++)
    {
        // cin>>title;

        getline(cin,title);
        //scanf("%d",&t);
        cin>>t;
        getline(cin,dummy);
        for(int j=0; j<t; j++)
        {

            getline(cin,tem[j].name);
            //    cin>>tem[j].name;
            // cout<<tem[j].name;

            tem[j].draw=0;
            tem[j].goalA=0;
            tem[j].goalF=0;
            tem[j].loose=0;
            tem[j].play=0;
            tem[j].point=0;
            tem[j].win=0;
        }
        //scanf("%d",&g);

        cin>>g;
         getline(cin,dummy);
        for(int j=0; j<g; j++)
        {
          //  cin>>scorecard[j];
            getline(cin,scorecard[j]);

        }

        for(int j=0; j<g; j++)
        {
            k=0;
            l=0;

            while(scorecard[j][k]!='#')
            {
                first.resize(l+1);
                first[l++]=scorecard[j][k++];

            }

            k++;
            l=0;

            while(scorecard[j][k]!='@')
            {
                home[l++]=scorecard[j][k++];
            }

            home[l]='\0';

            k++;
            l=0;

            while(scorecard[j][k]!='#')
            {
                away[l++]=scorecard[j][k++];
            }

            away[l]='\0';

            k++;

            l=0;

            while(scorecard[j][k]!='\0')
            {
                second.resize(l+1);

                second[l++]=scorecard[j][k++];

                //away.resize(l+1);

            }

            int hm,aw;

            hm=atoi(home);
            aw=atoi(away);

       //     cout<<first<<" "<<second/*<<" "<<hm<<" "<<aw*/<<endl;
            for(int z=0; z<t; z++)
            {
//                cout<<tem[z].name.compare(home);
//                cout<<endl<<tem[z].name<<" "<<home<<endl;
                if(!tem[z].name.compare(first))
                {
                    tem[z].goalF+=hm;
                    tem[z].goalA+=aw;

                    tem[z].play++;
                    if(hm>aw)
                    {
                        tem[z].point+=3;
                        tem[z].win++;
                    }
                    else if(aw>hm)
                    {
                        tem[z].loose++;
                    }
                    else
                    {
                        tem[z].point++;
                        tem[z].draw++;
                    }
                }

                else if(!tem[z].name.compare(second))
                {
                    tem[z].goalF+=aw;
                    tem[z].goalA+=hm;

                    tem[z].play++;

                    if(aw>hm)
                    {
                        tem[z].point+=3;
                        tem[z].win++;
                    }

                    else if(hm>aw)
                    {
                        tem[z].loose++;
                    }

                    else
                    {
                        tem[z].point++;
                        tem[z].draw++;
                    }

                }
            }
        }

        qsort(tem,t,sizeof(team),compare);

        cout<<title<<endl;
        for(int j=0; j<t; j++)
        {
            printf("%d) ",j+1);
            cout<<tem[j].name<<" ";
            printf("%dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",tem[j].point,tem[j].play,tem[j].win,tem[j].draw,tem[j].loose,(tem[j].goalF-tem[j].goalA),tem[j].goalF,tem[j].goalA);

        }

         if(i<n-1) printf("\n");
    }
    return 0;
}
