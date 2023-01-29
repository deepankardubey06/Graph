#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
{
    vector<string> creatableRec;
    int found = 1;

    for(int i=0; i<recipes.size(); i++){
        found = 1;
        for(int j=0; j<ingredients[i].size(); j++){
            if(find(supplies.begin(), supplies.end() ,ingredients[i][j]) == supplies.end()){
                found = 0;
                break;
            }
        }
        if(found == 1){
            supplies.push_back(recipes[i]);
            creatableRec.push_back(recipes[i]);
        }
    }

    return creatableRec;
}

void display(vector<string> &ans){
    for(string i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<string> recipes = {"bread", "sandwich", "burger"};
    vector<vector<string>> ingredients = {{"yeast", "flour"}, {"bread", "meat"}, {"sandwich", "meat", "bread"}};
    vector<string> supplies = { "yeast", "flour", "meat" };

    vector<string> ans;
    ans = findAllRecipes(recipes,ingredients, supplies);
    display(ans);

    return 0;
}