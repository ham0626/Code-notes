#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int t,n;
int num[400005];
long long fac[200005];
long long qpow(long long a,long long b){//快速幂
    long long res=1;
    while(b){
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    fac[0]=1;
    while(t--){
        cin>>n;
        for(int i=1;i<=2*n;i++) cin>>num[i];
        sort(num+1,num+2*n+1);
        for(int i=1;i<=n;i++) 
            fac[i]=(fac[i-1]*i)%mod;
        long long part1=(fac[n]*fac[n])%mod;
        long long part2=qpow(2,n);
        long long diff=(num[n+1]-num[n])%mod;
        if(diff<0) diff+=mod;
        long long ans=(part1*part2)%mod*diff%mod;
        cout<<ans<<'\n';
    }
    return 0;
}