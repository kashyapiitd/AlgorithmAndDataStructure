#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <iostream>

#define NUM_ELEMENTS 100
using namespace std;
class data{
public:
    int index;
    string name;
};

void printArray(vector<int> ar){
     for (int j = 0; j < ar.size(); j++){
             cout<<ar[j]<<" ";
          }
          cout<<endl;
}


void countingSort(vector<int>& ar){
    vector<int> counts(NUM_ELEMENTS,0);
    for (int i = 0; i < ar.size(); i++){
        counts[ar[i]]++;
    }
    vector<int>sortedArray;
    for (int i = 0; i < NUM_ELEMENTS; i++ ){
        if (counts[i] != 0){
            int countElement = counts[i];
            while(countElement > 0){
                sortedArray.push_back(i);
                countElement--;
            }
        }
    }
    printArray(sortedArray);
}
int main(){
    int nElements;
    cin >> nElements;
    vector<int> ar(nElements);
    for(int i = 0; i < nElements; i++){
        cin >> ar[i];
    }
    countingSort(ar);
}
