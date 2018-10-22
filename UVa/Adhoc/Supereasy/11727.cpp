#include<bits/stdc++.h>
using namespace std;
int main()
{	freopen("in.txt","r",stdin);
	int t,*arr=new int[3],i;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		for(i=0;i<3;i++)
		cin>>arr[i];
		sort(arr,arr+3);
		cout<<"Case "<<j<<": "<<arr[1];
		cout<<"\n";
	}
	return 0;
}
