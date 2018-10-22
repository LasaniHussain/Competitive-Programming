#include<bits/stdc++.h>
using namespace std;
vector<string> grid;
int dr[]={1,1,0,-1,-1,-1,0,1};
int dc[]={0,1,1,1,0,-1,-1,-1};
bool vis[100][100];
int row,col,cnt;
void dfs(int r,int c)
{
	if(r<0||c<0||r==row||c==col||grid[r][c]=='L'||vis[r][c])
	return;
	vis[r][c]=true;
	cnt++;
	for(int i=0;i<8;i++)
		dfs(r+dr[i],c+dc[i]);
}	
int main()
{
	int t;
	cin>>t;
	string s;
	getline(cin,s);getline(cin,s);
	while(t--)
	{
		//string s;
		//getline(cin,s);
		//getline(cin,s);
		grid.clear();
		row=0,col=0;
		while(getline(cin,s)&&s.length()>0)
		{	
			if(s[0]=='L'||s[0]=='W')
			{	grid.push_back(s);
				//cout<<s<<"\n";
				row++;col=s.length();
			}
			else
			{
				int r,c;
				cnt=0;
				memset(vis,0,sizeof(vis));
				istringstream is(s);
				is>>r>>c;
				//cout<<r<<" "<<c<<"\n";
				//cin>>r>>c;
				dfs(r-1,c-1);
				cout<<cnt<<"\n";
			}
		}
		if(t)
		cout<<"\n";
	}
	return 0;
}
