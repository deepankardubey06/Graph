#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> finalans;

void dfs(vector<vector<int>> &graph, int start ,vector<int> &ans){
    if(graph[start].size() == 0){
        ans.push_back(start);
        vector<int> temp = ans;
        finalans.push_back(temp);
        ans.pop_back();
    }
    ans.push_back(start);
    for(int i: graph[start]){
        dfs(graph, i, ans);
    }
    ans.pop_back();
}

void display(vector<vector<int>> &arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> graph = { { 1, 2 }, {3}, {3}, {} };
    graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    vector<int> ans;
    dfs(graph, 0, ans);
    display(finalans);
    return 0;
}