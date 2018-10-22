#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
bool vis[10001];
bool bfs(int s,int n)
{
	queue<int> q;
	q.push(s);
	vis[s]=true;
	int c=0;
	while(!q.empty())
	{
		
		int v=q.front();
		q.pop();
		//vis[v]=true;
		for(int i=0;i<adj[v].size();i++)
		{
			if(vis[adj[v][i]])
			return false;
			else
			{
				vis[adj[v][i]]=true;
				q.push(adj[v][i]);
			}
		}
		c++;
	}
	if(c!=n)
	return false;
	else
	return true;
}		
int main()
{
	freopen("in.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{	int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		//adj[y].push_back(x);
	}
	memset(vis,false,sizeof(vis));
	if(bfs(1,n)==true)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}
