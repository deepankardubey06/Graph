#include<iostream>
#include<vector>
using namespace std;

void displayGraph(vector<vector<int>> &graph){
    for(int i=1; i<graph.size(); i++){
        cout<<i<<"->";
        for(int j=0; j<graph[i].size(); j++){
            cout<<graph[i][j]<<"->";
        }
        cout<<endl;
    }
}

int main(){
    int v,e;
    cout<<"Vertices :- ";
    cin>>v;
    cout<<"Edges :- ";
    cin>>e;
    vector<vector<int>> graph(v+1 ,vector<int>());
    // {{ },{ },{ },{ },{ }}
    //   0   1   2   3   4
    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    // {{ },{2,3},{1,4},{4,1},{2,3}}
    //   0    1     2     3     4
    displayGraph(graph);

    return 0;
}