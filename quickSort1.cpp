#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <iostream>

using namespace std;

void printArray(vector<int> ar){
     for (int j = 0; j < ar.size(); j++){
             cout<<ar[j]<<" ";
          }
          cout<<endl;
}


void partition(vector <int>  ar) {
   // Enter code for partitioning and printing here.
   int pivot = ar[0];
   vector<int> leftElements;
   vector<int> rightElements;
   for (int i = 1; i < ar.size(); i++ ){
        if (ar[i] <= pivot){
            leftElements.push_back(ar[i]);
        }
        else{
            rightElements.push_back(ar[i]);
        }
   }
   // Join the arrays
   //vector<int>result(leftElements.size()+rightElements.size()+1);
   vector<int> result;
   result.insert(result.begin(),leftElements.begin(),leftElements.end());
   result.insert(result.begin()+leftElements.size(),pivot);
   result.insert(result.begin()+leftElements.size()+1,rightElements.begin(),rightElements.end());
   printArray(result);
}
int main(void) {
   vector <int>  _ar;
   int _ar_size;
   cin >> _ar_size;

     for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }

   partition(_ar);

   return 0;
}

