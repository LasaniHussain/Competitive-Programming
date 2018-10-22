#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll p1,p2,p3,p4;
	for(p1=1;p1<2000;p1++)
	{
		for(p2=1;p2<2000;p2++)
		{
			for(p3=1;p3<2000;p3++)
			{
				for(p4=1;p4<2000;p4++)
				{		
					if((p1+p2+p3+p4)==2000&&(p1*p2*p3*p4==2000000000))
					cout<<double(p1)/100<<" "<<double(p2)/100<<" "<<double(p3)/100<<" "<<double(p4)/100<<"\n";
				}
			}
		}
	}
	return 0;
}
