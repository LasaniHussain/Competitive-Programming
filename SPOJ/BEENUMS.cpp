#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{	freopen("in.txt","r",stdin);
	int n;
	while(cin>>n&&n!=-1)
	{
		if(n%2==0)
		cout<<"N";
		else
		{	n--;
			if(n%3!=0)
			cout<<"N";
			else
			{
				n/=3;
				n=4*n+1;
				double sq=sqrt(n);
				if(sq-int(sq)>0)
				cout<<"N";
				else
				cout<<"Y";
			}
		}
		cout<<"\n";
	}
	return 0;
}
	
