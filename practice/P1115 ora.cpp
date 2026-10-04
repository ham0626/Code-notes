#include<bits/stdc++.h>
using namespace std;
int lin[200010];
long long ans[200010];
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>lin[i],ans[i]=lin[i];
    for(int i=2;i<=n;i++){
        if(ans[i-1]+lin[i]>lin[i]) ans[i]=ans[i-1]+lin[i];
        else ans[i]=lin[i];
    }
    long long maxn=-0x3f3f3f3f;//万一全是负数，赋成极小值
    for(int i=1;i<=n;i++) maxn=max(maxn,ans[i]);
    cout<<maxn;
    return 0;
}