#include<bits/stdc++.h>
using namespace std;
int row[8],a,b,line;
bool place(int r,int c)
{
	for(int pc=0;pc<c;pc++)
	if(row[pc]==r||(abs(row[pc]-r)==abs(pc-c)))
	return false;
	return true;
}
void printsol()
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
}		
void backtrack(int c)
{	
	if(c==8)
	{	cout<<"Sol "<<line++<<"\n";	
		printsol();
		for(auto it:row)
		cout<<it<<" ";
		cout<<"\n";
	}
		//cout<<"\n";
	if(c<8)
	for(int r=0;r<8;r++)
	if(place(r,c))
	{	row[c]=r;
		cout<<"\ncalling with c= "<<c+1<<"\n";
		backtrack(c+1);
	}
}		
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	//cin>>a>>b;
		//a--;b--;
		memset(row,0,sizeof(row));
		line=1;
		auto start=chrono::steady_clock::now();
		backtrack(0);
		auto end=chrono::steady_clock::now();
		cout<<" time: "<<chrono::duration_cast<chrono::nanoseconds>(end-start).count();
	}
	return 0;
}
	
