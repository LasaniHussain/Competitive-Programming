#include<bits/stdc++.h>
using namespace std;
int t,n,adj[101][101],cal;char sol[101][101];
vector<set<int> > st(101);
bool ini;
bool vis[101];
set<int> initial;
void dfs(int s)
{	//cout<<"dfs("<<s<<")\n";
	if(ini==true)
	initial.insert(s);
	else
	st[cal].insert(s);
	vis[s]=true;
	if(ini==false&&s==cal)
	{	//cout<<"returning\n";
		return;
	}
	for(int i=0;i<n;i++)
	{	/*cout<<s<<" "<<i<<" "<<adj[s][i]<<" ";
		if(vis[adj[s][i]]==true)
		cout<<"T";
		else
		cout<<"F";
		cout<<"\n";*/
		if(adj[s][i]==1&&!vis[i])
		dfs(i);
	}
}
int main()
{
	cin>>t;
	for(int test=1;test<=t;test++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cin>>adj[i][j];
		}
		memset(vis,0,sizeof(vis));
		/*for(int i=0;i<n;i++)
		if(vis[i]==true)
		cout<<'T'<<" ";
		else
		cout<<'F'<<" ";
		cout<<"\n";*/
		initial.clear();
		ini=true;
		cal=0;
		dfs(0);
		ini=false;
		for(cal=0;cal<n;cal++)
		{	st[cal].clear();
			memset(vis,0,sizeof(vis));
			dfs(0);
			/*for(int i=0;i<n;i++)
			{
				if(init.find(i)==init.end()||(init.find(i)!=init.end()&&st[cal].find(i)!=st[cal].end()))
				sol[cal][i]='N';
				else
				sol[ca][i]='Y';
			}*/
		}
		for(int i=0;i<n;i++)
		{	for(int j=0;j<n;j++)
			{	if(i==j)
				sol[i][j]='Y';
				else
				sol[i][j]='N';
			}
		}
		for(int i=0;i<n;i++)
		{
			if(initial.find(i)==initial.end())
			{
				for(int j=0;j<n;j++)
				sol[j][i]='N';
			}
		}
		for(int i=0;i<n;i++)
		{	
			for(auto it=initial.begin();it!=initial.end();it++)
			{	
				if(st[i].find(*it)==st[i].end())
				sol[i][*it]='Y';
			}
		}
		cout<<"Case "<<test<<":\n";
		cout<<"+";
		for(int i=0;i<2*n-1;i++)
		cout<<"-";
		cout<<"+\n";
		for(int i=0;i<n;i++)
		{	cout<<"|";
			for(int j=0;j<n;j++)
			cout<<sol[i][j]<<"|";
			cout<<"\n+";
			for(int k=0;k<2*n-1;k++)
			cout<<"-";
			cout<<"+";
			cout<<"\n";
		}
		/*cout<<"\n";
		cout<<"inital set : ";
		for(auto c:initial)
		cout<<c<<" ";
		cout<<"\n";
		for(int i=0;i<n;i++)
		{	cout<<"after turning off node "<<i<<" : ";
			for(auto c:st[i])
			cout<<c<<" ";
			cout<<"\n";
		}*/
	}
	return 0;
}			
