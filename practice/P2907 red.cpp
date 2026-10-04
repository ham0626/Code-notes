#include<bits/stdc++.h>
using namespace std;
int ans;
void divi(int n,int k){
    if((n-k)%2!=0||n<=k){
        ans++;
        return;
    }
    else{
        int n1=(n-k)/2;
        int n2=(n+k)/2;
        divi(n1,k);
        divi(n2,k);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    divi(n,k);
    cout<<ans;
    return 0;
}