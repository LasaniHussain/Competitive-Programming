#include<bits/stdc++.h>
using namespace std;
string s;
int back(int i,int j)
{	if(i>j)
	return 0;
	if(s[i]==s[j])
	return back(i+1,j-1);
	else if(i==j-1)
	{
		if(s[i]==s[j])
		return 0;
		else
		return 1;
	}
	else
	return min(back(i+1,j),back(i,j-1))+1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		cout<<back(0,s.length()-1);
		if(t)
		cout<<"\n";
	}
	return 0;
}
