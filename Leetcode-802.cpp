#include<iostream>
#include<vector>

using namespace std;
int flag;

void dfs(vector<vector<int>> &graph, int start, vector<bool> &visited){
    if(visited[start] == true){
        flag = 1;
        return;
    }
    visited[start] = true;
    for(int i: graph[start]){
        if(flag == 0){
            dfs(graph, i, visited);
        }
    }
    visited[start] = false;
}

int main(){
    vector<vector<int>> graph = { { 1, 2 }, { 2, 3 }, { 5 }, { 0 }, { 5 }, { }, { } };
    vector<bool> visited(graph.size(), false);
    for(int i=0; i<graph.size(); i++){
        flag = 0;   //No Cycle
        dfs(graph, i, visited);
        if(flag == 0){
            cout<<i<<endl;
        }
    }
    return 0;
}