#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int t,n;
vector<int> g[MAXN];
int core[MAXN],a[MAXN],b[MAXN],dis[MAXN];
void init(){
    for(int i=1;i<MAXN;i++) core[i]=i;
    for(int i=2;i*i<MAXN;i++){
        int sq=i*i;
        for(int j=sq;j<MAXN;j+=sq){
            while(core[j]%sq==0){
                core[j]/=sq;
            }
        }
    }
}
int bfs(int s){
    queue<int> q;
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(v==s){
                dis[v]=dis[u]+1;
                return dis[v];
            }
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    init();
    memset(dis,-1,sizeof(dis));
    while(t--){
        cin>>n;
        vector<int> used;
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
            int u=core[a[i]],v=core[b[i]];
            if(u==1&&v==1) cnt++;
            else{
                g[u].push_back(v);
                used.push_back(u);
                used.push_back(v);
            }
        }
        if(cnt>=2){
            cout<<"2"<<'\n';
            for(int i=0;i<used.size();i++){
            int u=used[i];
            g[u].clear();
            break;
            }
            continue;
        }
        else{
            int ans=bfs(1);
            cout<<ans<<'\n';
        }
        for(int i=0;i<used.size();i++){
            int u=used[i];
            g[u].clear();
            dis[u]=-1;
        }
        dis[1]=-1;
    }
    return 0;
}