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
void countingSort(vector<data>& input){
    int threshold = input.size()/2;
    vector<int> countElements(NUM_ELEMENTS,0);
    vector<vector<int> > nameArray(NUM_ELEMENTS);
    for (int i = 0; i < input.size(); i++){
        countElements[input[i].index]++;
        nameArray[input[i].index].push_back(i);
    }
/*     for (int i = 0; i < 10; i++){
 *         for (int j = 0 ; j < nameArray[i].size(); j++){
 *             cout<<nameArray[i][j]<<",";
 *         }
 *         cout<<endl;
 *     }
 */
    // Iterate through the countElements Array
    vector<data> output(input.size());
    int outputIndex = 0;
    for (int i = 0; i < countElements.size(); i++){
        if (countElements[i] != 0){
            int counts = 0;
            while(counts < countElements[i]){
                output[outputIndex].index = i;
                int index = nameArray[i][counts];
                if (index >= threshold){
                    output[outputIndex].name = input[nameArray[i][counts]].name;
                }else{
                    output[outputIndex].name = "-";
                }

                counts++;
                outputIndex++;
            }
        }
    }
     for (int i = 0; i < output.size(); i++){
        cout<<output[i].name<<" ";
    }
    cout<<endl;
    // Print the Sorted array
    #ifdef PRINT_SORTED_LIST
    for (int i = 0; i < output.size(); i++){
        cout<<output[i].index<<" "<<output[i].name<<endl;
    }
    #endif

}
int main(){
    int nElements;
    cin >> nElements;
    vector<data> dictionary(nElements);
    for(int i = 0; i < nElements; i++){
        cin >> dictionary[i].index >> dictionary[i].name;
    }
    countingSort(dictionary);
    return 0;
}
