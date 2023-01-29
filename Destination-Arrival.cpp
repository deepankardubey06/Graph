#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int mini = 10000;
int totalPaths = 0;
vector<vector<pair<int,int>>> createGraph(int n, vector<vector<int>> &roads){
    vector<vector<pair<int,int>>> graph(n, vector<pair<int,int>>());
    for(int i=0; i<roads.size(); i++){
        pair<int,int> p;
        p.first = roads[i][1];
        p.second = roads[i][2];
        graph[roads[i][0]].push_back(p);
        pair<int,int> p2;
        p2.first = roads[i][0];
        p2.second = roads[i][2];
        graph[roads[i][1]].push_back(p2);
    }
    return graph;
}

void display(vector<vector<pair<int, int>>> &graph){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<"->";
        for(int j=0; j<graph[i].size(); j++){
            cout<<"("<<graph[i][j].first<<","<<graph[i][j].second<<")"<<" ";
        }
        cout<<endl;
    }
}

void dfs(int start, int end, vector<vector<pair<int, int>>> &graph, vector<int> visi,int count,string str){
    str += to_string(start) + " ";
    visi[start] = 1;
    if(count > mini){
        return;
    }
    if(start == end){
        mini = min(count,mini);
        totalPaths += 1;
        cout<<str<<endl;
        return;
    }
    for(int i=0; i<graph[start].size(); i++){
        if(visi[graph[start][i].first] == 0){
            dfs(graph[start][i].first, end, graph, visi, count + graph[start][i].second, str);
        }
    }
}

void countPaths(int n, vector<vector<int>> &roads)
{
    vector<vector<pair<int, int>>> graph;
    graph = createGraph(n,roads);
    // display(graph);
    // cout<<endl;
    vector<int> visi(n,0);
    dfs(0, n-1, graph, visi, 0, "");
}

int main(){
    vector<vector<int>> roads = {{ 0, 6, 7 }, { 0, 1, 2 }, { 1, 2, 3 }, { 1, 3, 3 }, { 6, 3, 3 }, { 3, 5, 1 }, { 6, 5, 1 }, { 2, 5, 1 }, { 0, 4, 5 }, { 4, 6, 2 }}; 
    countPaths(7, roads);
    cout<<totalPaths<<"Ttal";
    return 0;
}