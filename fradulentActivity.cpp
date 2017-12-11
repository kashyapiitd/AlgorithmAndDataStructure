#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <iostream>

using namespace std;
vector<int>counts(201,0);
float computeMedianExpense1(vector<int>& expenses,int start, int stop, int d){
    float medianExpense;
    // Check if the number of days in history is even or odd
    int nHistoryDays = d;
    int midVal = 0;
    if (nHistoryDays % 2 == 0){
        midVal = nHistoryDays /2;
        int midVal1 = midVal -1;
        std::nth_element(expenses.begin()+start,expenses.begin()+start+midVal,expenses.begin()+stop);
        medianExpense = (float)expenses[start+midVal];
        std::nth_element(expenses.begin()+start,expenses.begin()+start+midVal1,expenses.begin()+stop);
        int temp = expenses[start+midVal];
        medianExpense = (float)( medianExpense + temp )/2.0;
    }else{
        midVal = nHistoryDays / 2;
        std::nth_element(expenses.begin()+start,expenses.begin()+start+midVal,expenses.begin()+stop);
        medianExpense = (float)expenses[start+midVal];
    }
    //cout<<"Median Expense for start: "<<start<<" till End: "<<stop<<" is: "<<medianExpense<<endl;
    return medianExpense;
}
void makeCountsArray(vector<int>& expenses,int d)
{
  for(int i = 0; i < d; i++)
  {
    counts[expenses[i]]++;
  }
}
float computeMedianExpense(vector<int>& expenses,int start, int stop, int d){
  float medianExpense = 0;
  if (stop != d)
  {
    int removeElement = expenses[start-1];
    int newElement = expenses[stop-1];
    counts[removeElement]--;
    counts[newElement]++;
  }
  int dby2 = d /2;
  // Get the median from the counts array
  if (d % 2 != 0)
  {
    //cout<<"Odd\n";
    int nSamples = 0;
    for (int i = 0; i < counts.size(); i++)
    {
      nSamples+=counts[i]; 
      //cout<<nSamples<<endl; 
      if (nSamples > dby2)
      {
        //cout<<"i is: "<<i<<endl;
        medianExpense = (float)i;
        break;
      }
    }
  }
  else
  {
    //cout<<"Even\n";
    int nSamples = 0;
    for (int i = 0; i < counts.size(); i++)
    {
      nSamples+=counts[i];
      if (nSamples == dby2)
      {
        medianExpense = (float)(i + (i+1))/2.0;
        break;
      }
      else if (nSamples > dby2 )
      {
        medianExpense = (float)i;
        break;
      }

    }
  }
  return medianExpense;
}
int activityNotifications(vector <int> expenditure, int d) {
   int nNotifications = 0;
   int nDays = expenditure.size();
   int startIndex = 0;
   int endIndex = d;
   makeCountsArray(expenditure,d);
   for (int i = d; i < nDays; i++)
   {
       int expenseForDay = expenditure[i];
       float medianForLastDDays = computeMedianExpense(expenditure,startIndex, endIndex, d);
       if (expenseForDay >= (2 * medianForLastDDays)){
            nNotifications++;
       }
       startIndex = startIndex +1;
       endIndex = endIndex+1;
   }
   return nNotifications;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> expenditure(n);
    for(int expenditure_i = 0; expenditure_i < n; expenditure_i++){
       cin >> expenditure[expenditure_i];
    }
    int result = activityNotifications(expenditure, d);
    cout << result << endl;
    return 0;
}
