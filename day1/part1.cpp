#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int a, b, sum = 0; 
    vector<int> ta, tb; 
    
    while(cin>>a && cin>>b){
       ta.push_back(a); 
       tb.push_back(b);
    }

    sort(ta.begin(), ta.end());
    sort(tb.begin(), tb.end());

    for(int i = 0; i < ta.size(); i++){
        sum = sum + abs(ta[i] - tb[i]);
    }

    cout << sum;
}