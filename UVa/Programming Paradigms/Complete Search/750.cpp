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
void backtrack(int c)
{
	if(c==8&&row[b]==a)
	{	
		printf("%2d      ",line++);
		for(int j=0;j<8;j++)
		{	cout<<row[j]+1;
			if(j!=7)
			cout<<" ";
		}
		cout<<"\n";
	}
	for(int r=0;r<8;r++)
	if(place(r,c))
	{	row[c]=r;
		backtrack(c+1);
	}
}		
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	cin>>a>>b;
		a--;b--;
		memset(row,0,sizeof(row));
		line=1;
		cout<<"SOLN       COLUMN\n";
		cout<<" #      1 2 3 4 5 6 7 8\n\n";
		backtrack(0);
		if(t)
		cout<<"\n";
	}
	return 0;
}
	
