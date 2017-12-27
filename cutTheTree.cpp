#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;
//#define PRINT_ADJ_MATRIX
enum vertexColor {WHITE, BLACK, GREY};
class Vertex
{
public:
    int id;
    int data;
    Vertex(){};
    ~Vertex(){};
    Vertex(int id, int data)
    {
        this -> id = id;
        this -> data = data;
    }
    bool operator == (const Vertex &  other)const
    {
        return (id == other.id && data == other.data);
    }

};
struct VertexHashser
{
    size_t operator ()(const Vertex &  other) const
    {
        return other.id;
    }
};
class Graph
{
public:
    int nVertex;
    int nEdges;
    int score = 0;
    int minScore ;
    int minScoreForOneStartVertex;
    int sumOfWeights;
    int halfSum;
    vector<Vertex> vertexList;
    vector<int> subTreeWeight;
    unordered_map<int, vertexColor> alreadyVisitedVertex;
    vector<vector<int> > adjMatrix;
    Graph(){};
    ~Graph(){};
    Graph(int nVertex)
    {
        this -> nVertex = nVertex;
        vertexList.resize(nVertex + 1);
        adjMatrix.resize(nVertex+1);
        subTreeWeight.resize(nVertex + 1, 0);
    }
    void findMinDiff(int startVertex);
    void DFSVisit(int startVertex);
    void findWeightOfSubTree();
    void exploreEdgesOfGraph();
};
void Graph::exploreEdgesOfGraph()
{
    // Explore the Edges of the graph using the adjMatrix

}
void Graph::findWeightOfSubTree()
{
    // Start at the root node and find the weight of the subtrees
    // starting at each vertex.
    // Vertex 1 is assumed to be the start vertex
    int startVertex = 1;
    DFSVisit(startVertex);

}
int main()
{
    int nVertex;
    int sumOfWeights = 0;
    int weights;
    int startVertex;
    cin >> nVertex;
    Graph graph(nVertex);
    // Put the id and the data for each vertex
    for (int i = 0 ; i < nVertex; i++)
    {
        graph.vertexList[i+1].id = i+1;
        graph.alreadyVisitedVertex[i+1] = WHITE;
        cin >> weights;
        graph.vertexList[i+1].data = weights;
        sumOfWeights += weights;
    }
    // Get the Connections and put it in the adjMatrix
    for (int i = 0; i < nVertex - 1; i++)
    {
        int first, second;
        cin >> first;
        //if (i == 0)
            //startVertex = first;
        cin >> second;
        graph.adjMatrix[first].push_back(second);
        graph.adjMatrix[second].push_back(first);
    }
    #ifdef PRINT_ADJ_MATRIX
    // Print out the adjMatrix
    for (int i = 0; i < graph.adjMatrix.size(); i++)
    {
        cout << i << "-->";
        for (int j = 0 ; j < graph.adjMatrix[i].size(); j++)
        {
            cout << graph.adjMatrix[i][j] << ",";
        }
        cout << endl;
    }
    #endif // PRINT_ADJ_MATRIX
    graph.sumOfWeights = sumOfWeights;
    graph.minScore = sumOfWeights;
    graph.halfSum = sumOfWeights >> 1;
    graph.findWeightOfSubTree();
    for (int i = 1; i <= graph.nVertex; i++)
    {
        cout << graph.subTreeWeight[i] << ",";
    }
    cout << endl;
    //graph.findMinDiff(startVertex);
    //cout << sumOfWeights << endl;
    //cout << graph.minScoreForOneStartVertex << endl;
    return 1;

}
// Class function definations
/* void Graph::findMinDiff(int startVertex)
 * {
 *
 *     // Do a DFS on the vertexes starting from node 1
 *     //int startVertex = 1;
 *
 *     for (int i = 1 ; i <= nVertex; i++)
 *     {
 *         score = 0;
 *         minScore = sumOfWeights;
 *         for (int j = 0 ; j < alreadyVisitedVertex.size(); j++)
 *         {
 *             alreadyVisitedVertex[j] = false;
 *         }
 *         DFSVisit(i);
 *         cout << "Score for Vertex: "<<i<<" :"<<minScore<<endl;
 *         if (i == 1)
 *             minScoreForOneStartVertex = minScore;
 *         else
 *         {
 *             if (minScore < minScoreForOneStartVertex)
 *                 minScoreForOneStartVertex = minScore;
 *         }
 *
 *     }
 *     return;
 * }
 */
void Graph::DFSVisit(int startVertex)
{
    if (alreadyVisitedVertex[startVertex] == WHITE)
    {
        //cout << "DFSVisit called with Vertex: "<<startVertex<<endl;
        alreadyVisitedVertex[startVertex] = GREY;
        vector<int> adjList = adjMatrix[startVertex];
        for (int i = 0 ; i < adjList.size(); i++)
        {
            DFSVisit(adjList[i]);
        }
        //cout << "Explored  all sub-trees of : "<<startVertex<<endl;
        subTreeWeight[startVertex] = vertexList[startVertex].data;
        for (int i = 0 ; i < adjList.size(); i++)
        {
            if (alreadyVisitedVertex[adjList[i]] == BLACK)
                subTreeWeight[startVertex] += subTreeWeight[adjList[i]];
        }
        alreadyVisitedVertex[startVertex] = BLACK;
    }
    return;
}
/* void Graph::DFSVisit(int startVertex)
 * {
 *     //cout << "DFSVisit called with Vertex: "<<startVertex<<endl;
 *     // Check if we have already visited this vertex
 *     if (alreadyVisitedVertex[startVertex] == false)
 *     {
 *         alreadyVisitedVertex[startVertex] = true;
 *         score += vertexList[startVertex].data;
 *         if (score >= halfSum )
 *         {
 *             //cout << score << endl;
 *             int diff = abs(score - (sumOfWeights - score));
 *             //cout << diff << " "<<sumOfWeights<<" "<<minScore<<endl;
 *             if (diff  < minScore)
 *             {
 *                 minScore = diff;
 *             }
 *             score -= vertexList[startVertex].data;
 *             //cout << score << endl;
 *             //return;
 *         }
 *         else
 *         {
 *             // This Vertex is not visited before.
 *             // go ahead and visit
 *             vector<int> adjList = adjMatrix[startVertex];
 *             for (int i = 0 ; i < adjList.size(); i++)
 *             {
 *                 DFSVisit(adjList[i]);
 *             }
 *         }
 *
 *
 *     }
 *     //cout << startVertex<<" already Visited"<<endl;
 *     return;
 * }
 */
