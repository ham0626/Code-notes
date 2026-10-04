#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,r,pos;
    cin>>n>>r;
    pos=(n+1)/2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){//比较距离不要开方，直接平方比较
            int cx,cy;
            cx=abs(i-pos);
            cy=abs(j-pos);
            if(cx*cx+cy*cy<=r*r) cout<<"#";
            else cout<<".";
        }
        cout<<'\n';
    }
    return 0;
}