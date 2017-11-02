
#include<bits/stdc++.h>

double my_sqrt(double a,double f,double e)
{
    double temp=(f+e)/2.0;
    printf("%lf %lf %lf %lf\n",f,e,temp,temp*temp-a);
    if(abs(e-f)<0.00000000001)
    {
        printf("%lf\n",temp);
        return temp;
    }
    else if((temp*temp)>a)  my_sqrt(a,f,temp);
    else  my_sqrt(a,temp,e);

}

double mysqrt(double X){
  double low=0.0;
  double high=X;
    double mid;
  while (high-low>.0001){
		mid=(low+high)/2;
	//	print low, high, mid, mid*mid
		if (mid*mid>X)
			high=mid;
		else
			low=mid;
  }

        return mid;

}

int main()
{

    printf("%lf",my_sqrt(36.0,0,36));
    return 0;

}

