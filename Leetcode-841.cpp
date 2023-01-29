#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(vector<vector<int>> &graph,int start, vector<bool> &rooms){
    if(rooms[start] == true){
        return;
    }
    rooms[start] = true;
    for(int i: graph[start]){
        dfs(graph, i, rooms);
    }
}

int main(){
    vector<vector<int>> graph = { {1}, {2}, {3}, {} };
    graph = {{ 1, 3 }, { 3, 0, 1 }, {2}, {0}}; 
    vector<bool> rooms(graph.size(), false);
    dfs(graph, 0, rooms);
    if(find(rooms.begin(), rooms.end(), false) == rooms.end()){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}