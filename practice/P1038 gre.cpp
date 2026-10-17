#include<bits/stdc++.h>
using namespace std;
int n,p;
int lim[105],beg[105],fa[105],sum[105],exi[105];
struct node{//阈值，初始值，入度，贡献值，兴奋度
    int to,val;
};
vector<node> nerve[105];
queue<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int flag=0;
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>beg[i]>>lim[i];
    }
    for(int i=1;i<=p;i++){
        int u,v,w;
        cin>>u>>v>>w;
        nerve[u].push_back({v,w});
        fa[v]++;
    }
    for(int i=1;i<=n;i++)
        if(fa[i]==0)//不管是否>0都要入队 下一个节点是否兴奋看的是总贡献
            q.push(i),exi[i]=beg[i];
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<nerve[cur].size();i++){
            int des=nerve[cur][i].to;
            fa[des]--;
            if(exi[cur]>0){//兴奋了才有后面的事
                sum[des]+=exi[cur]*nerve[cur][i].val;//只要兴奋了就要加上贡献值
                }
            if(fa[des]==0){//输出端
                    exi[des]=sum[des]-lim[des];//提前处理好 避免在循环里反复处理
                    q.push(des);//入度为0再入队，确保算exi时所有贡献都已经加完
                }
            }
    }
    for(int i=1;i<=n;i++){
        if(nerve[i].size()==0)
            if(exi[i]>0){
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"NULL";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(nerve[i].size()==0)
        if(exi[i]>0)
        cout<<i<<" "<<exi[i]<<'\n';
    }
    return 0;
}