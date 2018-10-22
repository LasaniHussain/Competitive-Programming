#include<bits/stdc++.h>
using namespace std;
int arr[200009]={0};
void build(int n)
{
	for(int i=n-1;i>0;i--)
	arr[i]=max(arr[i<<1],arr[i<<1|1]);
}
int query(int l,int r,int n)
{
	int res=INT_MIN;
	for(l+=n,r+=n;l<=r;l>>=1,r>>=1)
	{
		if(l&1)
		res=max(res,arr[l++]);
		if(!(r&1))
		res=max(res,arr[r--]);
	}
	return res;
}
int main()
{
	int n;
	cin>>n;
	//memset(sizeof(arr
	for(int i=0;i<n;i++)
	cin>>arr[n+i];
	build(n);
	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<query(--l,--r,n);
		if(q)
		cout<<"\n";
	}
	return 0;
}
