#include<bits/stdc++.h>
using namespace std;
int n,m;
int head[1005],fa[1005];
int enemy[1005];//遇到的第一个敌人
int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void merge(int p,int q){
    int fp=find(p);
    int fq=find(q);
    if(fp!=fq)
        fa[fp]=fa[fq];
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        char op;
        cin>>op;
        if(op=='F'){//朋友
            int p,q;
            cin>>p>>q;
            merge(p,q);
        }
        else{
            int p,q;
            cin>>p>>q;
            if(enemy[p]==0) enemy[p]=q;
            else merge(enemy[p],q);
            if(enemy[q]==0) enemy[q]=p;
            else merge(enemy[q],p);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i) cnt++;
    }
    cout<<cnt;
    return 0;
}