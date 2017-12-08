#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdlib.h>

using namespace std;
void insertionSort(vector <int>  ar) {
    int sample = ar[ar.size()-1];
    bool found = false;
    for (int i = ar.size()-2; i >= 0; i--){
        cout<<"i is: "<<i <<endl;
        if (ar[i] > sample){
            ar[i+1] = ar[i];
        }else{
            ar[i+1] = sample;
            found = true;
        }
        for(int j = 0; j<ar.size();j++){
            cout<<ar[j]<<" ";
        }
        if (found){
            break;
        }
        cout<<endl;
    }
    if (!found){
        ar[0] = sample;
        for(int j = 0; j<ar.size();j++){
            cout<<ar[j]<<" ";
        }
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

    insertionSort(_ar);
    return 0;
}
