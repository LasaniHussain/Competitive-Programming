#include<bits/stdc++.h>
using namespace std;
int n,k;
bitset<101> colored;
char color[101];
vector<int> adj[101];
vector<int> sol;
int black;
void backtrack(int v)
{	//cout<<"backtrack "<<v<<"\n";	
	if(v==n+1)
	{
		int b=0;
		for(int i=1;i<=n;i++)
		if(color[i]=='b')
		b++;
		if(b>=black)
		{
			black=b;
			sol.clear();
			for(int i=1;i<=n;i++)
			if(color[i]=='b')
			sol.push_back(i);
			/*for(auto c:sol)
			cout<<c<<" ";
			cout<<"\n";*/
		}
		return;
	}
	bool bl=true;
	for(int i=0;i<adj[v].size();i++)
	{	//cout<<adj[v][i]<<" ";
		if(colored[adj[v][i]]&&color[adj[v][i]]=='b')
		{
			bl=false;
			break;
		}
	}
	//cout<<"\n";
	colored.set(v);
	if(bl)
	{	//cout<<"node "<<v<<" assigned black\n";
		color[v]='b';
		backtrack(v+1);
	}
	//cout<<"node "<<v<<" assigned white\n";
	color[v]='w';
	backtrack(v+1);
	colored.reset(v);
}
void printGraph()
{
	for(int i=1;i<=n;i++)
	{	cout<<i<<"----> ";
		for(int j=0;j<adj[i].size();j++)
		cout<<adj[i][j]<<"\t";
		cout<<"\n";
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		memset(adj,0,sizeof(adj));
		//memset(colored,false,sizeof(color));
		colored.reset();
		memset(color,'b',sizeof(color));
		//cout<<colored[0]<<" "<<color[0]<<"\n";
		for(int i=0;i<k;i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		black=-1;
		backtrack(1);
		//printGraph();
		/*if(backtrack(1))
		cout<<"Solution\n";
		else
		cout<<"No solution\n";
		cout<<"Node\tColor\n";
		for(int i=1;i<=n;i++)
		cout<<i<<"\t\t"<<color[i]<<"\n";*/
		cout<<black<<"\n";
		for(int i=0;i<sol.size();i++)
		{
			cout<<sol[i];
			if(i!=sol.size()-1)
			cout<<" ";//if(color[i]=='b')	
		}	
		if(t)
		cout<<"\n";
	}
	return 0;
}




/*#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef std::vector<int> vi;
typedef std::vector<pair<int, int> > vii;
//----------Main source code -----------------//
bitset<101> colored;
vector<vi> adj;
char color[101];
int n, ans;
vi ansL;
void rcr_bkt(int i){
	//-----ending the recursion----//
	if(i==n){
		int b=0;
		for(int c=0;c<n;c++)
			if(color[c]=='b') b++;
		if(b>ans){
			ans=b;
			ansL.clear();
			for(int c=0;c<n;c++)
			if(color[c]=='b') ansL.push_back(c);
		}
		return;
	}
	//-----------------------------//

	//check if it can be colored black
	bool black = true;
	for(vi::iterator it=adj[i].begin();it!=adj[i].end();it++)
		if(colored[*it]&&color[*it]=='b'){
			black = false;
			break;
		}

	//color one by one
	colored.set(i);
	if(black){
		//color node black
		color[i]='b';
		rcr_bkt(i+1);
	}
	//white
	color[i]='w';
	rcr_bkt(i+1);

	colored.reset(i); //reset colored to retain previous state

}
int main() {
	int t, k, a, b;
	cin >> t;
	while(t--){
		cin>>n>>k;
		adj.assign(n, vi());
		colored.reset();
		ans=-1;
		while(k--){
			cin >> a>> b;
			adj[--a].push_back(--b);
			adj[b].push_back(a);
		}
		std::fill_n(color, 101, 'b');
		rcr_bkt(0);
		cout<<ans<<endl;
		for(vi::iterator i=ansL.begin();i!=ansL.end()-1;i++)
			cout<<*i+1<<" ";
		if(ans>0)cout<<*(ansL.end()-1)+1;
		
		cout<<endl;
	}
	return 0;
}*/
