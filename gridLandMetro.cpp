#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <set>
#include <stack>

using namespace std;

#define MAX_ROWS 1000000000
#define MAX_COLUMNS 1000000000
#define INPUT_WIDTH 3

long long int computeNUsedCells(unordered_map<long int, vector<pair <long int, long int> > > intervals)
{
    long long int nUsedCells = 0;
    unordered_map<long int, vector<pair <long int, long int> > > ::iterator it;
    for (it = intervals.begin(); it != intervals.end(); ++it)
    {
        stack<pair<long int, long int > > intervalStack;
        vector<pair <long int, long int> >intervalForOneRow = it->second;
        // Sort the intervals in ascending order of the lower limit
        sort(intervalForOneRow.begin(),intervalForOneRow.end(),[](pair<long int, long int> first , pair <long int, long int> second) {return first.first < second.first;});
        for (int i = 0; i < intervalForOneRow.size(); i++)
        {
            //cout<<"Interval is: "<<intervalForOneRow[i].first<<" to: "<<intervalForOneRow[i].second<<endl;
            if (intervalStack.size() == 0)
            {
                intervalStack.push(intervalForOneRow[i]);
            }
            else
            {
                // pop the first element out
                pair<long int, long int> tos = intervalStack.top();
                // Compare the new interval with the top of stack
                if (intervalForOneRow[i].first > tos.second)
                {
                    // No Overlap, Push interval onto stack
                    //intervalStack.push(tos);
                    intervalStack.push(intervalForOneRow[i]);
                }
                else if (intervalForOneRow[i].first >= tos.first && intervalForOneRow[i].second >= tos.second)
                {
                    // Modify the TOS
                    tos.second = intervalForOneRow[i].second;
                    intervalStack.pop();
                    intervalStack.push(tos);
                }
            }
        }
        // Processing is finished for one row. Proceed to the next row.
        // Before that, increament the number of unused cells
        int sizeStack = intervalStack.size();
        while(sizeStack > 0)
        {
            pair<long int, long int> tos = intervalStack.top();
            intervalStack.pop();
            long long int temp = (long long int) tos.second - (long long int) tos.first + (long long int) 1;
            nUsedCells += temp;
            sizeStack--;
        }
    }
    return nUsedCells;
}

long long int computeNLampPositions(vector< vector <long int> > tracks,long int nRows,long int nCols)
{
    long long int nLamps = 0;
    // First compute the maximum possible number of locations
    long long int maxPossibleLocations = (long long int)nRows * (long long int)nCols;
    //cout<<"Max Possible: "<<maxPossibleLocations<<endl;
    unordered_map<long int, vector<pair <long int, long int> > > intervals;
    for (int i = 0; i < tracks.size(); i++)
    {
            long int rowNumber = tracks[i][0];
            long int startColNumber = tracks[i][1];
            long int endColNumber = tracks[i][2];
            //cout<<"Row,Start,End "<<rowNumber<<" "<<startColNumber<<" "<<endColNumber<<endl;
            pair<long int, long int> tempPair = make_pair(startColNumber,endColNumber);
            intervals[rowNumber].push_back(tempPair);

    }
    long long int uniqueUsedCellNumberCount = computeNUsedCells(intervals);
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
