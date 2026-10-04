#include<bits/stdc++.h>
using namespace std;
int num[2010];
int n,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    int cnt=0;
    for(int i=1;i<=n;i++) cin>>num[i];
    if(n==1){
        if(num[1]<k) cout<<"1";
        else cout<<"0";
        return 0;
    }
    if(n==2){
        if(num[1]<k) cnt++;
        if(num[2]<k) cnt++;
        // if(num[1]==num[2]&&num[1]==0){
        //     cout<<"2";
        //     return 0;
        // }
        if(num[1]*10+num[2]<k&&num[1]!=0) cnt++;
        if(num[2]*10+num[1]<k&&num[2]!=0) cnt++;
        if(num[1]*10+num[1]<k&&num[1]!=0) cnt++;
        if(num[2]*10+num[2]<k&&num[2]!=0) cnt++;
    }
    cout<<cnt;
    return 0;
}