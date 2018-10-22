#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		bool sol=false;
		int x,y,z,a,b,c;
		cin>>a>>b>>c;
		for(x=-22;x<=22;x++)
		{	if(x*x<=c)
			{
			for(y=-100;y<=100;y++)
			{	if(y!=x&&x*x+y*y<=c)
				{
				for(z=-100;z<=100;z++)
				{
					if(x!=y && x!=z && y!=z && x+y+z==a && x*y*z==b && x*x+y*y+z*z==c)
					{
						if(!sol)
						{	cout<<x<<" "<<y<<" "<<z;
							sol=true;
						}
					}
				}
			}
		}
		if(!sol)
		cout<<"No solution.";
		if(t)
		cout<<"\n";
	}
	return 0;
}
