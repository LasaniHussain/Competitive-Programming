#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ll n;
	while(cin>>n)
	{	if(n==0)
		break;
		priority_queue<ll,vector<ll>,greater<ll> > pq;
		ll i;
		for(i=0;i<n;i++)
		{
			ll x;
			cin>>x;
			pq.push(x);
		}
		ll c=0;
		for(i=0;i<n-1;i++)
		{	//cout<<"iteration : "<<i<<"\t";
			ll x=pq.top();
			//cout<<"x = "<<x;
			pq.pop();
			ll y=pq.top();
			//cout<<" y = "<<y<<"\n";
			pq.pop();
			c+=(x+y);
			pq.push(x+y);
		}
		cout<<c<<"\n";
	}
	return 0;
}
