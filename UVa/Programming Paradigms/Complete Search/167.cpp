#include<bits/stdc++.h>
using namespace std;
int row[8],board[8][8],t,ans;
bool place(int r,int c)
{
	for(int pc=0;pc<c;pc++)
	if(row[pc]==r||(abs(row[pc]-r)==abs(pc-c)))
	return false;
	return true;
}
/*void printsol()
{
	int mat[8][8]={0};
	for(int i=0;i<8;i++)
	mat[row[i]][i]=1;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		cout<<mat[i][j]<<" ";
		cout<<"\n";
	}
}		*/
void backtrack(int c)
{	
	if(c==8)
	{	int score=0;
		for(int i=0;i<8;i++)
		score+=board[row[i]][i];
		ans=max(ans,score);
		//cout<<"Sol "<<line++<<"\n";	
		//printsol();
		//for(auto it:row)
		//cout<<it<<" ";
		//cout<<"\n";
	}
		//cout<<"\n";
	for(int r=0;r<8;r++)
	if(place(r,c))
	{	row[c]=r;
		//cout<<"\ncalling with c= "<<c+1<<"\n";
		backtrack(c+1);
	}
}		
int main()
{
	cin>>t;;
	while(t--)
	{	
		memset(row,0,sizeof(row));
		memset(board,0,sizeof(board));
		for(int i=0;i<8;i++)
		{	for(int j=0;j<8;j++)
			cin>>board[i][j];
		}
		ans=INT_MIN;
		backtrack(0);
		cout<<setw(5)<<ans<<"\n";
	}
	return 0;
}
