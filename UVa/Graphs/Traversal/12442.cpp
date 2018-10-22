#include<bits/stdc++.h>
using namespace std;
int n,t,test=1,u,v,cnt=0,mail[50001];
vector<int> adj[50001];
bool vis[50001];
int dfs(int vertex)
{	if(vis[vertex])
	return 0;
	vis[vertex]=true;
	int tmp=dfs(adj[vertex][0]);
	vis[vertex]=false;
	return 1+tmp;
}
void ini()
{
	for(int i=0;i<50001;i++)
	vis[i]=false;
}
int main()
{
	cin>>t;
	for(test=1;test<=t;test++)
	{	ini();
		cin>>n;
		for(int i=1;i<=n;i++)
		{	cin>>u>>v;
			adj[u].push_back(v);
		}
		int ma=INT_MIN;
		memset(mail,0,sizeof(mail));
		for(int i=1;i<=n;i++)
		{	memset(mail,0,sizeof(mail));ini();
			//if(vis[i]==false)
			{	cnt=0;//cout<<"starting at node "<<i<<"\n";
				mail[i]=dfs(i);
			}
			cout<<mail[i]<<" ";
		}
		/*int index=-1;
		for(int i=1;i<=n;i++)
		{	cout<<mail[i]<<" ";
			if(mail[i]>ma)
			{	ma=mail[i];
				index=i;
			}
		}*/
		cout<<"\n";
		cout<<"Case "<<test<<": "<<"\n";
	}
	return 0;
}
			
