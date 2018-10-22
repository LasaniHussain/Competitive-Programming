#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-7
int p,q,r,s,t,u;
double f(double x)
{
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF)
	{	
		if(f(0)*f(1)>0)
		cout<<"No solution";
		else
		{
			double l=0,r=1;
			while(r-l>0.0000001)
			{
				double mid=(l+r)/2;
				if(f(l)*f(mid)<=0)
				r=mid;
				else
				l=mid;
			}
			printf("%.4lf",(l+r)/2);
		}
		cout<<"\n";
	}
	return 0;
}
		
