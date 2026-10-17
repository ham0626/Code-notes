#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int fa[100005],head[100005],ans[100005];
struct node{
    int fro,to,nxt;
}edge[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    //一般拓扑:时间最短 父->子
    //序号最小（最小的先出）把尾巴放前面，后面不受影响
    while(t--){
        priority_queue<int> q;
        memset(fa,0,sizeof(fa));
        memset(head,0,sizeof(head));
        memset(ans,0,sizeof(ans));
        cin>>n>>m;
        int k=n;
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            fa[x]++;
            edge[i].fro=y,edge[i].to=x;
            edge[i].nxt=head[y];
            head[y]=i;
        }
        for(int i=1;i<=n;i++)
            if(fa[i]==0) q.push(i);//1->2 1->3 最大的先走，记录一下，倒序输出
        // if(q.size()==0)//有可能有链有环
        //     cout<<"Impossible! "<<'\n';
        int cnt=1;
        while(!q.empty()){
            int cur=q.top();
            q.pop();
            ans[cnt]=cur;
            cnt++;
            k--;
            for(int i=head[cur];i;i=edge[i].nxt){
                int v=edge[i].to;
                fa[v]--;
                if(fa[v]==0) q.push({v});
            }
        }
        if(k>0) cout<<"Impossible! "<<'\n';
        else{
            for(int i=cnt-1;i>=1;i--){
            if(i!=1) cout<<ans[i]<<" ";
            else cout<<ans[i]<<'\n';
            }
        }
    }
    return 0;
}