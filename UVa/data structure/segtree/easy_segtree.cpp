#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct node
{
	int sum,pre,suf,res;
}tree[1000000]
void build(ll n)
{
	for(ll i=n-1;i>0;i--)
	{
		tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
		tree[i].pre=max(tree[i<<1].pre,tree[i<<1].sum+tree[i<<1|1].pre);
		tree[i].suf=max(tree[i<<1|1].suf,tree[i<<1|1].sum+tree[i<<1].suf);
		tree[i].res=max(tree[i<<1].suf+tree[i<<1|1].pre,max(tree[i<<1].res,tree[i<<1|1].res));
	}
}
void modify(int loc,int val,int n)
{	//loc+=n;
	for(t[loc+=n]=val;loc>1;loc>>=1)
	{
		t[loc>>1]=t[loc]+t[loc^1];
}
ll query(ll l,ll r,ll n)
{
	ll ans=INT_MIN;
	for(l+=n,r+=n;l<=r;l>>=1,r>>=1)
	{
		if(l&1)
		ans=max(ans,t[l++].res);
		if(!(r&1))
		ans=max(ans,t[r--].res);	
	}
	return res;
}
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{	int x;
		cin>>x;
		t[n+i].sum=t[n+1].pre=t[n+1].suf=t[n+1].res=x;
	}
	build(n);
	ll q;
	cin>>q;
	while(q--)
	{
		ll l,r;
		cin>>l>>r;
		cout<<"\n"<<query(l,r,n);
		cout<<"\n";
	}
	return 0;
}
