#include <iostream>
#include <vector>
#include <unordered_map> 
#include <algorithm>

using namespace std;


class Cell
{
public:
	int x_coordinate;
	int y_coordinate;
	Cell(){};
	~Cell(){};
	Cell(int x, int y)
	{
		x_coordinate = x;
		y_coordinate = y;
	}
	bool operator == (const Cell& obj)const
	{
		return  (x_coordinate == obj.x_coordinate && y_coordinate == obj.y_coordinate);
			
	}
};
struct KeyHasher
{
	std::size_t operator()(const Cell& cell) const
	{
		return (cell.x_coordinate << 8 | cell.y_coordinate);
	}
};
int computeShortestDistanceBFS(unordered_map<Cell, vector<Cell>, KeyHasher >& adjMatrix, Cell startIndex, Cell endIndex)
{		
	int shortestDistance;
	vector<Cell> alreadyVisitedVertices;
	vector<int> levelOfVertices;
	vector<Cell> currentList;
	vector<Cell> nextToVisitList;
	int level = 0;
	currentList.push_back(startIndex);
	while (currentList.size() > 0)
	{
		int currentListIndex = 0;
		nextToVisitList.clear();
		while(currentListIndex < currentList.size())
		{
			Cell nextVertex = currentList[currentListIndex];
			if (find(alreadyVisitedVertices.begin(),alreadyVisitedVertices.end(),nextVertex) == alreadyVisitedVertices.end())
			{
				// We have not visited this vertex before
				alreadyVisitedVertices.push_back(nextVertex);
				// Push back the level
				levelOfVertices.push_back(level);
				//if (nextVertex == endIndex)
				//	shortestDistance = level;
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
	int endElementIndex = -1;
	for (int i  = 0 ; i < alreadyVisitedVertices.size(); i++)
	{
		if (alreadyVisitedVertices[i] == endIndex)
		{
			endElementIndex = i;
			break;
		}
	}
	if (endElementIndex == -1)
	{
		shortestDistance = -1;
	}
	else
	{
		shortestDistance = levelOfVertices[endElementIndex];
	}
	return shortestDistance;

}

vector<Cell> computeNextPossibleStatesFromCurrentState(Cell current, int x_allowed, int y_allowed , int n)
{
	vector<Cell> possibleStates;
	Cell allowedMoves;
	int count = 0;
	while(count < 2){
		if (count == 0)
		{
			allowedMoves.x_coordinate = x_allowed;
			allowedMoves.y_coordinate = y_allowed;
		}
		else
		{
			allowedMoves.x_coordinate = y_allowed;
			allowedMoves.y_coordinate = x_allowed;
		}
		bool isIncreamentAllowedInXDir = true;
		bool isDecreamentAllowedInXDir = true;
		bool isIncreamentAllowedInYDir = true;
		bool isDecreamentAllowedInYDir = true;
		if (current.x_coordinate + allowedMoves.x_coordinate > n-1)
			isIncreamentAllowedInXDir = false;
		if (current.x_coordinate < allowedMoves.x_coordinate)
			isDecreamentAllowedInXDir = false;
		if (current.y_coordinate + allowedMoves.y_coordinate > n-1)
			isIncreamentAllowedInYDir = false;
		if (current.y_coordinate < allowedMoves.y_coordinate)
			isDecreamentAllowedInYDir = false;
		if (isIncreamentAllowedInXDir and isIncreamentAllowedInYDir)
		{
			Cell temp(current.x_coordinate + allowedMoves.x_coordinate , current.y_coordinate + allowedMoves.y_coordinate);
			possibleStates.push_back(temp);
		}
		if (isDecreamentAllowedInXDir and isDecreamentAllowedInYDir)
		{
			Cell temp(current.x_coordinate - allowedMoves.x_coordinate , current.y_coordinate - allowedMoves.y_coordinate);
			possibleStates.push_back(temp);
		}
		if (isIncreamentAllowedInXDir and isDecreamentAllowedInYDir)
		{
			Cell temp(current.x_coordinate + allowedMoves.x_coordinate , current.y_coordinate - allowedMoves.y_coordinate);
			possibleStates.push_back(temp);
		}
		if (isDecreamentAllowedInXDir and isIncreamentAllowedInYDir)
		{
			Cell temp(current.x_coordinate - allowedMoves.x_coordinate , current.y_coordinate + allowedMoves.y_coordinate);
			possibleStates.push_back(temp);
		}
		count++;
	}
	return possibleStates;
}
int main()
{
	int size;
	cin >> size;
	int nCells = size * size;
	Cell startCell(0,0);
	Cell endCell(size -1 , size -1);
	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			int x_allowed = i;
			int y_allowed = j;
			unordered_map<Cell, vector<Cell> , KeyHasher> adjMatrix;
			for (int inner_i = 0; inner_i < size; inner_i++)
			{
				for (int inner_j = 0; inner_j < size; inner_j++)
				{
					Cell currentCell(inner_i,inner_j);
					//cout <<"computeNextPossibleStatesFromCurrentState Called\n";
					adjMatrix[currentCell] = computeNextPossibleStatesFromCurrentState(currentCell,x_allowed,y_allowed,size);
					//cout <<"computeNextPossibleStatesFromCurrentState Returned\n";
				}
			}
			// The adjMatrix is the respresentation of the graph which has all the possible transitions from each cell
			// of the chess board given the x_allowed and y_allowed.
			// Once this graph representation is done, we need to find the minimum number of steps for the knight to travel 
			// from the startCell to the endCell.
			// We will use BFS for this. The Level of the vertex 'endCell' will be the shortest distance from the startCell to the 
			// endCell.
			int shortestDistance = computeShortestDistanceBFS(adjMatrix, startCell, endCell);
			cout << shortestDistance <<" ";
		}
		cout << endl;
	}
}