#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ll n;
	while(cin>>n)
	{
		if(n==0)
		break;
		map<map<ll,ll>,ll> vmap;
		while(n--)
		{	ll x;
			map<ll,ll> mp;
			for(int i=0;i<5;i++)
			{
				cin>>x;
				//cout<<x<<" ";
				mp[x]++;	
			}
			//cout<<"\n";
			vmap[mp]++;
		}
		ll mi=0;
		for(auto c:vmap)
		mi=max(mi,c.second);
		ll count=0;
		for(auto c:vmap)
		if(c.second==mi)
		count+=mi;
		//ll mi=0;
		/*for(ll i=0;i<vmap.size()-1;i++)
		{	ll c=1;
			for(ll j=i+1;j<vmap.size();j++)
			{
				if(vmap[i]==vmap[j])
				c++;
			}
			mi=max(mi,c);
		}*/
		/*for(ll i=0;i<vmap.size();i++)
		{
			for(auto c:vmap[i])
			cout<<c.first<<" "<<c.second<<"\n";
			cout<<"\n";
		}*/
		//cout<<mi<<"\n";
		//cout<<"\n";
		cout<<count<<"\n";
	}
	return 0;
}
