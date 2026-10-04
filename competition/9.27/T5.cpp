#include<bits/stdc++.h>
using namespace std;
int lamp[35][35];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int contri(int x,int y,int c){
    int con=0;
    if(lamp[x-1][y]==c) con++;
    if(lamp[x][y-1]==c) con++;
    if(lamp[x+1][y]==c) con++;
    if(lamp[x][y+1]==c) con++;
    return con;
}
int comp(int x,int y,int c){
    int fin;
    if(c==1){
        int old=contri(x,y,1);
        int new1=contri(x,y,2);
        int new2=contri(x,y,3);
        int maxn=max(new1,new2);
        fin=maxn-old;
    }
    if(c==2){
        int old=contri(x,y,2);
        int new1=contri(x,y,1);
        int new2=contri(x,y,3);
        int maxn=max(new1,new2);
        fin=maxn-old;
    }
    if(c==3){
        int old=contri(x,y,3);
        int new1=contri(x,y,1);
        int new2=contri(x,y,2);
        int maxn=max(new1,new2);
        fin=maxn-old;
    }
    return fin;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int h,w;
    int ans=0,cont=0,maxx=-5;
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++)
        cin>>lamp[i][j];
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(lamp[i][j]==lamp[i+1][j]) ans++;
            if(lamp[i][j]==lamp[i][j+1]) ans++;
            maxx=max(comp(i,j,lamp[i][j]),maxx);
        }
    }
    if(maxx<0) cout<<ans;
    else cout<<maxx+ans;
    return 0;
}