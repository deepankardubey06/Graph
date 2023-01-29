// Detect Cycle in Directed Graph using Graph Coloring Algorithm
#include<iostream>
#include<vector>
using namespace std;

bool checkCycle(vector<vector<int>> &graph, int curr, vector<int> &visited)
{
    if (visited[curr] == 2)
    {
        return true;
    }

    visited[curr] = 2;

    for (int i : graph[curr])
    {
        if (visited[i] != 1)
        {
            bool ans;
            ans = checkCycle(graph, i, visited);
            if (ans == true)
            {
                return true;
            }
        }
    }

    visited[curr] = 1;
    return false;
}

int main(){
    vector<vector<int>> graph(3, vector<int>());
    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(1);

    vector<int> visited(3, 0);
    for (int i = 0; i < 3; i++)
    {
        if (visited[i] == 0)
        {
            bool finalans;
            finalans = checkCycle(graph, i, visited);
            if (finalans == true)
            {
                cout<<"Cycle Detected"<<endl;
            }
        }
    }
    return 0;
}