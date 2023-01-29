#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;
void dfs(vector<vector<int>> &graph,int source, vector<int> &visited){
    ans.push_back(source);
    visited[source] = 1;

    for(int i: graph[source]){
        if(visited[i] == 0){
            dfs(graph, i, visited);
        }
    }
}

    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{

    vector<vector<int>> graph(n, vector<int>{});
    // This will create a graph
    for (int i = 0; i < edges.size(); i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    // {{1,2} {0,2} {1,0}}
    //   0      1     2
    vector<int> visited(n,0);
    dfs(graph, source, visited);
    if(find(ans.begin(), ans.end(), destination) == ans.end()){
        return false;
    }
    return true;
}

int main(){
    return 0;
}