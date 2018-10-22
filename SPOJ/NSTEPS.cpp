#include<bits/stdc++.h>
using namespace std;
int main()
{	freopen("in.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		if(x==y||y+2==x)
		{	if(x%2==0)
			cout<<x+y;
			else
			cout<<x+y-1;
		}
		else
		{
			cout<<"No Number";
		}
		if(t)
		cout<<"\n";
	}
	return 0;
}
