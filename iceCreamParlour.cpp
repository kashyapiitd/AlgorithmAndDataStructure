#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;
pair<int, int> computeIndices(vector<int> ar, int sum)
{
    // First construct a map
    int firstIndex;
    int secondIndex;
    unordered_map<int, int> compValToIndexMap;
    for (int i = 1 ; i < ar.size(); i++)
    {
        int currNumber = ar[i];
        int compNumber = sum - currNumber;
        //cout<<"curr: "<<currNumber<<" comp: "<<compNumber<<endl;
        if (compNumber > 0)
        {
            // Search in the Map to see if we have seen this before
            if (compValToIndexMap .find (currNumber) != compValToIndexMap.end())
            {
                // Get the index of the compNumber from the Map
                //cout<<"comp no found\n";
                int compNumberIndex = compValToIndexMap[currNumber];
                firstIndex = i;
                secondIndex = compNumberIndex;
                //cout<<firstIndex << " and "<<secondIndex<<endl;
                break;
            }
            else
            {
                // If not found put the number on to the map
                //cout <<"comp number not found\n";
                compValToIndexMap[compNumber] = i;
            }
        }
    }
    pair<int, int> returnPair;
    if (firstIndex < secondIndex)
    {
        returnPair.first = firstIndex ;
        returnPair.second = secondIndex ;
    }
    else
    {
        returnPair.first = secondIndex ;
        returnPair.second = firstIndex ;
    }
    return returnPair;
}
int main()
{
    int nTrips;
    cin >> nTrips;
    vector<pair<int, int> > output(nTrips);
    for (int i = 0; i < nTrips; i++)
    {
        int m;
        int n;
        cin >> m;
        cin >> n;
        vector<int> iceCream(n+1,0);
        for (int j = 1; j < n+1; j++)
        {
            cin >> iceCream[j];
        }
        pair<int, int> tempOutput = computeIndices(iceCream,m);
        output[i] = tempOutput;
    }
    // Output the Result
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i].first <<" "<<output[i].second << endl;
    }
}
