#include<bits/stdc++.h>
using namespace std;
int n,m,p,q;
int fa[200010];//存父节点（不需要存根，一直推就行）
int find(int x){
    if(fa[x]==x) return x;//已经是根节点
    else return fa[x]=find(fa[x]);//把所有这条路上的元素全部指向根
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>p>>q;
    int cnt=0,minn=0x3f3f3f3f;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=p;i++){
        int x,y;
        cin>>x>>y;
        fa[find(x)]=find(y);//合并
    }
    for(int i=1;i<=n;i++){
        if(find(i)==find(1)) cnt++;
    }
    minn=min(minn,cnt);
    memset(fa,0,sizeof(fa));
    cnt=0;
    for(int i=1;i<=m;i++) fa[i]=i;
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        x=-x,y=-y;
        fa[find(x)]=find(y);//合并
    }
    for(int i=1;i<=m;i++){
        if(find(i)==find(1)) cnt++;
    }
    minn=min(minn,cnt);
    cout<<minn;
    return 0;
}