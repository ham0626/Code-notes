#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int t;
int fa[MAXN];
int dis[MAXN],siz[MAXN];
int find(int u){
    if(u==fa[u]) return u;
    else{
        int rt=find(fa[u]);//先递归出dis
        dis[u]+=dis[fa[u]];
        return fa[u]=rt;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    for(int i=1;i<=30000;i++){
        fa[i]=i;
        siz[i]=1;
        dis[i]=0;//距离
    }
    while(t--){
        char op;
        cin>>op;
        if(op=='M'){//并
            int u,v;
            cin>>u>>v;
            if(find(u)!=find(v)){
                int ru=find(u);
                int rv=find(v);
                fa[ru]=rv;//合并
                dis[ru]=siz[rv];//前面放队了
                siz[rv]+=siz[ru];
            }
        }
        else{//查
            int u,v;
            cin>>u>>v;
            if(find(u)!=find(v)) cout<<"-1"<<'\n';
            else cout<<abs(dis[u]-dis[v])-1<<'\n';
        }
    }
    return 0;
}