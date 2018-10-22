#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll t[1000000];
void build(ll n)
{
	for(ll i=n-1;i>0;i--)
	t[i]=t[i<<1]*t[i<<1|1];
}
ll query(ll l,ll r,ll n)
{
	ll res=1;
	for(l+=n,r+=n;l<=r;l>>=1,r>>=1)
	{
		if(l&1)
		res*=t[l++];
		if(!(r&1))
		res*=t[r--];
	}
	return res;
}
void update(ll loc,ll val,ll n)
{
	for(t[loc+=n]=val;loc>1;loc>>=1)
	t[loc>>1]=t[loc]*t[loc^1];
}
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ll n,q;
	while(scanf("%lld %lld",&n,&q)!=EOF)
	{
		ll i;
		for(i=0;i<n;i++)
		{
			ll x;
			cin>>x;
			if(x>0)
			t[n+i]=1;
			else if(x<0)
			t[n+i]=-1;
			else
			t[n+i]=0;
		}
		build(n);
		//for(i=1;i<2*n;i++)
		//cout<<t[i]<<" ";
		//cout<<"\n";
		while(q--)
		{
			char c;
			cin>>c;
			if(c=='P')
			{
				ll l,r;
				cin>>l>>r;
				ll res=query(l-1,r-1,n);
				//cout<<res<<"\n";
				if(res>0)
				cout<<"+";
				else if(res<0)
				cout<<"-";
				else
				cout<<"0";
			}
			else
			{
				ll loc,val;
				cin>>loc>>val;
				if(val>0)
				val=1;
				else if(val<0)
				val=-1;
				update(loc-1,val,n);
			}
		}
		cout<<"\n";
	}
	return 0;
}
