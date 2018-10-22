#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[200009];
void ini()
{
	for(ll i=0;i<200009;i++)
	arr[i]=i;
}
ll root(ll a)
{
	while(arr[a]!=a)
	{
		arr[a]=arr[arr[a]];
		a=arr[a];
	}
	return a;
}
void _union(ll a,ll b)
{
	if(root(a)==root(b))
	return;
	else
	arr[root(a)]=arr[root(b)];
}
ll kruskal(vector<pair<ll,pair<ll,ll> > > &v)
{
	ll cost=0;
	for(auto c:v)
	{
		ll cst,x,y;
		cst=c.first;x=c.second.first;y=c.second.second;
		if(root(x)!=root(y))
		{
			cost+=cst;
			_union(x,y);
		}
	}
	return cost;
}
//vector<pair<ll,pair<ll,ll> > > adj[200001];
int main()
{
	ll m,n;
	while(true)
	{
		cin>>m>>n;
		if(m==0&&n==0)
		break;
		ll tot=0;
		vector<pair<ll,pair<ll,ll> > > adj(n);
		ll *arr=new ll[m];
		memset(arr,0,sizeof(arr));
		ini();
		for(ll i=0;i<n;i++)
		{
			ll x,y,cost;
			cin>>x>>y>>cost;
			tot+=cost;
			adj[i]=make_pair(cost,make_pair(x,y));
		}
		sort(adj.begin(),adj.end());
		cout<<tot-kruskal(adj)<<"\n";
	}
	return 0;
}
		
			
