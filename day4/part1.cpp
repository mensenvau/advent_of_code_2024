#include<bits/stdc++.h>
using namespace std;

string str_find = "XMAS";
vector<vector<int>> dc = {
    {0, 1},  
    {0, -1},
    {1, 0}, 
    {-1, 0}, 
    {1, 1},   
    {-1, -1}, 
    {1, -1},
    {-1, 1} 
};

bool check(vector<string> arr, int row, int col, int x, int y, int cx, int cy) { 
    for (int i = 0; i < str_find.size(); i++) {
        int nx = x + i * cx;
        int ny = y + i * cy; 
        if (nx < 0 || nx >= row || ny < 0 || ny >= col || arr[nx][ny] != str_find[i]) 
            return false;
    }
    return true;
}

int main(){ 
   
    string line; 
    vector<string> arr;
 
    while(getline(cin, line)){  arr.push_back(line);  }

    int sum = 0;
    int row = arr.size();
    int col = arr[0].size();
 
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            for(int k = 0; k < dc.size(); k++){
               if(check(arr, row, col, i, j, dc[k][0], dc[k][1])) {
                    sum++;  
               }
            }
        }
    }

    cout<<sum;
}