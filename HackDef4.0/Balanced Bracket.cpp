#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int c=0;
        int low=0;
        int high=s.length()-1;
        while(low<high){
            if(s[low]==')'){
                low++;
            }
            else if(s[high]=='('){
                high--;
            }else{
                c+=2;
                low++;
                high--;
            }
        }
        cout<<c<<endl;
    }
}