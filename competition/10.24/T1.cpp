#include<bits/stdc++.h>
using namespace std;
int n,a,b,t;
int mine[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        memset(mine,0,sizeof(mine));
        cin>>n>>a>>b;
        for(int i=1;i<=n;i++) cin>>mine[i];
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(mine[i]==1){
                if(a>0) a--;
                else if(b>0) b--;
                else break;
            }
            else{
                if(b>0) b--;
                else break;
            }
            cnt++;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}