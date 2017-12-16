#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

string solve(vector < int > a){
    // Complete this function
    if (a.size() == 1)
    {
        return "YES";
    }
    if (a.size() >= 3)
    {
        int pivotIndex = a.size() - 2;// secondLast Element is Pivot
        int rightIndex = a.size() -1;
        int leftIndex = a.size() - 3;
        // Compute the sum till the leftIndex
        long int sumTillLeftIndex = std::accumulate(a.begin(),a.begin()+leftIndex+1,(long int)0);
        long int sumTillRightIndex = (long int) a[rightIndex];
        while(leftIndex >= 0)
        {
            //cout<< sumTillLeftIndex << " " << sumTillRightIndex << endl;
            if (sumTillLeftIndex == sumTillRightIndex)
            {
                return "YES";
                break;
            }
            else
            {
                sumTillLeftIndex -= a[leftIndex];
                sumTillRightIndex += a[pivotIndex];
                leftIndex--;
                rightIndex--;
                pivotIndex--;

            }
        }
        return "NO";

    }
    else
    {
        return "NO";
    }
}

int main() {
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        string result = solve(a);
        cout << result << endl;
    }
    return 0;
}
