#include<bits/stdc++.h>
using namespace std;
//A* F(综合评分)=H(估计还有多少步)+G(已经走了多少步)
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int dis[400000];
struct Node{
    int f,g;//重载运算符
    string sta;
    bool operator<(const Node&other)const{
        return f>other.f;//小根堆
    }
};
int esti(string s){
    int px[9]={0,0,0,1,1,1,2,2,2};
    int py[9]={0,1,2,0,1,2,0,1,2};
    int tar[9]={4,0,1,2,5,8,7,6,3};//理想中每个数(下标)的位置
    int sum=0;
    for(int i=0;i<=8;i++){
        int num=s[i]-'0';//i是位置编号
        if(tar[num]!=i&&num!=0){//不在最终位置上
            int pos=tar[num];//理想中应该在的位置
            sum+=abs(px[pos]-px[i])+abs(py[pos]-py[i]);
        }
    }
    return sum;
}
int fac[10]={1,1,2,6,24,120,720,5040,40320,362880};//阶乘预处理
int cantor(string s){
    int res=0;
    for(int i=0;i<9;i++){
        int cnt=0;
        for(int j=i+1;j<9;j++){
            if(s[j]<s[i]) cnt++;
        }
        res+=cnt*fac[8-i];
    }
    return res;
}
void astar(string s){
    priority_queue<Node> q;
    memset(dis,0x3f,sizeof(dis));
    int sid=cantor(s);//康托展开 每个状态对应一个编号来查重
    dis[sid]=0;
    q.push({esti(s),0,s});
    while(!q.empty()){
        Node cur=q.top();
        q.pop();
        if(cur.sta=="123804765"){
            cout<<cur.g<<'\n';
            return;
        }
        int pos0=cur.sta.find('0');
        int y=pos0%3;
        int x=pos0/3;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=3||ny<0||ny>=3) continue;
            int id=nx*3+ny;
            string nxt=cur.sta;//复制一份现在的状态
            swap(nxt[id],nxt[pos0]);//交换位置
            int nid=cantor(nxt);//新状态编号
            int ng=cur.g+1;//已经走的步数
            if(ng<dis[nid]){
                dis[nid]=ng;
                q.push({ng+esti(nxt),ng,nxt});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string start;
    cin>>start;
    astar(start);
    return 0;
}