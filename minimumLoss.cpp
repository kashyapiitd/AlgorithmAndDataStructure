#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class House
{
public:
	long long int price;
	int index;
};

int main()
{
	int nDays;
	long long int minLoss = (long long int)100000000 * (long long int)100000000;
	cin >> nDays;
	vector<House> arr(nDays);
	for (int i = 0; i < nDays; i++)
	{
		House temp;
		cin >> temp.price;
		temp.index = i;
		arr[i] = temp;
	}
	sort(arr.begin(),arr.end(),[](House first, House second){return first.price > second.price;});
	for (int i = 0 ; i < nDays - 1; i++)
	{
		if (arr[i].index < arr[i+1].index && (arr[i].price - arr[i+1].price) < minLoss)
		{
			minLoss = arr[i].price - arr[i+1].price;
		}
	}
	cout << minLoss << endl;
	return 1;
}