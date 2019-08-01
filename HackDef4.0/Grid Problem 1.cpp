#include<bits/stdc++.h> 
using namespace std;

const int s = 1e6+5; 
vector<pair<int,char> > v[s]; 

bool cmp(pair<int, char> a, pair<int, char> b) {
    return a.first < b.first; 
}

int sum(int a)
{
    return (a*(a+1))/2; 
}

int main() {
    int N, M, w, b, x, y; 
    cin >> N >> M >> w >> b; 
    
    for(int i=1; i<=w; i++) {
        cin >> x >> y; 
        v[x].push_back({y, 'W'}); 
    }
    for(int i=1; i<=b; i++) {
        cin >> x >> y; 
        v[x].push_back({y, 'B'}); 
    }
    
    for(int i=1; i<=N; i++) {
        sort(v[i].begin(), v[i].end(), cmp); 
    }
    
    int ans = 0, cur, last;
    bool last_w; 
    
    for(int i=1; i<=N; i++) {
        cur = 0; 
        last = 0;
        last_w = false; 
        
        for(pair<int,char> j: v[i]) {
            if(last_w) {
                ans += sum(cur) + (j.first-last+1) * cur; 
                if(j.second == 'B') {
                    ans += sum(j.first-last)-1;
                    last_w = false; 
                    cur = 0; 
                }    
                else {
                    cur = j.first-last-1; 
                }
                last = j.first; 
            }
            else {
                if(j.second == 'W') {
                    last_w = true;
                    cur = j.first-last-1; 
                }
                else {
                    ans += sum(j.first-last)-1; 
                    cur = 0; 
                }
                last = j.first; 
            }
        }
        
        ans += sum(M-last) + sum(cur) + (M-last+1) * cur; 
    } 
    
    cout << ans << endl; 
    return 0; 
}