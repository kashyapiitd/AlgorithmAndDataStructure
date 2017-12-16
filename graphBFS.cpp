#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define NUMBER_VERTICES 5
void printVector(vector<int> input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout<<input[i]<<" , ";
    }
    cout<<endl;
}

void breadthFirstSearch(vector<vector<int> >& adjMatrix, int startIndex)
{		
	vector<int> alreadyVisitedVertices;
	vector<int> levelOfVertices;
	vector<int> currentList;
	vector<int> nextToVisitList;
	int level = 0;
	currentList.push_back(startIndex);
	while (currentList.size() > 0)
	{
		int currentListIndex = 0;
		nextToVisitList.clear();
		while(currentListIndex < currentList.size())
		{
			int nextVertex = currentList[currentListIndex];
			if (find(alreadyVisitedVertices.begin(),alreadyVisitedVertices.end(),nextVertex) == alreadyVisitedVertices.end())
			{
				// We have not visited this vertex before
				alreadyVisitedVertices.push_back(nextVertex);
				// Push back the level
				levelOfVertices.push_back(level);
				// Push back all the vertices that are reachable via the next vertex in the nextVisitList
				for (int inner = 0; inner < adjMatrix[nextVertex].size(); inner++)
				{
					nextToVisitList.push_back(adjMatrix[nextVertex][inner])	;
				} 
				//printVector(nextToVisitList);
			}
			currentListIndex++;
		}
		// Now go to the Next Level of Vertices.
		// Increament the level by 1
		level++;
		// Replace the Current List with the nextToVisitList
		currentList.clear();
		currentList.swap(nextToVisitList);
		nextToVisitList.clear();
	}
	printVector(alreadyVisitedVertices);
	printVector(levelOfVertices);
	return;

}
int main()
{
	vector<vector<int> > adjMatrix(NUMBER_VERTICES + 1);
	adjMatrix[1].push_back(5);
	adjMatrix[1].push_back(2);
	adjMatrix[2].push_back(1);
	adjMatrix[2].push_back(5);
	adjMatrix[2].push_back(4);
	adjMatrix[2].push_back(3);
	adjMatrix[3].push_back(2);
	adjMatrix[3].push_back(4);
	adjMatrix[4].push_back(3);
	adjMatrix[4].push_back(2);
	adjMatrix[4].push_back(5);
	adjMatrix[5].push_back(1);
	adjMatrix[5].push_back(2);
	adjMatrix[5].push_back(4);
	breadthFirstSearch(adjMatrix,1);
	return 0;	
}