#include<bits/stdc++.h>
using namespace std;
int arr[1000000];
int parent(int a)
{
	while(arr[a]!=a)
	{
		arr[a]=arr[arr[a]];
		a=arr[a];
	}
	return a;
}
void _union(int a,int b)
{
	int p=parent(a);
	int q=parent(b);
	if(p!=q)
	arr[p]=arr[q];
}
void ini(int n)
{
	for(int i=1;i<=n;i++)
	arr[i]=i;
}
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("\n%d\n",&n);
		//cout<<"n= "<<n<<"\n";
		string line;
		ini(n);
		char c;int x,y,pos=0,neg=0;
		while(true)
		{	if(!getline(cin,line)||line.empty())
			break;
			//sscanf(line.c_str(),"%c %d %d",&c,&i,&j);
			stringstream ss(line);
			ss>>c>>x>>y;
			//cout<<c<<" "<<i<<" "<<j;
			if(c=='c')
			{
				_union(x,y);
				//cout<<"doing union\n";	
			}
			else
			{
				if(parent(x)==parent(y))
				pos++;
				else
				neg++;
			}
			//cout<<"querying\n";
			//cout<<"\n";
			
		}
		cout<<pos<<","<<neg<<"\n";
		/*for(int i=1;i<=n;i++)
		cout<<"i= "<<i<<" "<<parent(arr[i])<<"\n";*/
		if(t)
		cout<<"\n";
	}
	return 0;
}
