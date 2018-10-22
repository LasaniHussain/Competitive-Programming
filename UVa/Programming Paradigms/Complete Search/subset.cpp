#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[]={1,2,3,4,5};
	int i,j,n=3;
	//for(i=0;i<(1<<n);i++)
	//{
		for(j=0;j<n;j++)
		if(3&(1<<j))
		cout<<arr[j]<<" ";
		cout<<"\n";
	
	return 0;
}
