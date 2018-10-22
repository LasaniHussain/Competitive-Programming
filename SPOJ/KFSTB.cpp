#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
vector<int> adj[10001];
bool vis[10001];
int ways[10001];
int s,t;
int dfs(int s)
{	//cout<<"visited "<<s<<"\n";
	if(s==t)
	return 1;
	if(ways[s]!=-1)
	return ways[s];
	int res=0;
	for(int i=0;i<adj[s].size();i++)
	{
		//ways[adj[s][i]]=(ways[adj[s][i]]+1)%mod;
		res+=dfs(adj[s][i]);
		res%=mod;
	}
	ways[s]=res;
	return ways[s];
}
int main()
{
	int d;
	cin>>d;
	while(d--)
	{
		int c,b;
		cin>>c>>b>>s>>t;
		for(int i=1;i<=c;i++)
		adj[i].clear();
		for(int i=0;i<b;i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
		}
		memset(vis,false,sizeof(vis));
		memset(ways,-1,sizeof(ways));
		int ans=dfs(s);		
		cout<<ans;
		if(d)
		cout<<"\n";
	}
	return 0;
} 
