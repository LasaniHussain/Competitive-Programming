#include<bits/stdc++.h>
using namespace std;
int memo[5][7500],val,V[5]={1,5,10,25,50},N=5;
int ways(int ind,int v)
{	//cout<<"ways("<<ind<<","<<v<<")\n";	
	if(v==0)
	{	//cout<<"1 returned for val=0 ind= "<<ind<<"\n";
		return 1;
	}
	if(v<0||ind==N)
	return 0;
	if(memo[ind][v]!=-1)
	return memo[ind][v];
	return memo[ind][v]=ways(ind+1,v)+ways(ind,v-V[ind]);
}
int main()
{	memset(memo,-1,sizeof memo);
	while(scanf("%d", &val) != EOF)
	{	//cout<<val<<"\t";
		cout<<ways(0,val)<<"\n";
	}
	return 0;
}	
