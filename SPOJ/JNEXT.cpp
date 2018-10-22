#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{	//freopen("in.txt","r",stdin);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,i;
		cin>>n;
		ll *arr=new ll[n];
		for(i=0;i<n;i++)
		cin>>arr[i];
		if(next_permutation(arr,arr+n))
		{
			for(i=0;i<n;i++)
			cout<<arr[i];
		}	
		else
		cout<<"-1";
		if(t)
		cout<<"\n";
	}
	return 0;
}
