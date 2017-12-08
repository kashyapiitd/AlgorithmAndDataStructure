#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <iostream>
using namespace std;


class BinaryIndexedTree{
private:
    vector<int> mArray;
public:
    void setValue(int position, int val){
        int position1 = position;
        while(position1 < mArray.size()){
            position = position1;
            mArray[position]+=val;
            // To find the Next position , add bit 1 to the
            // last set bit of the position/index.
            // This is acheived by doing position+= position & -position
            position1 += position & (0-position);
        }
    }
    int getSum(int index){
        //index++;
        int sum = 0;
        int index1 = index;
        while(index > 0){
            index = index1;
            sum+=mArray[index];
             // To find the Next index , subtract bit 1 to the
            // last set bit of the position/index.
            // This is acheived by doing position-= position & -position
            index1 -= index & (0 - index);
        }
        return sum;
    }
    BinaryIndexedTree(vector<int> input){
        // Start with an array with size of input.size()+1 as the indexing starts with 1
        mArray.resize(input.size()+1,0);
        // Construct the BIT
        for (int i = 1; i < mArray.size(); i++){
            setValue(i,input[i-1]);
        }
        // Print the Array
        for (int i = 0; i < mArray.size(); i++){
           cout<<mArray[i]<<",";
        }
        cout<<endl;
    }
};

int main(){
    vector<int> test{5,2,1,0,5,2,3,4};
    BinaryIndexedTree myTree(test);
    cout<< myTree.getSum(5) << endl;

    return 0;
}
