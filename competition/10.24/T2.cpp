#include<bits/stdc++.h>
using namespace std;
long long t,n,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k;
        long long leas=2*n-k;
        long long temp=max(0LL,2*k+1-n);
        long long ans=3*k-temp;
        cout<<min(leas,ans)<<'\n';
    }
    return 0;
}