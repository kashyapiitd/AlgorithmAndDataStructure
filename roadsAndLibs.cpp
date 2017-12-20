#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int,bool> alreadyVisitedCity;

int DFSVisit(vector<vector<int>>& adjMatrix, int startCity);

long long int  DFS(vector<vector<int>>& adjMatrix, int nCities, int cRoad, int cLib)
{
	int nConnectedCities;
	int totalCitiesVisited = 0;
	long long int  totalCost = 0;
	for (int i = 1; i <= nCities; i++)
	{
		nConnectedCities = 0;
		if (totalCitiesVisited == nCities)
			break;
        if (alreadyVisitedCity[i] == false)
		//if (find(alreadyVisitiedCity.begin(),alreadyVisitiedCity.end(),i) == alreadyVisitiedCity.end())
		{
			// Go and visit the City
			//alreadyVisitedCity[i] = true;
			nConnectedCities =  DFSVisit(adjMatrix,i);
		}
		//cout << "i is: "<<i <<" and nConnected Cities are: "<<nConnectedCities<<endl;
		//cout << ((long long int )(nConnectedCities - 1)) * ((long long int )cRoad) + (long long int )cLib <<endl;
		if (nConnectedCities > 0)
            totalCost = totalCost + (((long long int )(nConnectedCities - 1)) * ((long long int )cRoad) + (long long int )cLib);
        totalCitiesVisited += nConnectedCities;
	}
	//cout << totalCost <<endl;
	//cout << totalCitiesVisited << endl;
	//nConnectedCities = alreadyVisitiedCity.size();
	if (totalCitiesVisited < nCities)
    {
        // If the Cities cannot be connected, place a library in each city
        //cout << ((long long int)( nCities - totalCitiesVisited) * (long long int) cLib) << endl;
        totalCost += ((long long int)( nCities - totalCitiesVisited) * (long long int) cLib);
    }
	return totalCost;
}

int DFSVisit(vector<vector<int>>& adjMatrix, int startCity)
{
    //cout << "DFSVisit with city: "<<startCity<<endl;
	int nCitiesTouched = 0;
	vector<int> cititesToVisit = adjMatrix[startCity];
	for (int i = 0 ; i < cititesToVisit.size(); i++)
	{
		// Check if we have already visited the city
		if (alreadyVisitedCity[cititesToVisit[i]] == false)
		//if (find(alreadyVisitiedCity.begin(),alreadyVisitiedCity.end(),cititesToVisit[i]) == alreadyVisitiedCity.end())
		{
			// Go ahead and visit the city
			nCitiesTouched ++;
			//alreadyVisitiedCity.push_back(cititesToVisit[i]);
			alreadyVisitedCity[cititesToVisit[i]] = true;
			nCitiesTouched += DFSVisit(adjMatrix, cititesToVisit[i]);
		}
	}
	return nCitiesTouched;
}

int main()
{
	int nTestCases;
	cin >> nTestCases;
	for (int i = 0 ; i < nTestCases; i++)
	{
    	int nCities, nRoads, cRoad, cLib;
    	cin >> nCities;
    	cin >> nRoads;
    	cin >> cLib;
    	cin >> cRoad;
    	alreadyVisitedCity.clear();
    	for (int i = 0 ; i < nCities; i++)
        {
            alreadyVisitedCity[i+1] = false;
        }
    	vector<vector<int>> adjMatrix(nCities+1);
    	for (int i = 0 ; i < nRoads; i++)
    	{
    		int startCity, endCity;
    		cin >> startCity;
    		cin >> endCity;
    		// Put into the adjacency list
    		adjMatrix[startCity].push_back(endCity);
    		adjMatrix[endCity].push_back(startCity);
    	}
    	/*for (int i = 0 ; i <= nCities; i++)
        {
            cout << i << " ";
            for (int j = 0 ; j < adjMatrix[i].size(); j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }*/
    	long long int totalCostOfMakingLibraryInEachCity = (long long int) nCities * (long long int)cLib;
    	long long int totalCost = DFS(adjMatrix,nCities,cRoad,cLib);
    	//cout << "totalCostOfMakingLibraryInEachCity: "<<totalCostOfMakingLibraryInEachCity<<endl;
    	//cout << "totalCost: "<<totalCost<<endl;
    	(totalCostOfMakingLibraryInEachCity < totalCost) ? cout << totalCostOfMakingLibraryInEachCity << endl : cout << totalCost <<endl;

    }
    return 1;
}
