#include<bits/stdc++.h>
using namespace std;
int n;
vector<long long> num;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    num.push_back(n);
    while(n!=1){
        if(n%2==0){
            n=n/2;
            num.push_back(n);
        }
        else{
            n=3*n+1;
            num.push_back(n);
        }
    }
    for(int i=num.size()-1;i>=0;i--) cout<<num[i]<<" ";
    return 0;
}