#include<bits/stdc++.h>
using namespace std;
int t,n,tot;
int mapp[60][60],match[60];//下标是床的编号
bool is[60];//是不是在校生->有没有床
bool need[60];//是否需要
bool vis[60];
bool dfs(int u){//u是学生编号
    for(int i=1;i<=n;i++){//认识人的编号
        if(mapp[u][i]==0||is[i]==0) continue;//不认识 外校生
        if(vis[i]==true) continue;
        vis[i]=true;
        if(match[i]==0||dfs(match[i])==true){
            match[i]=u;//i相当于本校生的床
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        memset(mapp,0,sizeof(mapp));
        memset(is,0,sizeof(is));
        memset(need,0,sizeof(need));
        memset(match,0,sizeof(match));
        memset(vis,0,sizeof(vis));
        tot=0;
        cin>>n;//n个人
        for(int i=1;i<=n;i++){
            cin>>is[i];
        }
        for(int i=1;i<=n;i++){
            int op;
            cin>>op;
            if(is[i]==1){//是在校生
                if(op==0) need[i]=1,tot++;//不回家 要床
                else need[i]=0;//回家 不需要床
            }
            else{//外校生肯定需要
                need[i]=1,tot++;
                continue;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
            cin>>mapp[i][j];
            mapp[i][i]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(need[i]==1){
                memset(vis,0,sizeof(vis));
                if(dfs(i)==true) ans++;//需要
            }
        }
        if(ans==tot||ans==n) cout<<"^_^"<<'\n';
        else cout<<"T_T"<<'\n';
    }
    return 0;
}