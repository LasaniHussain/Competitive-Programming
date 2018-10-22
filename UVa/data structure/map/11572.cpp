#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		map<ll,ll> mp;
		while(n--)
		{
			ll x;
			cin>>x;
			mp[x]++;
		}
		for(auto c:mp)
		cout<<c.first<<" "<<c.second<<"\n";
	}
	return 0;
}
