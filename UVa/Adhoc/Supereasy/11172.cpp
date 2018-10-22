#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		if(a<b)
		cout<<"<";
		else if(a==b)
		cout<<"=";
		else
		cout<<">";
		cout<<"\n";
	}
	cout<<"\n";
	return 0;
}
