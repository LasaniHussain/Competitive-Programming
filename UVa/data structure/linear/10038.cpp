#include<bits/stdc++.h>
using namespace std;
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	while(cin>>n)
	{	if(n==1)
		{
			int x;cin>>x;
			cout<<"Jolly\n";
		}
		else
		{
			int *arr=new int[n],hash[3000]={0},i;
			//memset(hash,0,sizeof(int)*3000);
			for(i=0;i<n;i++)
			{
				cin>>arr[i];
				if(i!=0)
				hash[abs(arr[i]-arr[i-1])]++;
			}
			for(i=1;i<n;i++)
			if(hash[i]!=1)
			break;
			if(i!=n)
			cout<<"Not jolly\n";
			else
			cout<<"Jolly\n";
		}
	}
	//cout<<"\n";
	return 0;
}
