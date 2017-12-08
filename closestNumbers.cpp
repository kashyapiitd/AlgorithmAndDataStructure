#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <iostream>

using namespace std;
void closestNumbers(vector<int> & input){
    vector<pair<int,int> > output;
    // First Sort the Array
    sort(input.begin(),input.end());// O(nLogn)
    vector<int> diff(input.size() -1);
    for (int i = 1; i < input.size(); i++){
        diff[i-1] = input[i] - input[i-1];
    }
    // Find the Smallest diff among them
    int minimum = *min_element(diff.begin(),diff.end());
    // Iterate through the diff array and find all the pairs
    for (int i = 0; i < diff.size(); i++){
        if (diff[i] == minimum){
            pair<int,int> temp = make_pair(input[i],input[i+1]);
            output.push_back(temp);
        }
    }
    // Print the Pairs
    for (int i = 0; i < output.size(); i++){
        cout<<output[i].first<<" "<<output[i].second<<" ";
    }
    cout<<endl;
}
int main(){
    int nElements;
    cin >> nElements;
    vector<int> ar(nElements);
    for(int i = 0; i < nElements; i++){
        cin >> ar[i];
    }
    closestNumbers(ar);
    return 0;
}
