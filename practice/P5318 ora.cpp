// #include<bits/stdc++.h>
// using namespace std;
// int pos[1001000];//存某个节点排序后在哪里
// bool vis[1001000];//检查论文是否已经读过
// int n,m;
// queue<int> q;
// struct node{
//     int fro,to;
// }art[1001000];//论文编号存在这里
// bool comp(node a,node b){
//     if(a.fro>b.fro) return false;//a大
//     else if(a.fro==b.fro){
//         if(a.to<b.to) return true;
//         else return false;
//     }
//     else return true;
// }
// void bfs(int i){
//     q.push(i);
//     vis[i]=true;
//     while(!q.empty()){
//         int cur=q.front();
//         q.pop();
//         cout<<cur<<" ";
//         if(pos[cur]==-1) continue;//必须特判，压进去的元素可能没有子元素，所以对应的pos为-1，就非法了
//         for(int j=pos[cur];j<=m&&art[j].fro==art[pos[cur]].fro;j++){
//             if(vis[art[j].to]==false) q.push(art[j].to),vis[art[j].to]=true;
//             else continue;
//         }
//     }
// }
// void dfs(int i){
//     vis[i]=true;
//     cout<<i<<" ";
//     if(pos[i]==-1) return;//必须特判，压进去的元素可能没有子元素，所以对应的pos为-1，就非法了
//     for(int j=pos[i];j<=m&&art[j].fro==art[pos[i]].fro;j++){
//         if(vis[art[j].to]==false) dfs(art[j].to);
//         else continue;
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0),cout.tie(0);
//     memset(pos,-1,sizeof(pos));
//     cin>>n>>m;
//     for(int i=1;i<=m;i++)
//         cin>>art[i].fro>>art[i].to;
//     sort(art+1,art+m+1,comp);
//     for(int i=1;i<=m;i++){
//         if(i==1||art[i].fro!=art[i-1].fro){//子元素区间
//             pos[art[i].fro]=i;
//         }
//     }
//     dfs(1);
//     cout<<'\n';
//     memset(vis,0,sizeof(vis));
//     bfs(1);
//     return 0;
// }
//vector存
#include<bits/stdc++.h>
using namespace std;
bool vis[100100];//检查论文是否已经读过
int n,m;
queue<int> q;
vector<int> mapp[100010];
void bfs(int i){
    q.push(i);
    vis[i]=true;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout<<cur<<" ";
        if(mapp[cur].size()==0) continue;//必须特判，压进去的元素可能没有子元素，所以对应的pos为-1，就非法了
        for(int j=0;j<mapp[cur].size();j++){
            if(vis[mapp[cur][j]]==false) q.push(mapp[cur][j]),vis[mapp[cur][j]]=true;
            else continue;
        }
    }
    return;
}
void dfs(int i){
    vis[i]=true;
    cout<<i<<" ";
    if(mapp[i].size()==0) return;//必须特判，压进去的元素可能没有子元素，所以对应的pos为-1，就非法了
    for(int j=0;j<mapp[i].size();j++){
        if(vis[mapp[i][j]]==false){
            vis[mapp[i][j]]=true;
            dfs(mapp[i][j]);
        }
        else continue;
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        mapp[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    sort(mapp[i].begin(),mapp[i].end());
    dfs(1);
    cout<<'\n';
    memset(vis,0,sizeof(vis));
    bfs(1);
    return 0;
}
