#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void createGraph(vector<vector<int>> &graph, vector<vector<int>> &paths){
    for(int i=0; i<paths.size(); i++){
        graph[paths[i][0]].push_back(paths[i][1]);
        graph[paths[i][1]].push_back(paths[i][0]);
    }
}

vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
{
    vector<vector<int>> graph(n + 1, vector<int>());
    createGraph(graph, paths);
    vector<int> color(n + 1,0);

    for(int i=1; i<graph.size(); i++){
        if(color[i] == 0){
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while(!q.empty()){
                int temp =  q.front();
                q.pop();
                for(int neighbour: graph[temp]){
                    
                }
            }
        }
    }
}

int main(){
    return 0;
}