#include<bits/stdc++.h>
using namespace std;
char arr[1001][1001];
int dist[1001][1001];
bool vis[1001][1001];
int n,m;
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
bool valid(int i,int j)
{
	if(arr[i][j]=='#'||vis[i][j]||i<0||j<0||i>=m||j>=n)
	return false;
	return true;
}
void bfs(int i,int j)
{	//cout<<"inside bfs\n";
	dist[i][j]=0;vis[i][j]=true;
	queue<pair<int,int> > q;
	q.push(make_pair(i,j));
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		for(int d=0;d<4;d++)
		{
			int newi=p.first+dr[d],newj=p.second+dc[d];
			if(valid(newi,newj))
			{	//cout<<"processing "<<newi<<" "<<newj<<"\n";
				q.push(make_pair(newi,newj));
				vis[newi][newj]=true;
				dist[newi][newj]=dist[p.first][p.second]+1;
			}
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	
		cin>>n>>m;
		//cout<<m<<" "<<n<<"\n";
		int posi=-1,posj=-1;
		memset(dist,-1,sizeof(dist));
		memset(vis,false,sizeof(vis));
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{	cin>>arr[i][j];
				if(arr[i][j]=='.'&&posi==-1)
				{
					posi=i;posj=j;
				}
			}
		}
		/*for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
			cout<<"\n";
		}*/
		bfs(posi,posj);
		int dis=-1,maxi=-1,maxj=-1;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(dist[i][j]>dis)
				{
					dis=dist[i][j];
					maxi=i,maxj=j;
				}
			}
		}
		memset(dist,-1,sizeof(dist));
		memset(vis,false,sizeof(vis));
		bfs(maxi,maxj);
		int ans=-1;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				ans=max(ans,dist[i][j]);
			}
		}
		cout<<"Maximum rope length is "<<ans<<".";
		if(t)	
		cout<<"\n";
	}
	return 0;
}
		
