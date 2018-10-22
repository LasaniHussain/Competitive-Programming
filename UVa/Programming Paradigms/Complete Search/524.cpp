#include<bits/stdc++.h>
using namespace std;
int used[20],n,circle[16];
bool isPrime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		return false;
	}
	return true;
}
void backtrack(int pos)
{
	if(pos==n-1&&isPrime(circle[pos]+1))
	{
		for(int i=0;i<n;i++)
		{
			cout<<circle[i];
			if(i!=n-1)
			cout<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=2;i<=n;i++)
	{
		if(!used[i]&&isPrime(circle[pos]+i))
		{
			used[i]=1;
			circle[pos+1]=i;
			backtrack(pos+1);
			used[i]=0;
		}
	}
}
int main()
{
	int t=0;
	while(cin>>n)
	{
		memset(used,0,sizeof(used));
		t++;
		if(t>1)
		cout<<"\n";
		cout<<"Case "<<t<<":\n";
		circle[0]=1;
		backtrack(0);
		//cout<<"\n";
	}
	return 0;
}
