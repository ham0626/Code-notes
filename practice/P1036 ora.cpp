#include<bits/stdc++.h>
using namespace std;
int num[25];
int n,k,cnt;
bool pri(int numb){
    if(numb==1) return false;
    if(numb==2) return true;
    for(int i=2;i*i<=numb;i++){
        if(numb%i==0) return false;
    }
    return true;
}
void dfs(int start,int lim,int sum){
    if(lim==0){
        if(pri(sum)==true) cnt++;
        return;
    }
    for(int i=start+1;i<=n;i++){
        dfs(i,lim-1,sum+num[i]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>num[i];
    if(n==1){
        if(pri(num[1])==true){
            cout<<"1";
            return 0;
        }
        else{
            cout<<"0";
            return 0;
        }
    }
    for(int i=1;i<=n-k+1;i++){
        dfs(i,k-1,num[i]);
    }
    cout<<cnt;
    return 0;
}