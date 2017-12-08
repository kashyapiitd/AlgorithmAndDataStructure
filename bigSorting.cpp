#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdlib.h>

using namespace std;

bool sortingFunction(string first, string second){
    int m = first.length();
    int n = second.length();
    if (m == n)
    {
        return (first < second);
    }
    return m<n;
}
int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    std::sort(unsorted.begin(),unsorted.end(),sortingFunction);
    for (int i = 0; i < unsorted.size(); i++)
    {
        cout<<unsorted[i]<<endl;
    }
    return 0;
}
