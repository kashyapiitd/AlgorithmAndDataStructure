#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_HOUSES 100000
void printVector(vector<int> input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout<<input[i]<<" , ";
    }
    cout<<endl;
}
int computeMinTransmitters(vector<int> positions, int range)
{
    int nTransmitters = 0;
    vector<int> transmitterPositions;
    // Make a count array
    vector<int> countPositions(MAX_HOUSES+1,0);
    // Take the count in this
    for (int i = 0; i < positions.size();i++)
    {
        countPositions[positions[i]]++;
    }
    // Iterate through this count array to find the min
    // number of transmitters needed
    int i = 1;
    while(i < countPositions.size())
    {
        if (countPositions[i] != 0)
        {
            //cout<<"B: "<<i<<endl;
            int nextAssumedPosition = i + range;
            // Check if a house exist in that position
            while (countPositions[nextAssumedPosition] == 0)
            {
                nextAssumedPosition--;
            }
            // Place a transmitter in the nextAssumedPosition and update the count
            //cout<<"Next POS: "<<nextAssumedPosition<<endl;
            transmitterPositions.push_back(nextAssumedPosition);
            nTransmitters++;
            // Also Update the value of i to next Position
            i = nextAssumedPosition + range + 1;
            //cout<<"A: "<<i<<endl;
        }
        else
        {
            i++;
        }
    }
    //cout<<"Transmitter Positions are: "<<endl;
    //printVector(transmitterPositions);
    return nTransmitters;
}
int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> x(n);
    for(int x_i = 0;x_i < n;x_i++){
       cin >> x[x_i];
    }
    int nTransmitters =  computeMinTransmitters(x,k);
    cout << nTransmitters << endl;
    return 0;
}
