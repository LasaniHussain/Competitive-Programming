#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll t[1000000];
void build(ll n)
{
	for(ll i=n-1;i>0;i--)
	t[i]=t[i<<1]+t[i<<1|1];
}
void modify(int loc,int val,int n)
{	//loc+=n;
	for(t[loc+=n]=val;loc>1;loc>>=1)
	t[loc>>1]=t[loc]+t[loc^1];
}
ll query(ll l,ll r,ll n)
{
	ll res=0;
	for(l+=n,r+=n;l<=r;l>>=1,r>>=1)
	{
		if(l&1)
		res+=t[l++];
		if(!(r&1))
		res+=t[r--];	
	}
	return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ll n,cnt=1;
	while(scanf("%lld",&n),n)
	{
		ll i;
		for(i=0;i<n;i++)
		scanf("%lld",&t[n+i]);
		build(n);
		char s[4];
		if(cnt!=1)
		printf("\n");
		printf("Case %lld:\n",cnt++);
		while(scanf("%s",s),strcmp(s,"END")!=0)
		{
			if(strcmp(s,"S")==0)
			{
				ll loc,val;
				scanf("%lld %lld",&loc,&val);
				modify(loc-1,val,n);
			}
			else
			{	ll l,r;
				scanf("%lld %lld",&l,&r);
				printf("%lld\n",query(l-1,r-1,n));
			}
		}
	}
	return 0;
}
