#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>> &matrix, int x, int y, int r, int c){
    if(x < 0 || y >= c || matrix[x][y] == 2 || matrix[x][y] == 0 || x >= r || y < 0){
        return;
    }

    matrix[x][y] = 2;
    dfs(matrix, x + 1, y, r, c); //Down
    dfs(matrix, x, y + 1, r, c); //Right
    dfs(matrix, x-1, y, r, c); //Top
    // dfs(grid, x, y+1, r, c); //Right  
    // dfs(grid, x+1, y, r, c); //Down
    dfs(matrix, x, y-1, r, c); //Left
}

int main(){
    cout<<"Hello"<<endl;
    vector<vector<int>> grid = {
        { 1, 1, 0, 0, 0 },
        { 1, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0 }
    };
    int row = grid.size();
    int column = grid[0].size();
    int island = 0;
    for(int i=0; i<grid.size(); i++){
        cout<<"loop1"<<endl;
        for(int j=0; j<grid[i].size(); j++){
            if(grid[i][j] == 1){
                cout<<i<<" "<<j<<endl;
                dfs(grid, i, j, row, column);
                island += 1;
                cout<<island<<endl;
            }
        }
    }

    // for (int i = 0; i < grid.size(); i++)
    // {
    //     for (int j = 0; j < grid[i].size(); j++)
    //     {
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<"bye"<<endl;
    cout<<island<<endl;
    return 0;
}