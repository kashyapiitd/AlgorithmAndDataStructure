#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printVector(vector<int> input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout<<input[i]<<" , ";
    }
    cout<<endl;
}
vector<int> Merge(vector<int> left, vector<int> right)
{
    //printVector(left);
    //printVector(right);
    vector<int>sorted(left.size()+right.size());
    int left_index = 0;
    int right_index = 0;
    int result_index = 0;
    while(left_index < left.size() && right_index < right.size())
    {
        if (left[left_index] < right[right_index])
        {
            sorted[result_index] = left[left_index];
            result_index++;
            left_index++;
        }
        else
        {
            sorted[result_index] = right[right_index];
            result_index++;
            right_index++;
        }
    }
    if (left_index == left.size() - 1)
    {
        sorted[result_index] = left[left_index];
    }
    if (right_index == right.size() - 1)
    {
        sorted[result_index] = right[right_index];
    }
    //printVector(sorted);
    return sorted;
}
vector<int> mergeSort(vector<int> ar)
{
    //cout<<"Merge Sort Called. array size is: "<<ar.size()<<endl;
    if(ar.size() > 1)
    {
        int halfSize = ar.size()/2;
        // Split the unsorted array into two halves
        vector<int> leftHalf,rightHalf;
        leftHalf.resize(halfSize);
        rightHalf.resize(ar.size()-halfSize);
        copy(ar.begin(),ar.begin()+halfSize,leftHalf.begin());
        copy(ar.begin()+halfSize,ar.end(),rightHalf.begin());
        // Call merge sort again with the splitted halves
        vector<int> leftSorted = mergeSort(leftHalf);
        vector<int> rightSorted = mergeSort(rightHalf);
        // Call the Merge Routine to combine two sorted subarrays into one
        vector<int> sorted = Merge(leftSorted,rightSorted);
        return sorted;
    }
    else
    {
        return ar;
    }

}
int main()
{
    int nElements;
    cin >> nElements;
    vector<int> input(nElements);
    for (int i = 0; i < nElements; i++)
    {
        cin >> input[i];
    }
    vector<int> sortedArray = mergeSort(input);
    for (int i = 0; i < nElements; i++)
    {
        cout << sortedArray[i]<<endl;;
    }
    return 1;
}
