#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int countMinSwapsOptm(vector<long long int> input)
{
	int swap_as = 0;
	int swap_des = 0;
	int swap = 0;
	// Sort the input in both acsending and descending order
	vector<long long int> input_ascending(input.size());
	vector<long long int> input_descending(input.size());
	std::copy(input.begin(),input.end(),input_ascending.begin());
	std::sort(input_ascending.begin(),input_ascending.end());
	std::reverse_copy(input_ascending.begin(),input_ascending.end(),input_descending.begin());
	unordered_map<long long int, int> inputMap, inputMap1;
	for (int i = 0; i < input.size(); i++)
	{
		inputMap[input[i]] = i;
		inputMap1[input[i]] = i;
	}
	vector<long long int> inputCopy(input.size());
	copy(input.begin(),input.end(),inputCopy.begin());
	for (int i = 0 ; i < input.size(); i++)
	{	
		//cout<<"Input is: "<<input[i]<<" and ascending is: "<<input_ascending[i]<<endl;	
		//print the map
		//cout<<"Map is: "<<endl;
		/*for (auto it = inputMap.begin(); it != inputMap.end(); ++it)
		{
			cout<<it->first << " --> "<<it->second<<endl;
		}*/
		if (input[i] != input_ascending[i])
		{
			//swap
			int position = inputMap[input_ascending[i]];
			// swap input[i] with input[position] and increament swap count
			long long int temp = input[position];
			input[position] = input[i];
			input[i] = temp;
			//cout<<"Swapping : "<<input[i]<<" with "<<input[position]<<endl;
			/*for (int ii = 0; ii < input.size(); ii++)
			{
				cout<<input[ii]<<",";
			}
			cout<<endl;*/
			// update the map
			//cout<<input[i]<<" Position Before Updating: "<<position<<endl;
			inputMap[input[position]] = position;
			inputMap[temp] = i;
			// increament the swap 
			swap_as++;
		}
	}
	for (int i = 0; i < inputCopy.size(); i++)
	{
		if (inputCopy[i] != input_descending[i])
		{
			//cout<<"Input is: "<<inputCopy[i]<<" and ascending is: "<<input_ascending[i]<<endl;	
			//print the map
			/*cout<<"Map is: "<<endl;
			for (auto it = inputMap1.begin(); it != inputMap1.end(); ++it)
			{
				cout<<it->first << " --> "<<it->second<<endl;
			}*/
			int position = inputMap1[input_descending[i]];
			// swap input[i] with input[position] and increament swap count
			long long int temp = inputCopy[position];
			inputCopy[position] = input[i];
			inputCopy[i] = temp;
			/*cout<<"Swapping : "<<inputCopy[i]<<" with "<<inputCopy[position]<<endl;
			for (int ii = 0; ii < inputCopy.size(); ii++)
			{
				cout<<inputCopy[ii]<<",";
			}
			cout<<endl;*/
			// update the map
			inputMap1[inputCopy[position]] = position;
			inputMap1[temp] = i;
			// increament the swap 
			swap_des++;
		}
	}
	// Find the minimum swaps from ascending and descending
	if (swap_as < swap_des)
	{
		swap = swap_as;
	}
	else{
		swap = swap_des;
	}
	return swap;

}
int main()
{
	int nElements;
	cin >> nElements;
	vector<long long int> _ar(nElements);
	for (int i = 0; i < nElements; i++)
	{
		cin>>_ar[i];
	}
	int result = countMinSwapsOptm(_ar);
	cout<<result<<endl;
}
