#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int sum = 0, num; 
    string line;
    
    while(getline(cin, line)){
        stringstream in(line);

        vector<int> arr;
        while(in>>num){ arr.push_back(num); }

        int c1 = 1, c2 = 1;
        for(int i=1; i<arr.size(); i++){
            if(arr[i-1]<arr[i] && arr[i]-arr[i-1]>=1 && arr[i]-arr[i-1]<=3) continue;
            c1 = 0; 
            break;
        }

        for(int i=1; i<arr.size(); i++){
            if(arr[i-1]>arr[i] && arr[i-1]-arr[i]>=1 && arr[i-1]-arr[i]<=3) continue;
            c2 = 0; 
            break;
        } 
        
        if(c1==1 || c2==1) sum++;
    }

   cout<<sum;

}