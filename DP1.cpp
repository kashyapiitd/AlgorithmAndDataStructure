#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countMinOperations(vector<int> & arr)
{
    // Check the Min Element
    int minElement = *(min_element(arr.begin(),arr.end()));
    //cout << minElement<<endl;
    // We need to try for minElement, minElement-1, minElement-2,minElement-3,minElement-4
    int count = 0;
    int maxCount;
    if (minElement - 5 >= 0)
        maxCount = 5;
    else
        maxCount = 5 - minElement;
    int minOperations;
    while (count < maxCount)
    {
        //cout << count << endl;
        int operations_count = 0;
        int element = minElement - count;
        vector<int> minElementArray(arr.size(),element);
        vector<int> subtractionResult(arr.size());
        std::transform(arr.begin(),arr.end(),minElementArray.begin(),subtractionResult.begin(),[](int & first, int & second){return first - second;});
        // Iterate through the subtractionResult and find the number of operations needed
        for (int i = 0 ; i < subtractionResult.size(); i++)
        {
            int a2 = 0,a1 = 0,a0 = 0;
            int subtractionAnswer = subtractionResult[i];
            if (subtractionAnswer == 0)
                continue;
            else{
                // Try to count the operations in terms of 1,2 and 5
                a2 = subtractionAnswer/5;
                if (subtractionAnswer % 5 != 0)
                    a1 = (subtractionAnswer%5)/2;
                if ((subtractionAnswer%5)%2 != 0)
                    a0 = (subtractionAnswer%5)%2;
            }
            //cout << "answer is: "<<subtractionAnswer<<" and weights are: "<<a2<<" "<<a1<<" "<<a0<<endl;
            // The Number of operations for this number will be sum of a2,a1 and a0
            operations_count+=(a2+a1+a0);
            //cout << operations_count << endl;
        }
        if (count == 0)
            minOperations = operations_count;
        else
            (operations_count < minOperations) ? minOperations = operations_count : minOperations = minOperations;
        count++;
    }
    return minOperations;

}
int main()
{
    int nTests;
    cin >> nTests;
    for (int i = 0 ; i < nTests; i++)
    {
        int nElements;
        cin >> nElements;
        vector<int> arr(nElements);
        for (int j = 0 ; j < nElements; j++)
        {
            cin >> arr[j];
        }
        int result = countMinOperations(arr);
        cout << result << endl;
    }
    return 1;
}
