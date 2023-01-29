#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> createGraph(int n, vector<vector<int>> &roads){
    vector<vector<int>> graph(n, vector<int>());

    for(int i=0; i<roads.size(); i++){
        graph[roads[i][0]].push_back(roads[i][1]);
        graph[roads[i][1]].push_back(roads[i][0]);
    }
    return graph;
}

void display(vector<vector<int>> &graph){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<"->";
        for(int j=0; j<graph[i].size(); j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void findInDegree(vector<vector<int>> &graph, vector<int> &InDeg){
    for(int i=0; i<graph.size(); i++){
        InDeg[i] = graph[i].size();
    }
}

void display2(vector<int> &InDeg){
    for(int i: InDeg){
        cout<<i<<" ";
    }
}

void maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    vector<vector<int>> graph(n, vector<int>());
    graph = createGraph(n, roads);
    // display(graph);
    int maxi = -100;

    vector<int> InDeg(n,0);
    findInDegree(graph, InDeg);
    // display2(InDeg);

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(find(graph[i].begin(), graph[i].end(), j) == graph[i].end()){
                maxi = max(InDeg[i] + InDeg[j], maxi);
            }
            else{
                maxi = max(InDeg[i] + InDeg[j] - 1, maxi);
            }
        }
    }
    cout<<maxi;
}

int main(){
    vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {5, 6}, {5, 7}};
    maximalNetworkRank(8,roads);
    return 0;
}