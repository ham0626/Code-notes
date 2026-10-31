#include<bits/stdc++.h>
using namespace std;
int n,k;
int tree[100005];
bool check(int lim){
    long long cnt=0;
    for(int i=1;i<=n;i++){
        cnt=cnt+(tree[i]/lim);
    }
    if(cnt>=k) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    int maxn=0;
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>tree[i];
        sum+=tree[i];
        maxn=max(maxn,tree[i]);
    }
    if(sum<k){
        cout<<"0";
        return 0;
    }
    int l=0,r=maxn;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=max(ans,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}