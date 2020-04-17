#include<iostream>
using namespace std;
#define MAX 100
typedef struct Job {
  char id[5];
  int deadline;
  int profit;
} Job;

void jobSequencingWithDeadline(Job jobs[], int n);

int minValue(int x, int y)
 {
  if(x < y) return x;
  return y;
}
int main(void) 
{
  int i, j;

  Job jobs[5] = {
    {"j1", 4,  80},
    {"j2", 6, 120},
    {"j3", 3,  20},
    {"j4", 5,  60},
    {"j5", 1,  40},
  };
  Job temp;
  int n = 5;

  for(i = 1; i < n; i++) //sort the jobs profit wise in descending order 
  {
    for(j = 0; j < n - i; j++) 
	{
      if(jobs[j+1].profit > jobs[j].profit)
	   {
        temp = jobs[j+1];
        jobs[j+1] = jobs[j];
        jobs[j] = temp;
      }
    }
  }
	cout<<"  \nJOB\t    Deadline\t    TOTAL_Profit\n";
  	for(i = 0; i < n; i++) 
  		{
    		cout<<"\n  " <<jobs[i].id<<"\t\t"<<jobs[i].deadline<<"\t\t"<<jobs[i].profit;
  		}

  jobSequencingWithDeadline(jobs, n);
	return 0;
}

void jobSequencingWithDeadline(Job jobs[], int n) 
{
  int i, j, k, maxprofit;
  int timeslot[MAX];
  int filledTimeSlot = 0;
  int dmax = 0;
  for(i = 0; i < n; i++)
   {
    if(jobs[i].deadline > dmax)
	 {
      dmax = jobs[i].deadline;
    }
  }
  for(i = 1; i <= dmax; i++) {
    timeslot[i] = -1;
  }
	cout<<"\ndmax:  "<<dmax;
  for(i = 1; i <= n; i++) 
  {
    k = minValue(dmax, jobs[i - 1].deadline);
    while(k >= 1) {
      if(timeslot[k] == -1) {
        timeslot[k] = i-1;
        filledTimeSlot++;
        break;
      }
      k--;
    }
  if(filledTimeSlot == dmax)
   {
      break;
    }
  }
  cout<<"\n Required Jobs: ";   //required jobs
  for(i = 1; i <= dmax; i++) {
    cout<<jobs[timeslot[i]].id;
 
 if(i < dmax) {
      cout<<" --> ";
    }
  }
  maxprofit = 0;
  for(i = 1; i <= dmax; i++) {
    maxprofit += jobs[timeslot[i]].profit;
  }
  cout<<"\nMax Profit: "<<maxprofit;
}
