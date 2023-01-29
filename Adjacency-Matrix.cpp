#include<iostream>
#include<vector>
using namespace std;

int main(){
    int v;
    int e;
    cout<<"Enter vertices:- ";
    cin>>v;
    cout<<"Enter Edges:- ";
    cin>>e;

    int graph[v+1][v+1];

    for(int i=0; i<v+1; i++){
        for(int j=0; j<v+1; j++){
            graph[i][j] = 0;
        }
    }


    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            int temp;
            cout<<"Enter Val:- ";
            cout<<i<<","<<j<<"->";
            cin>>temp;
            graph[i][j] = temp;
        }
    }

    for(int i=1; i<v+1; i++){
        cout<<i<<"->";
        for(int j=1; j<v+1; j++){
            if(graph[i][j] == 1){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}