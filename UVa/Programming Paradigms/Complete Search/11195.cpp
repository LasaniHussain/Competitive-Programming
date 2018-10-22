#include<bits/stdc++.h>
using namespace std;
int row[15],n,ans,t;
char board[15][15];
bool place(int r,int c)
{	if(board[r][c]=='*')
	return false;
	for(int pc=0;pc<c;pc++)
	if(row[pc]==r||(abs(row[pc]-r)==abs(pc-c)))
	return false;
	return true;
}
void backtrack(int c)
{
	if(c==n)
	ans++;
	for(int r=0;r<n;r++)
	if(place(r,c))
	{	row[c]=r;
		backtrack(c+1);
	}
}		
int main()
{	t=1;
	while(cin>>n&&n!=0)
	{	memset(board,0,sizeof(board));
		ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cin>>board[i][j];
		}
		backtrack(0);
		cout<<"Case "<<t++<<": "<<ans<<"\n";
	}
	return 0;
}
