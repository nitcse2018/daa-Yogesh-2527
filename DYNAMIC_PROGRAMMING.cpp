#include<iostream>
using namespace std;
#define MAX 100
int n=4;
int dist[10][10] = {
        				{0,20,42,25},
        				{20,0,30,34},
       					{42,30,0,10},
       					{25,34,10,0},
};
int travel_all = (1<<n) -1;
int ar[16][4];
int  tsp(int mask,int pos)
{
	if(mask==travel_all)
	{
		return dist[pos][0];
	}
	if(ar[mask][pos]!=-1)
	{
	   return ar[mask][pos];
	}
	int ans = INT_MAX;
	for(int city=0;city<n;city++)
	{
		if((mask&(1<<city))==0)
		{
			int nAns = dist[pos][city] + tsp( mask|(1<<city), city);
			ans = min(ans, nAns);
		}
	}
	return ar[mask][pos] = ans;
} 
int main()
{
    for(int i=0;i<(1<<n);i++)
	{
    	for(int j=0;j<n;j++){
            ar[i][j] = -1;
        }
    }
	cout<<"MIN_COST TRAVELLING DISTANCE: "<<tsp(1,0);
return 0;
}
