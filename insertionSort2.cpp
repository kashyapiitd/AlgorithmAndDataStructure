#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdlib.h>

using namespace std;

int insertionSortEachElement(vector <int>& ar, int nElements) {
    int shiftForEachElement = 0;
    int sample = ar[nElements - 1];
    bool found = false;
    for (int i = nElements-2; i >= 0; i--){
        if (ar[i] > sample){
            ar[i+1] = ar[i];
            shiftForEachElement++;
        }else{
            ar[i+1] = sample;
            found = true;
        }
        if (found){
            break;
        }
    }
    if (!found){
        ar[0] = sample;
    }
    return shiftForEachElement;
}
void printArray(vector<int> ar){
     for (int j = 0; j < ar.size(); j++){
             cout<<ar[j]<<" ";
          }
          cout<<endl;
}
void insertionSort(vector<int> ar) {
    int totalShifts = 0;
    for (int i = 1; i < ar.size(); i++){
        totalShifts+=insertionSortEachElement(ar,i+1);
        // Print the Array
/*         for (int j = 0; j < ar.size(); j++){
 *             cout<<ar[j]<<" ";
 *         }
 *         cout<<endl;
 */

    }
    // Print the total number of shifts
        cout<<totalShifts<<endl;

}
void insertionSortNew(vector<int>& ar){
    for (int i = 1; i < ar.size(); i++){
        int sample = ar[i];
        int j = i-1;
        while(j>=0 && ar[j] > sample){
            ar[j+1] = ar[j];
            j--;
        }
       ar[j+1] = sample;
    }
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

    //insertionSort(_ar);
    insertionSortNew(_ar);
    printArray(_ar);
    return 0;
}
