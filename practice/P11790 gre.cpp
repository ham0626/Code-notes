#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long n,q,s,t;
long long ori[MAXN],num[MAXN];
long long ans=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q>>s>>t;
    for(int i=0;i<=n;i++) cin>>ori[i];
    for(int i=1;i<=n;i++){
        num[i]=ori[i]-ori[i-1];
        if(num[i]>0) ans-=num[i]*s;//爬坡降温
        else ans+=abs(num[i])*t;//下坡升温
    }
    for(int i=1;i<=q;i++){
        long long l,r,x;
        cin>>l>>r>>x;
        if(num[l]>0) ans+=num[l]*s;//复原
        else ans-=abs(num[l])*t;
        num[l]+=x;
        if(num[l]>0) ans-=num[l]*s;//新贡献
        else ans+=abs(num[l])*t;
        if(r<n){
            if(num[r+1]>0) ans+=num[r+1]*s;//复原
            else ans-=abs(num[r+1])*t;
            num[r+1]-=x;//r变了 num是后-前
            if(num[r+1]>0) ans-=num[r+1]*s;//新贡献
            else ans+=abs(num[r+1])*t;
        }
        cout<<ans<<'\n';
    }
    return 0;
}