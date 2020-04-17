#include <iostream>
#include <stack>
using namespace std;
 
int set[] = {10, 7, 3, 5, 18, 12, 20, 15, 2, 8 };
int n = 10, sum = 25  ;
 
class SubSet{
    public:
  
  	stack<int> solutionSet;
  	bool hasSolution;
  	bool solve(int s, int idx)
	{
      if(s>sum) //return false if s value exceed sum
    return false;
 
    if(s==sum)  //check if stack has the right subsets of numbers
	{
        hasSolution = true;
         cout << "\t POSSIBLE OUTCOMES : ";
		displaySolutionSet();
        return false;
    }
        for(int i=idx; i<n; i++)
		{
        	solutionSet.push(set[i]);
 	        if(solve(s+set[i],i+1))
			 	{
            		return true;
            	}	
        solutionSet.pop();
    }
        return false;
  }
void displaySolutionSet()   // Function to display stack content
  {
        stack<int> temp;
        while (!solutionSet.empty()) 
        { 
        cout <<  solutionSet.top() << "  "; 
            temp.push(solutionSet.top()); 
            solutionSet.pop();
        } 
        cout << '\n';
        
        while (!temp.empty()) 
        { 
            solutionSet.push(temp.top()); 
            temp.pop();
        } 
    }
};
 
int main()
{
  	SubSet ss;
    ss.solve(0,0);
	    
	if(ss.hasSolution == false)
	    cout << "No Solution";
  	return 0;
}
