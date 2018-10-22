#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll t[1000000];
void build(ll n)
{
	for(ll i=n-1;i>0;i--)
	t[i]=t[i<<1]+t[i<<1|1];
}
ll query(ll loc,ll n)
{	//loc+=n;
	ll res=0;
	for(loc+=n;loc>0;loc>>=1)
	res+=t[loc];
	return res;
}
void modify(ll l,ll r,ll val,ll n)
{
	for(l+=n,r+=n;l<=r;l>>=1,r>>=1)
	{
		if(l&1)
		t[l++]+=val;
		if(!(r&1))
		t[r--]+=val;	
	}
}
void print_seg(ll n)
{
	for(ll i=1;i<2*n;i++)
	cout<<t[i]<<" ";
	cout<<"\n";
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
		print_seg(n);
		if(c=='q')
		{
			ll loc;
			cin>>loc;
			cout<<query(loc,n);	
		}
		else
		{
			ll l,r,val;
			cin>>l>>r>>val;
			modify(l,r,val,n);
		}
		
		if(q)
		cout<<"\n";
	}
	return 0;
}
