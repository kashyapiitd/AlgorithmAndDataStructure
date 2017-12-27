#include <iostream>
#include <vector>
#include <string>
#include <numeric>

#define scale 1000 * 1000 * 1000 + 7

using namespace std;

void printVector(vector<long long> input)
{
    for (int i = 0 ; i < input.size(); i++)
    {
        cout << input[i]<<",";
    }
    cout <<endl;
}
long long findSunOfStringRecursively(string input)
{
    long long result = 0;
    vector<long long> sumToIndex(input.size(), 0);
    sumToIndex[0] = (long long )input[0] - (long long)48;
    for (int i = 1; i < input.size(); i++)
    {
        long long temp = (long long) input[i] - (long long)48;
        //cout << sumToIndex[i-1] << scale << (sumToIndex[i-1] % (long long )100000007) << endl;
        sumToIndex[i] = (i+1)*temp + (10 * (sumToIndex[i-1] % (long long)100000007));
        sumToIndex[i] = sumToIndex[i] % (long long)100000007;

    }
    printVector(sumToIndex);
    result = accumulate(sumToIndex.begin(),sumToIndex.end(), (long long)0);
    result %= (long long)100000007;
    return result;
}
int main()
{
    string  N;
    cin >> N;
    long long result = findSunOfStringRecursively(N);
    cout << result << endl;
    return 1;
}
