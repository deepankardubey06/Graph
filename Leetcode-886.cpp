#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void createGraph(vector<vector<int>> &dislikes, vector<vector<int>> &graph){
    for(int i=0; i<dislikes.size(); i++){
        graph[dislikes[i][0]].push_back(dislikes[i][1]);
        graph[dislikes[i][1]].push_back(dislikes[i][0]);
    }
}

bool possibleBipartition(int n, vector<vector<int>> &dislikes){
    vector<vector<int>> graph(n + 1, vector<int>());
    createGraph(dislikes, graph);

    vector<int> color(n + 1, 0);
    for(int i=1; i<graph.size(); i++){
        if(color[i] == 0){
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while(!q.empty()){
                int t = q.front();
                q.pop();
                for(int neighbour: graph[t]){
                    if(color[t] == color[neighbour]){
                        return false;
                    }
                    if(color[neighbour] == 0){
                        
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> dislikes = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4 , 5}, {1 , 5} };
    cout<<possibleBipartition(5 , dislikes); 
    return 0;
}