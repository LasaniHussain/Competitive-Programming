#include<bits/stdc++.h>
using namespace std;
vector<int> adj[301];
int color[301];
bool isBipartite(int s)
{	//cout<<"inside bfs with s= "<<s<<"\n";
	color[s]=0;
	bool bipartite=true;
	queue<int> q;
	q.push(s);
	while(!q.empty()&&bipartite)
	{
		int v=q.front();
		q.pop();
		for(int i=0;i<adj[v].size();i++)
		{
			if(color[adj[v][i]]==-1)
			{
				color[adj[v][i]]=1-color[v];
				q.push(adj[v][i]);
			}
			else if(color[adj[v][i]]==color[v])
			{
				bipartite=false;
				break;
			}
		}
	}
	return bipartite;
}	
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		for(int i=1;i<=n;i++)
		adj[i].clear();
		int x,y;
		while(cin>>x>>y&&x!=0&&y!=0)
		{
			adj[x].push_back(y);
			adj[y].push_back(x);
			//cout<<x<<" "<<y<<"\n";
		}
		/*cout<<"adjacency list\n";
		for(int i=1;i<=n;i++)
		{
			cout<<i<<"---->";
			for(int j=0;j<adj[i].size();j++)
			cout<<adj[i][j]<<",";
			cout<<"\n";
		}*/
		memset(color,-1,sizeof(color));
		if(isBipartite(1))
		cout<<"YES";
		else
		cout<<"NO";
		cout<<"\n";
		/*cout<<"Node\t"<<"Color\n";
		for(int i=1;i<=n;i++)
		cout<<i<<"\t"<<color[i]<<"\n";*/
	}
	return 0;
}
	
