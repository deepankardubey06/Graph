#include<iostream>
#include<vector>

using namespace std;

bool find(vector<int> &arr, int A, int B){
    while(arr[A] != -1){
        A = arr[A];
    }
    while (arr[B] != -1)
    {
        B = arr[B];
    }
    if(A == B){
        return true;
    }
    return false;
}

void unionn(vector<int> &arr, int A, int B){
    arr[B] = A;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,-1);
    unionn(arr,0,1);
    unionn(arr,1,2);
    cout<<find(arr,0,3);

    return 0;
}
// Follow Up :- Detect Cycle In Undirected Graph Using Disjoint Set. 