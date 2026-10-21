#include<bits/stdc++.h>
using namespace std;
int a,b;
int fa[1005],ans[1005],mapp[505][505];
struct node{
    int fro,to,val;
}edge[130000];
bool comp(node x,node y){
    return x.val<y.val;
}
int find(int x){
    if(x==fa[x]) return x;
    else return fa[x]=find(fa[x]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>a>>b;
    int cnt=1;
    for(int i=1;i<=b;i++) fa[i]=i;
    for(int i=1;i<=b;i++)
        for(int j=1;j<=b;j++){
            cin>>mapp[i][j];
            if(mapp[i][j]>a||mapp[i][j]==0) continue;
            else{
                edge[cnt].fro=i,edge[cnt].to=j,edge[cnt].val=mapp[i][j];
                cnt++;
            }
        }
    for(int i=1;i<=b;i++){//超级源点，第一件物品需要买
        edge[cnt].fro=0,edge[cnt].to=i,edge[cnt].val=a;
        cnt++;
    }//cnt出循环的时候已经++，指的已经是空的值了
    int sum=0;
    sort(edge+1,edge+cnt,comp);
    for(int i=1;i<cnt;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        int w=edge[i].val;
        if(find(v)!=find(u)){//直接查找*
            fa[find(v)]=find(u);//一整个子树都得改*
            sum+=w;
        }
    }
    cout<<sum;
    return 0;
}