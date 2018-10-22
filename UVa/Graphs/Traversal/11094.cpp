#include<bits/stdc++.h>
using namespace std;
char grid[20][20];
bool vis[20][20];
int m,n;
char land;
char dis[2];
int cnt;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ma,x,y;
void dfs(int r,int c)
{	//cout<<"inside dfs r = "<<r<<" c = "<<c<<"\n";
	/*if(r==x&&c==y)
	{	cout<<"returning due to r==x and c==y\n";
		cnt=0;
		return;
	}*/
	if(r<0||c<0||r==m||c==n||vis[r][c]||grid[r][c]!=land)
	return;
	vis[r][c]=true;
	//cout<<"inside valid call with r = "<<r<<" c = "<<c<<"\n"; 
	cnt++;
	if(c==n-1)
	dfs(r,0);
	if(c==0)
	{	//cout<<"c==0\n";	
		dfs(r,n-1);
	}
	for(int k=0;k<4;k++)
	dfs(r+dx[k],c+dy[k]);
}	
int main()
{
	while(cin>>m>>n)
	{	ma=0;memset(vis,false,sizeof(vis));
		//cout<<m<<" "<<n<<"\n";
		for(int i=0;i<m;i++)
		{	for(int j=0;j<n;j++)
			{
				cin>>grid[i][j];
				if(i==0&&j==0)
				dis[0]=grid[i][j];
				else
				{
					if(grid[i][j]!=dis[0])
					dis[1]=grid[i][j];
				}
			}
		}
		/*for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			cout<<grid[i][j]<<" ";
			cout<<"\n";
		}*/
		//int x,y;
		cin>>x>>y;
		land=grid[x][y];
		dfs(x,y);
		//cout<<"land "<<land<<" water "<<water<<"\n";
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(grid[i][j]==land)
				{	//cout<<"staring call at "<<i<<" "<<j<<"\n";
					cnt=0;
					//memset(vis,false,sizeof(vis));
					dfs(i,j);
					//cout<<"cnt = "<<cnt<<"\n";
					ma=max(ma,cnt);
				}
			}
		}
		cout<<ma<<"\n";
	}
	//cout<<"\n";
	return 0;
}
