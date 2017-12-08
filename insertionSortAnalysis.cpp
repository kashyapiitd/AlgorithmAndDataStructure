#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX_ELEMENTS 10000000

void computeNPasses(vector<int>& input){
    int nPasses  = 0;
    for (int i = 0; i < input.size();i++){
        int sample = input[i];
        int j = i+1;
        while(j < input.size()){
            if (input[j] < sample){
                nPasses++;
            }
            j++;
        }
    }
    cout<<nPasses<<endl;
}
unsigned long long int getBitSum(vector<int>& bit,int idx){
        int idx1 = idx;
        unsigned long long int sum = 0;
        while(idx > 0){
            sum+=bit[idx];
            idx1 -= (idx & -idx);
            idx = idx1;
        }
        return sum;
}
void updateBit(vector<int>& bit,int idx, int value){
    int idx1 = idx;
    while(idx < bit.size()){
        bit[idx]+=value;
        idx1 += (idx & -idx);
        idx = idx1;
    }
}
void computeNPassesBIT(vector<int>& input){
    vector<int> bit(MAX_ELEMENTS+1,0);
    // Start from the last element in the input array.
    // and check how many elements smaller then the current
    // element already exists.
    unsigned long long int nPasses = 0;
    for (int i = input.size() -1; i >= 0; i--){
        // Get the number of elements smaller then the current element.
        unsigned long long int temp = getBitSum(bit,input[i]-1);
        //cout << temp <<endl;
        nPasses+=temp;
        // Update the BIT with a 1 in the position denoted by the current element.
        updateBit(bit,input[i],1);
    }
    //cout<<nPasses<<endl;

}
int main(){
    int nSets;
    cin >> nSets;
    vector<vector<int> > ar(nSets);
    for (int i = 0; i < nSets; i++){
        int nElements;
        cin >> nElements;
        ar[i].resize(nElements);
        for (int j = 0; j < nElements; j++){
            cin >> ar[i][j];
        }
    }
    for(int i = 0; i < nSets; i++){
        //computeNPasses(ar[i]);
        computeNPassesBIT(ar[i]);
    }
    return 0;
}
