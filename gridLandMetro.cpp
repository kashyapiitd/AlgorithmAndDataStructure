#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define MAX_ROWS 1000000000
#define MAX_COLUMNS 1000000000
#define INPUT_WIDTH 3

long long int computeNLampPositions(vector< vector <long int> > tracks,long int nRows,long int nCols)
{
    long long int nLamps = 0;
    // First compute the maximum possible number of locations
    long long int maxPossibleLocations = (long long int)nRows * (long long int)nCols;
    cout<<"Max Possible: "<<maxPossibleLocations<<endl;
    long long int startIndex;
    long long int endIndex;
    long long int usedCellCount;
    vector<long long int> usedCellNumbers;
    for (int i = 0; i < tracks.size(); i++)
    {
            long int rowNumber = tracks[i][0];
            long int startColNumber = tracks[i][1];
            long int endColNumber = tracks[i][2];
            cout<<"Row,Start,End "<<rowNumber<<" "<<startColNumber<<" "<<endColNumber<<endl;
            if (i == 0)
            {
                startIndex = ((long long int)rowNumber << 32) | (long long int)startColNumber;
                endIndex = ((long long int)rowNumber << 32) | (long long int)endColNumber;
                usedCellCount = endIndex - startIndex + 1;
            }
            else
            {
                int tempStartIndex = ((long long int)rowNumber << 32) | (long long int)startColNumber;
                int tempStopIndex = ((long long int)rowNumber << 32) | (long long int)endColNumber;
                if (tempStartIndex < startIndex && tempStopIndex < stopIndex)
                {
                    // Update both
                    startIndex = tempStartIndex;
                    stopIndex = tempStopIndex;
                }
                else if (tempStartIndex < startIndex && tempStopIndex >= stopIndex)
                {
                    // Update only the start index
                    startIndex = tempStartIndex;
                }
                else if (tempStartIndex >= startIndex && tempStopIndex >= stopIndex)
            }
//            for (long int k = startColNumber; k <= endColNumber; k++)
//            {
//                long long int temp = ((long long int)rowNumber << 32) | (long long int)k;
//                cout <<"k: "<<k<<" temp is: "<<temp<<endl;
//                usedCellNumbers.push_back(temp);
//            }
    }
    // Find all the Unique Entries in the usedCellNumbers vector
    cout<<"Total Used Cell: "<<usedCellNumbers.size()<<endl;
    std::set<long long int> uniqueUsedCellNumber(usedCellNumbers.begin(),usedCellNumbers.end());
    cout<<"Unique Used Cell: "<<uniqueUsedCellNumber.size()<<endl;
    long long int uniqueUsedCellNumberCount = uniqueUsedCellNumber.size();
    nLamps = maxPossibleLocations - uniqueUsedCellNumberCount;
    return nLamps;
}

int main()
{
    long int nRows,nCols;
    int nTracks;
    cin >> nRows;
    cin >> nCols;
    cin >> nTracks;
    vector< vector <long int> > tracks (nTracks,vector<long int>(INPUT_WIDTH,0));
    for (int i = 0; i < nTracks; i++)
    {
        for (int j = 0;j < INPUT_WIDTH; j++)
        {
            cin >> tracks[i][j];
        }
    }
    long long int result =  computeNLampPositions(tracks,nRows,nCols);
    cout << result;
    return 1;
}
