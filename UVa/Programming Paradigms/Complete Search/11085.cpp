#include<bits/stdc++.h>
using namespace std;
int row[8],queen[8],t,ans;
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
	{	int dist=0;
		for(int i=0;i<8;i++)
		if(row[i]!=queen[i])
		dist++;
		ans=min(ans,dist);
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
	t=1;
	while(scanf("%d %d %d %d %d %d %d %d",&queen[0],&queen[1],&queen[2],&queen[3],&queen[4],&queen[5],&queen[6],&queen[7])==8)
	{	//cin>>a>>b;
		//a--;b--;
		//cout<<queen[0]<<queen[1]<<queen[2]<<queen[3]<<queen[4]<<queen[5]<<queen[6]<<queen[7]<<"\n";
		queen[0]--;queen[1]--;queen[2]--;queen[3]--;queen[4]--;queen[5]--;queen[6]--;queen[7]--;
		memset(row,0,sizeof(row));
		ans=INT_MAX;
		backtrack(0);
		cout<<"Case "<<t++<<": "<<ans<<"\n";
	}
	return 0;
}
