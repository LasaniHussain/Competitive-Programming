#include<bits/stdc++.h>
using namespace std;
int grid[500][500];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>grid[i][j];
				grid[i+n][j]=grid[i][j+n]=grid[i+n][j+n]=grid[i][j];
			}
		}
		for(int i=0;i<2*n;i++)
		{
			for(int j=0;j<2*n;j++)
			{
				//cout<<grid[i][j]<<" ";
				//cout<<"\n";
				if(i>0)
				grid[i][j]+=grid[i-1][j];
				if(j>0)
				grid[i][j]+=grid[i][j-1];
				if(i>0&&j>0)
				grid[i][j]-=grid[i-1][j-1];
			}
			//cout<<"\n";
		}
		int s=0,ma=INT_MIN;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=i;k<i+n;k++)
				{
					for(int l=j;l<j+n;l++)
					{
						s=grid[k][l];
						if(i>0)
						s-=grid[i-1][l];
						if(j>0)
						s-=grid[k][j-1];
						if(i>0&&j>0)
						s+=grid[i-1][j-1];
						ma=max(ma,s);
					}
				}
			}
		}
		cout<<ma;
		//if(t)
		cout<<"\n";
	}
	return 0;
}
