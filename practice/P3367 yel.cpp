#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[200010];//存父节点（不需要存根，一直推就行）
int find(int x){
    if(fa[x]==x) return x;//已经是根节点
    else return fa[x]=find(fa[x]);//把所有这条路上的元素全部指向根
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1){//并
            fa[find(x)]=find(y);
        }
        else{//查
            if(find(x)==find(y)) cout<<"Y"<<'\n';//必须根指向根
            else cout<<"N"<<'\n';
        }
    }
    return 0;
}