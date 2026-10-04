#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int x,y,z;
    long long ans=0;
    cin>>x>>y>>z;
    if(x==y){
        cout<<x/z;
        return 0;
    }
    if(y<z){
        cout<<"0";
        return 0;
    }
    for(int i=x;i<=y;i++){
        ans+=i/z;
    }
    cout<<ans;
    return 0;
}