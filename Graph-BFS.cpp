#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void displayGraph(vector<vector<int>> &graph){
    for (int i = 1; i < graph.size(); i++){
        cout << i << "->";
        for (int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << "->";
        }
        cout << endl;
    }
}

void graphBFS(vector<vector<int>> &graph, int source){
    // {{ },{2,3},{1,4},{4,1},{2,3}}
    //   0    1     2     3     4

    // {{0},{0},{0},{0},{0}}
    //   0   1   2   3   4
    vector<int> visited(graph.size(),0);
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while(!q.empty()){
        int vertex = q.front();
        q.pop();

        cout<<vertex<<" ";

        for(int i: graph[vertex]){
            if(visited[i] == 0){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<vector<int>> createGraph(int v, int e){
    cout << "Vertices :- "<<v<<endl;
    cout << "Edges :- "<<e<<endl;
    vector<vector<int>> graph(v + 1, vector<int>());
    // Creating An Undirected Graph
    // {{ },{ },{ },{ },{ }}
    //   0   1   2   3   4
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    // {{ },{2,3},{1,4},{4,1},{2,3}}
    //   0    1     2     3     4
    return graph;
}

int main(){
    vector<vector<int>> graph;
    graph = createGraph(4,4);
    // displayGraph(graph);
    graphBFS(graph, 1);
    return 0;
}