#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
void printVector(vector<long int> input)
{
    for (int i = 0 ; i < input.size(); i++)
    {
        cout << input[i]<<",";
    }
    cout <<endl;
}

long  int computeMinTotalCandies(vector<long int> scores,vector<long int> candies, long int N)
{
    long int total = 0;
    // Forward Loop
    for (int i = 1; i < N; i++)
    {
        if (scores[i] > scores[i-1])
        {
            candies[i] = candies[i-1] + 1;
        }
    }
    // Reverse Loop
    for (int i = N-2; i >= 0; i--)
    {
        if (scores[i] > scores[i+1] && candies[i] <= candies[i+1])
        {
            candies[i] = max(candies[i],candies[i+1]+1);
        }
    }
    total = std::accumulate(candies.begin(),candies.end(),(long int)0);
    return total;
}
long int computeMinTotalCandiesNew(vector<long int> scores, long int N)
{
    long int total = 0;
    vector<long int> candies(N+2,0);
    long int first = scores[0];
    long int last = scores[N-1];
    scores.insert(scores.begin(),first+ 1);
    scores.insert(scores.end(),last + 1);
    //printVector(candies);
    // Assign candies to the valleys
    for (int i = 1 ; i <= N; i++)
    {
        if (scores[i] <= scores[i+1] && scores[i] <= scores[i-1])
        {
            candies[i] = 1;
        }
    }
    //printVector(candies);
    // Assign rises from left to right
    for (int i = 1; i <= N ; i++)
    {
        if (scores[i] > scores[i-1] && scores[i] <= scores[i+1])
        {
            candies[i] = candies[i-1] + 1;
        }
    }
    //printVector(candies);
    // Assign falls from right to left
    for (int i = N; i >= 1; i--)
    {
        if (scores[i] > scores[i+1] && scores[i] <= scores[i-1])
        {
            candies[i] = candies[i+1] + 1;
        }
    }
    //printVector(candies);
    // Assign to the Peaks
    for (int i = 1; i <= N; i++)
    {
        if (scores[i] > scores[i-1] && scores[i] > scores[i+1])
        {
            candies[i] = max(candies[i-1],candies[i+1])+1;
        }
    }
    // Compute the total number of candies
    total = std::accumulate(candies.begin(),candies.end(),(long int)0);
    return total;
}
int main()
{
    long int N;
    cin >> N;
    vector<long int> scores(N,0);
    vector<long int> candies(N,1);// Minimum candy for each student is 1
    for (int i = 0; i <N; i++ )
    {
        cin >> scores[i];
    }
    //long int result =  computeMinTotalCandies(scores, candies, N);
    long int result = computeMinTotalCandiesNew(scores, N);
    cout << result <<endl;
    return 1;
}
