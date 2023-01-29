#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void createGraph(int n, vector<vector<int>> &edges, vector<vector<int>> &graph){
    for(int i=0; i<edges.size(); i++){
        graph[edges[i][0]].push_back(edges[i][1]);
    }
}

void display(vector<vector<int>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "->";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(n, vector<int>());
    createGraph(n, edges, graph);
    // display(graph);
    vector<int> InDeg(n, 0);
    vector<int> finalRes;

    for(int i=0; i<graph.size(); i++){
        for(int j=0; j<graph[i].size(); j++){
            InDeg[graph[i][j]] += 1;
        }
    }

    for(int i=0; i<InDeg.size(); i++){
        if(InDeg[i] == 0){
            finalRes.push_back(i);
        }
    }
}

int main(){
    vector<vector<int>> edges = {{ 0, 1 }, { 0, 2 }, { 2, 5 }, { 3, 4 }, { 4, 2 }};
    findSmallestSetOfVertices(6, edges);
    return 0;
}