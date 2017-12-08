#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    int nElements;
    cin >> nElements;
    vector<int> ar(nElements);
    for(int i = 0; i < nElements; i++){
        cin >> ar[i];
    }
    int halfSize = ar.size()/2;
    std::nth_element (ar.begin(), ar.begin()+halfSize, ar.end());
    cout<<ar[halfSize]<<endl;
    return 0;
}
