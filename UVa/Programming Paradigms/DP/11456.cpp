#include<bits/stdc++.h>
using namespace std;
int lis[2001];
int lds[2001];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int *arr=new int[n];
		//int *lis=new int[n];
		//int *lds=new int[n];
		fill_n(lis,n,1);
		fill_n(lds,n,1);
		for(int i=0;i<n;i++)
		cin>>arr[i];
		//reverse(arr,arr+n);
		for(int i=n-1;i>=0;i--)
		{
			for(int j=i;j<n;j++)
			{
				if(arr[i]<arr[j])
				lis[i]=max(lis[i],lis[j]+1);
				else if(arr[i]>arr[j])
				lds[i]=max(lds[i],lds[j]+1);
			}
		}
		/*for(int i=0;i<n;i++)
		cout<<lis[i]<<" ";
		cout<<"\n";
		for(int i=0;i<n;i++)
		cout<<lds[i]<<" ";
		cout<<"\n";*/
		int ans=0;
		for(int i=0;i<n;i++)
		ans=max(ans,lis[i]+lds[i]-1);
		cout<<ans;
		//if(t)
		cout<<"\n";
	}
	return 0;
}
		
