#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{	//freopen("in.txt","r",stdin);
	string s;
	cin>>s;
	map<char,int> mp;
	mp['C']=12;mp['O']=16;mp['H']=1;
	stack<int> st;
	int v;
	for(int i=0;i<s.length();i++)
	{
		if(isdigit(s[i]))
		{
			v=st.top();
			st.pop();
			st.push((s[i]-48)*v);
		}
		else if(isalpha(s[i]))
		st.push(mp[s[i]]);
		else if(s[i]=='(')
		st.push(-1);
		else if(s[i]==')')
		{
			v=0;
			while(st.top()!=-1)
			{
				v+=st.top();
				st.pop();
			}
			st.pop();
			st.push(v);
		}
	}
	v=0;
	while(!st.empty())
	{
		v+=st.top();
		st.pop();
	}
	cout<<v;
	return 0;
}
