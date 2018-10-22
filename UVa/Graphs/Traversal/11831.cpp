#include<bits/stdc++.h>
using namespace std;
char grid[101][101];
bool check(int i,int j,int n,int m)
{
	if(i>=0&&i<n&&j>=0&&j<m&&grid[i][j]!='#')
	return true;
	return false;
}
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m,i,j,s,c_x,c_y,c,n_x,n_y;
	char face;
	while(scanf("%d %d %d",&n,&m,&s)&&n&&m&&s)
	{	memset(grid,0,sizeof(grid));
		c=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{	cin>>grid[i][j];
				if(grid[i][j]=='N'||grid[i][j]=='S'||grid[i][j]=='L'||grid[i][j]=='O')
				{
					c_x=i;c_y=j;
					face=grid[i][j];
				}
			}
		}	
		string st;
		cin>>st;
		for(i=0;i<s;i++)
		{
			if(st[i]=='D')
			{
				if(face=='N')	face='L';
				else if(face=='L')	face='S';
				else if(face=='S')	face='O';
				else	face='N';
			}
			else if(st[i]=='E')
			{
				if(face=='N')	face='O';
				else if(face=='L')	face='N';
				else if(face=='S')	face='L';
				else	face='S';
			}
			else
			{
				n_x=c_x;n_y=c_y;
				if(face=='N')	n_x--;
				else if(face=='L')	n_y++;
				else if(face=='S')	n_x++;
				else	n_y--;
				if(check(n_x,n_y,n,m))
				{
					if(grid[n_x][n_y]=='*')
					{
						c++;
						grid[n_x][n_y]='.';
					}
					c_x=n_x;c_y=n_y;
				}
			}
		}
		cout<<c<<"\n";
	}
	return 0;
}			
