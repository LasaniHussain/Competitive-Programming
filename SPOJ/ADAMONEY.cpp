#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
void multiply(ll A[5][5],ll B[5][5])
{
	ll tmp[5][5]={0};
	for(ll i=0;i<5;i++)
	{
		for(ll j=0;j<5;j++)
		{
			for(ll k=0;k<5;k++)
			tmp[i][j]=(tmp[i][j]+(A[i][k]*B[k][j])%mod)%mod;
		}
	}
	for(ll i=0;i<5;i++)
	{
		for(ll j=0;j<5;j++)
		A[i][j]=tmp[i][j];
	}
}
void power(ll M[5][5],ll n)
{
	ll result[5][5]={0};
	for(ll i=0;i<5;i++)
	result[i][i]=1;
	while(n>0)
	{
		if(n%2)
		multiply(result,M);
		multiply(M,M);
		n=n/2;
	}
	for(ll i=0;i<5;i++)
	{
		for(ll j=0;j<5;j++)
		M[i][j]=result[i][j];
	}
}	
ll solve(ll arr[5],ll n)
{
	ll M[5][5]={{0,0,0,0,1},{1,0,0,0,5},{0,1,0,0,0},{0,0,1,0,2},{0,0,0,1,1}};
	power(M,n);
	ll result=0;
	for(ll i=0;i<5;i++)
		result=(result+(arr[i]*M[i][4])%mod)%mod;
	return result;
}
int main()
{	freopen("in.txt","r",stdin);
	ll t;
	cin>>t;
	while(t--)
	{
		ll t0,t1,t2,t3,t4,n;
		cin>>t0>>t1>>t2>>t3>>t4>>n;
		if(n==0)
		cout<<t0;
		else if(n==1)
		cout<<t1;
		else if(n==2)
		cout<<t2;
		else if(n==3)
		cout<<t3;
		else if(n==4)
		cout<<t4;
		else
		{	ll *arr=new ll[5];
			arr[0]=t0,arr[1]=t1,arr[2]=t2,arr[3]=t3,arr[4]=t4;
			ll ans=solve(arr,n-4);
			cout<<ans;
		}
		if(t)
		cout<<"\n";
	}
	return 0;
}
