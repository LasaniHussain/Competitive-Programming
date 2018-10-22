#include<bits/stdc++.h>
using namespace std;
string s;
int memo[6101][6101];
int back(int i,int j)
{	if(i>j)
	return INT_MAX;
	if(i==j)
	return 0;
	if(i==j-1)
	return s[i]==s[j]?0:1;
	if(memo[i][j]!=-1)
	return memo[i][j];
	if(s[i]==s[j])
	return memo[i][j]=back(i+1,j-1);
	else 
	return memo[i][j]=min(back(i+1,j),back(i,j-1))+1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		memset(memo,-1,sizeof(memo));
		back(0,s.length()-1);
		cout<<memo[0][s.length()-1];
		if(t)
		cout<<"\n";
	}
	return 0;
}
