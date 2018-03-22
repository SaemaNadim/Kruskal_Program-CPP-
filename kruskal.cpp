#include<iostream>
# include<algorithm>
using namespace std;
struct kruskal
{
	int i;
	int j;
	int weight;
	
};
int n,m;
int p[30];
int r[30];
 void makeset(int x)
   {
     p[x]=x;
     r[x]=0;
   }
  int findset(int x)
    {
      if(x!=p[x])
      p[x]=findset(p[x]);
      return p[x];
    }
  void uni(int x,int y)
   {
     int rep1=findset(x);
     int rep2=findset(y);
     if(r[rep1]>r[rep2])
       {
          p[rep2]=rep1;
       }
      else if(r[rep2]>r[rep1])
       {
	       p[rep1]=rep2;
       }
      else if(r[rep1]==r[rep2])
       {
	        p[rep2]=rep1;
	         r[rep1]=r[rep1]+1;
    	}
     }
     bool comp(kruskal a, kruskal b)
     {
     	return(b.weight>a.weight);
	 }
    int main()
    {
    	cout<<"enter the total verteces and edges\n";
    	cin>>n>>m;
    	kruskal arr[m];
    	int count=0;
    	for(int i=0;i<n;i++)
    	{
    		makeset(i);
		}
		cout<<"now enter edge with weight\n";
		for(int f=0;f<m;f++)
		{
			cin>>arr[f].i>>arr[f].j>>arr[f].weight;
		}
		sort(arr,arr+m,comp);
		for(int h=0;h<m;h++)
		{
			int u=arr[h].i;
			int v=arr[h].j;
			if(findset(u)!=findset(v))
			{
				count=count+arr[h].weight;
				uni(u,v);
			}
		}
		cout<<"min spanning weight is ";
		cout<<count;
		return 0;
	}
		
		
    	
		
    	
	

