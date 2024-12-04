#include<bits/stdc++.h>
using namespace std;

bool check(vector<string> arr, int row, int col, int x, int y) { 
    if (arr[x][y] == 'A' && x - 1 >= 0 && y - 1 >= 0 && x + 1 < row && y + 1 < col) {
        char lu = arr[x-1][y-1];
        char ru = arr[x-1][y+1];
        char ld = arr[x+1][y-1];
        char rd = arr[x+1][y+1];
        
        int count = 0;
        if(((ld == 'M' && ru == 'S') || (ld == 'S' && ru == 'M')) && 
          ((lu == 'M' && rd == 'S') || (lu == 'S' && rd == 'M'))) return true;
        return false;
    } 
    return false;
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
            if(check(arr, row, col, i, j)) { sum++; }
        }
    }

    cout<<sum;
}