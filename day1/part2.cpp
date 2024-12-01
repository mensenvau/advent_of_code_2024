#include<bits/stdc++.h>
using namespace std;


int main(){ 
    int a, b, sum = 0; 
    vector<int> ta;
    map<int, int> mb; 
    
    while(cin>>a && cin>>b){
       ta.push_back(a); 
       mb[b]++;
    }

    sort(ta.begin(), ta.end()); 

    for(int i = 0; i < ta.size(); i++){
        sum = sum + abs(ta[i] * mb[ta[i]]);
    }

    cout << sum;
}