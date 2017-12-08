#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdlib.h>
using namespace std;

int main(){
    int query = 0;
    int nElements = 0;
    cin >> query;
    cin >> nElements;
    vector<int> myArray(nElements,0);
    for (int i = 0; i < nElements; i++){
        cin >> myArray[i];
    }
    // Search for the query Element in the array
    for (int i = 0; i < nElements; i++){
        if (myArray[i] == query){
            cout<<i<<endl;
            break;
        }
    }

}
