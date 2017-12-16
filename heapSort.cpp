#include <iostream>
#include <vector>

using namespace std;


void maxHeapify(vector<int>& input, int parent, int heapSize)
{
	int leftChild = 2*parent;
	int rightChild = leftChild + 1;
	int largest = 0;
	int largestIndex;
	if (leftChild < heapSize)
	{
		largest = input[leftChild];
		largestIndex = leftChild;
	}
	if (rightChild < heapSize)
	{
		if (input[rightChild] > largest)
		{
			largest = input[rightChild];
			largestIndex = rightChild;
		}
	}
	//cout <<"Input Node is: "<<input[parent]<<" Left Index is"<<leftChild<<" "<<rightChild<<endl;		
	if (input[parent] < largest)
	{
		int temp = input[parent];
		input[parent] = input[largestIndex];
		input[largestIndex] = temp;
		//Now Call max heapify on the left child node
		maxHeapify(input,largestIndex,heapSize);
	}
	return;
}

void buildMaxHeap(vector<int>& input)
{
	int n = input.size();	
	for (int i = n/2; i > 0; i--)
	{
		maxHeapify(input,i,n);
	}
	return;
}
/*
*	The Complexity is O(N) + O(N LOG N) ~ O(N LOG(N))
*/
void heapSort(vector<int>& input)
{
	// First Step is to build a Max Heap out of the input array
	buildMaxHeap(input);// O(n)
	int heapSize = input.size();
	int j = 1;
	// This loop is n * O(log n) = O(nlogn)
	for (int i = input.size() - 1; i >= 2 ;i--)
	{
		// Exchange input[1] with input[i]
		int temp = input[1];
		input[1] = input[i];
		input[i] = temp;
		heapSize--;
		maxHeapify(input,1,heapSize);// O(log n)

	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> input(n+1,0);
	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}
	//buildMaxHeap(input);
	heapSort(input);
	//cout << "Max Heap is: "<<endl;
	for (int i = 1; i <= n; i++)
	{
		cout << input[i] << " ";
	}
	cout<<endl;
}