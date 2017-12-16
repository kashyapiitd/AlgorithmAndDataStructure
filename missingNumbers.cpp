#include <iostream>
#include <vector>

using namespace std;

#define LARGEST_NUMBER 10000

int main()
{	
	int size_A;
	int size_B;
	cin >> size_A;
	vector<int> A(size_A);
	for (int i = 0 ; i < size_A; i++)
	{
		cin >> A[i];
	}
	cin >> size_B;
	vector<int> B(size_B);
	for (int i = 0 ; i < size_B; i++)
	{
		cin >> B[i];
	}
	int countMissingElements = size_B - size_A;
	vector<int> count_A(LARGEST_NUMBER + 1,0);
	vector<int> count_B(LARGEST_NUMBER + 1,0);
	vector<int> missingList;
	for (int i = 0 ; i < size_A; i++)
	{
		count_A[A[i]]++;
	}
	for (int i = 0 ; i < size_B; i++)
	{
		count_B[B[i]]++;
	}
	int localCountMissingElements = 0;
	for (int i = 0 ; i < LARGEST_NUMBER + 1; i++)
	{
		bool result = count_A[i] ^ count_B[i];
		if (result != 0)
		{
			// Differnce in result
			int count = count_B[i] - count_A[i];
			missingList.push_back(i);
			localCountMissingElements += count;
		}
		if (localCountMissingElements == countMissingElements)
			break;
	}
	// Print the result
	for (int i = 0 ; i < missingList.size(); i++)
	{
		cout << missingList[i]<<" ";
	}
	cout << endl;
}
