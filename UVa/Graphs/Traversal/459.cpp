#include<bits/stdc++.h>
using namespace std;
int adj['Z'+1]['Z'+1];
bool vis['Z'+1];
char n;
void dfs(char c)
{
	vis[c]=true;
	for(int j='A';j<=n;j++)
		if(adj[c][j]==1&&!vis[j])
			dfs(j);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		string str;
		getline(cin,str);
		memset(adj,0,sizeof(adj));
		memset(vis,0,sizeof(vis));
		while(getline(cin,str)&&str.length()!=0)
		{	
			adj[str[0]][str[1]]=1;
			adj[str[1]][str[0]]=1;
		}
		int sol=0;
		for(char c='A';c<=n;c++)
		{
			if(!vis[c])
			{
				sol++;
				dfs(c);
			}
		}
		cout<<sol<<"\n";
		if(t)
		cout<<"\n";
	}
	return 0;
}
	
			
		
