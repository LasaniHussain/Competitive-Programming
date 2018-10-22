#include<bits/stdc++.h>
using namespace std;
int arr[100][100];
int main()
{	
	int n;
	while(cin>>n)
	{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
			if(i>0)
			arr[i][j]+=arr[i-1][j];
			if(j>0)
			arr[i][j]+=arr[i][j-1];
			if(i>0&&j>0)
			arr[i][j]-=arr[i-1][j-1];
		}
	}
	int s=0,ma=-128;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=i;k<n;k++)
			{
				for(int l=j;l<n;l++)
				{	s=arr[k][l];
					if(i>0)
					s-=arr[i-1][l];
					if(j>0)
					s-=arr[k][j-1];
					if(i>0&&j>0)
					s+=arr[i-1][j-1];
					ma=max(ma,s);
				}
			}
		}
	}
	cout<<ma<<"\n";
	}
	return 0;
}
