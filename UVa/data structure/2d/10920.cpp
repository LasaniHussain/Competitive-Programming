#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll sz,p,n,m,c,d,x,y;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(true)
	{
		cin>>sz>>p;
		if(sz==0&&p==0)
		break;
		if(sqrt(p)-int(sqrt(p))>pow(10,-5))
		{	m=int(sqrt(p));
			if(m%2==1)
			m+=2;
			else
			m+=1;
		}
		else
		{
			m=int(sqrt(p));
			if(m%2==0)
			m+=1;
		}
		
		n=sz;
		c=n/2+m/2+1;
		//cout<<"m = "<<m<<" c= "<<c<<"\n";
		if(p==m*m)
		{
			x=c;y=c;
		}
		else if(p==(m*m-m+1))
		{
			x=c-m+1;y=c;	
		}
		else if(p==(m*m-2*(m-1)))
		{
			x=c-m+1;y=c-m+1;	
		}
		else if(p==(m*m-3*(m-1)))
		{
			x=c;y=c-m+1;	
		}
		else
		{
			if(p<=(m*m-3*(m-1)-1)&&p>=(m*m-4*(m-1)+1))
			{
				d=(m*m-3*(m-1))-p;
				x=c;y=c-m+1+d;
			}
			else if(p<=(m*m-2*(m-1)-1)&&p>=(m*m-3*(m-1)+1))
			{
				d=(m*m-2*(m-1))-p;
				x=c-m+1+d;y=c-m+1;
			}
			else if(p<=(m*m-(m-1)-1)&&p>=(m*m-2*(m-1)+1))
			{
				d=(m*m-(m-1))-p;
				x=c-m+1;y=c-d;
			}
			else
			{
				d=m*m-p;
				x=c-d;y=c;
			}
		}
		cout<<"Line = "<<x<<", "<<"column = "<<y<<"."<<"\n";
	}
	//cout<<"\n";
	return 0;
}
