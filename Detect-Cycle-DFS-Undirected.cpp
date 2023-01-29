#include<iostream>
#include<vector>
using namespace std;

int ans;

void dfs_cycle(vector<vector<int>> &graph, int start, vector<bool> &visited, int parent){
    visited[start] = true;

    for(int i: graph[start]){
        if(visited[i] == false){
            dfs_cycle(graph, i, visited, start);
        }
        else{
            if(i != parent){
                ans = 1;
                return;
            }
        }
    }
}

int main(){
    vector<vector<int>> graph(3, vector<int>());
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(0);
    graph[2].push_back(1);

    vector<bool> visited(3,false);
    for(int i=0; i<3; i++){
        ans = 0;
        if(visited[i] == false){
            dfs_cycle(graph, i, visited, -1);
            if(ans == 1){
                cout<<"Cycle Detected";
            }
        }
    }

    return 0;
}