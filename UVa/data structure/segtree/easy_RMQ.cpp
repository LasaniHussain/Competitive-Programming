#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll t[1000000];
void build(ll n)
{
	for(ll i=n-1;i>0;i--)
	t[i]=min(t[i<<1],t[i<<1|1]);
}
void modify(int loc,int val,int n)
{	//loc+=n;
	for(t[loc+=n]=val;loc>1;loc>>=1)
	t[loc>>1]=min(t[loc],t[loc^1]);
}
ll query(ll l,ll r,ll n)
{
	ll res=LONG_MAX;
	for(l+=n,r+=n;l<=r;l>>=1,r>>=1)
	{
		if(l&1)
		res=min(t[l++],res);
		if(!(r&1))
		res=min(t[r--],res);	
	}
	return res;
}
int main()
{	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ll n,i,q;
	cin>>n>>q;
	for(i=0;i<n;i++)
	cin>>t[n+i];
	build(n);
	while(q--)
	{	char c;
		cin>>c;
		if(c=='q')
		{
			ll l,r;
			cin>>l>>r;
			cout<<"\n"<<query(l,r,n);	
		}
		else
		{
			ll loc,val;
			cin>>loc>>val;
			modify(loc,val,n);
		}
		if(q)
		cout<<"\n";
	}
	return 0;
}
