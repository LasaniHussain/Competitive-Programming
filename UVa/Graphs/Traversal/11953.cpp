#include<bits/stdc++.h>
using namespace std;
int t,n;
char mat[101][101];
bool vis[101][101];
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
void dfs(int r,int c)
{
	if(r<0||r==n||c<0||c==n||mat[r][c]=='.'||vis[r][c])
	return;
	vis[r][c]=true;
	for(int i=0;i<4;i++)
		dfs(r+dr[i],c+dc[i]);
}	
int main()
{
	cin>>t;
	for(int test=1;test<=t;test++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>mat[i][j];
		memset(vis,false,sizeof(vis));
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(mat[i][j]=='x'&&!vis[i][j])
				{
					cnt++;
					dfs(i,j);
				}
			}
		}
		cout<<"Case "<<test<<": "<<cnt;
		if(test!=t)
		cout<<"\n";
	}
	cout<<"\n";
	return 0;
}
