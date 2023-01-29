#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> createGraph(int v, int e)
{
    cout << "Vertices :- " << v << endl;
    cout << "Edges :- " << e << endl;
    vector<vector<int>> graph(v + 1, vector<int>());
    // Creating An Undirected Graph
    // {{ },{ },{ },{ },{ }}
    //   0   1   2   3   4
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    // {{ },{2,3},{1,4},{4,1},{2,3}}
    //   0    1     2     3     4
    return graph;
}

void graphDFS(vector<vector<int>> &graph, int start, vector<int> &visited){

    cout<<start<<" ";
    visited[start] = 1;

    for(int i: graph[start]){
        if(visited[i] == 0){
            graphDFS(graph, i, visited);
        }
    }
}

void displayGraph(vector<vector<int>> &graph)
{
    for (int i = 1; i < graph.size(); i++)
    {
        cout << i << "->";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << "->";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> graph;
    vector<int> visited(10, 0);
    graph = createGraph(9, 8);
    // displayGraph(graph);
    graphDFS(graph, 1, visited);
    return 0;
}