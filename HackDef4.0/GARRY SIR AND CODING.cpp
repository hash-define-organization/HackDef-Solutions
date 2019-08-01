#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin>>T;
    stack<int> s;
    while(T--){
        int n;
        cin>>n;
        if(n==2){
            int cost;cin>>cost;
            s.push(cost);
        }
        else{
            if(s.size()==0){
                cout<<"No Code"<<endl;
            }
            else{
                cout<<s.top()<<endl;
                s.pop();
            }
        }
    }
    return 0;
}