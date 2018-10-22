#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll> > v(1000001);
void init()
{
	for(ll i=0;i<1000001;i++)
	v[i].clear();
}
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ll n,m;
	while(scanf("%lld %lld",&n,&m)!=EOF)
	{
		ll i;
		init();
		for(i=0;i<n;i++)
		{
			ll x;
			cin>>x;
			//cout<<x;
			v[x].push_back(i+1);
		}
		/*cout<<"\n";
		for(i=1;i<5;i++)
		{	cout<<"i = "<<i<<"\t";
			for(auto c:v[i])
			cout<<c<<" ";
			cout<<"\n";
		}*/
		while(m--)
		{
			ll k,ele;
			cin>>k>>ele;
			if(k>v[ele].size())
			cout<<"0\n";
			else
			cout<<v[ele][k-1]<<"\n";
		}
		//cout<<"\n";
	}
	return 0;
}
