#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	int nElements;
	int diff;
	int nPairs = 0;
	cin >> nElements;
	cin >> diff;
	vector<int>arr(nElements);
	for (int i = 0; i < nElements; i++)
	{
		cin >> arr[i];
	}
	unordered_map <int, int> indexToCountMap;
	for (int i = 0 ; i < nElements; i++)
	{
		int first = arr[i] - diff;
		bool firstFound = false;
		int second = arr[i] + diff;
		bool secondFound = false;
		if (first > 0)
		{
			if (indexToCountMap.find(first) != indexToCountMap.end())
			{
				nPairs++;
				firstFound = true;
			}
		}
		if (indexToCountMap.find(second) != indexToCountMap.end())
		{
			nPairs++;
			secondFound = true;
			
		}
		if (! firstFound || !secondFound)
		{
			indexToCountMap[arr[i]]++;
		}
	}
	cout << nPairs <<endl;
	return 1;
}