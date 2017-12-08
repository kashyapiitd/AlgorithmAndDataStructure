#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <iostream>

using namespace std;
float computeMedianExpense(vector<int>& expenses,int start, int stop, int d){
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
int activityNotifications(vector <int> expenditure, int d) {
   int nNotifications = 0;
   int nDays = expenditure.size();
   int startIndex = 0;
   int endIndex = d;
   for (int i = d; i < nDays; i++)
   {
       int expenseForDay = expenditure[i];
       float medianForLastDDays = computeMedianExpense(expenditure,startIndex, endIndex, d);
       //cout<<"Median Expense for start: "<<startIndex<<" till End: "<<endIndex<<" is: "<<medianForLastDDays<<endl;
       //cout<<"Expenditure is: "<<expenseForDay<<endl;
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
