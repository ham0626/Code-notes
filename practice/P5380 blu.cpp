#include<bits/stdc++.h>
using namespace std;
char mapp[10][10];
char who;
int q;//红方小写 蓝方大写
//王:C//士:G//象:E//马:H//车:R//鸭:D//兵:S
void op(char o){
    if(o=='c') cout<<"red captain";
    if(o=='C') cout<<"blue captain";
    if(o=='g') cout<<"red guard";
    if(o=='G') cout<<"blue guard";
    if(o=='e') cout<<"red elephant";
    if(o=='E') cout<<"blue elephant";
    if(o=='h') cout<<"red horse";
    if(o=='H') cout<<"blue horse";
    if(o=='r') cout<<"red car";
    if(o=='R') cout<<"blue car";
    if(o=='d') cout<<"red duck";
    if(o=='D') cout<<"blue duck";
    if(o=='s') cout<<"red soldier";
    if(o=='S') cout<<"blue soldier";
    return;
}
bool checkc(int sx,int sy,int tx,int ty){//检查符不符合王走法
    return abs(sx-tx)+abs(sy-ty)==1;
}
bool checkg(int sx,int sy,int tx,int ty){//检查符不符合士走法
    return abs(sx-tx)==1&&abs(sy-ty)==1;
}
bool checke(int sx,int sy,int tx,int ty){//检查符不符合象走法
    if(abs(sx-tx)==2&&abs(sy-ty)==2){
        if(mapp[(tx-sx)/2+sx][(ty-sy)/2+sy]=='.') return true;
        else return false;
    }
    else return false;
}
bool checkh(int sx,int sy,int tx,int ty){//检查符不符合马走法
    if(abs(sx-tx)==2&&abs(sy-ty)==1){
        if(mapp[(tx-sx)/2+sx][sy]=='.') return true;
        else return false;
    }
    else if(abs(sy-ty)==2&&abs(sx-tx)==1){
        if(mapp[sx][(ty-sy)/2+sy]=='.') return true;
        else return false;
    }
    else return false;
}
bool checkr(int sx,int sy,int tx,int ty){//检查符不符合车走法
    if(sx==tx&&sy!=ty){
        int flag=0;
        if(sy>ty){
            for(int i=ty+1;i<=sy-1;i++){
            if(mapp[sx][i]!='.'){
                flag=1;
                break;
            }
        }
        if(flag==1) return false;
        else return true;
        }
        else{
            for(int i=sy+1;i<=ty-1;i++){
            if(mapp[sx][i]!='.'){
                flag=1;
                break;
            }
        }
        if(flag==1) return false;
        else return true;
        }
    }
    else if(sy==ty&&sx!=tx){
        int flag=0;
        if(sx>tx){
            for(int i=tx+1;i<=sx-1;i++){
            if(mapp[i][sy]!='.'){
                flag=1;
                break;
            }
        }
        if(flag==1) return false;
        else return true;
        }
        else{
            for(int i=sx+1;i<=tx-1;i++){
            if(mapp[i][sy]!='.'){
                flag=1;
                break;
            }
        }
        if(flag==1) return false;
        else return true;
        }
    }
    else return false;
}
bool checkd(int sx,int sy,int tx,int ty){//检查符不符合鸭走法
    if(abs(sx-tx)==3&&abs(sy-ty)==2){
        if(mapp[2*((tx-sx)/3)+sx][(ty-sy)/2+sy]=='.'&&mapp[(tx-sx)/3+sx][sy]=='.')
        return true;
        else return false;
    }
    else if(abs(sx-tx)==2&&abs(sy-ty)==3){
        if(mapp[(tx-sx)/2+sx][2*((ty-sy)/3)+sy]=='.'&&mapp[sx][(ty-sy)/3+sy]=='.')
        return true;
        else return false;
    }
    else return false;
}
bool checks(int sx,int sy,int tx,int ty){//检查符不符合兵走法
    return abs(sx-tx)<=1&&abs(sy-ty)<=1&&(sx!=tx||sy!=ty);
}
bool canmove(char o,int sx,int sy,int tx,int ty){//发派去哪里检查
    if(o=='c') return checkc(sx,sy,tx,ty);
    else if(o=='C') return checkc(sx,sy,tx,ty);
    else if(o=='g') return checkg(sx,sy,tx,ty);
    else if(o=='G') return checkg(sx,sy,tx,ty);
    else if(o=='e') return checke(sx,sy,tx,ty);
    else if(o=='E') return checke(sx,sy,tx,ty);
    else if(o=='h') return checkh(sx,sy,tx,ty);
    else if(o=='H') return checkh(sx,sy,tx,ty);
    else if(o=='r') return checkr(sx,sy,tx,ty);
    else if(o=='R') return checkr(sx,sy,tx,ty);
    else if(o=='d') return checkd(sx,sy,tx,ty);
    else if(o=='D') return checkd(sx,sy,tx,ty);
    else if(o=='s') return checks(sx,sy,tx,ty);
    else if(o=='S') return checks(sx,sy,tx,ty);
    else return false;
}
bool suremove(char f,char o,int sx,int sy,int tx,int ty){//确定终点能不能走（己方/对方），边界
    if(tx<0||tx>=10||ty<0||ty>=9) return false;
    if(mapp[sx][sy]=='.') return false;
    if(f=='r'){//前一个动作是红方(小写)
        if(o>='A'&&o<='Z'){//当前是蓝方
            if(!canmove(o,sx,sy,tx,ty)) return false;//路线都不对
            else{
                if(mapp[tx][ty]=='.') return true;
                else if(mapp[tx][ty]<='z'&&mapp[tx][ty]>='a') return true;
                else return false;
            }
        }
        else return false;
    }
    else{//前一个动作是蓝方(大写)
        if(o>='a'&&o<='z'){//当前是红方
            if(!canmove(o,sx,sy,tx,ty)) return false;//路线都不对
            else{
                if(mapp[tx][ty]=='.') return true;
                else if(mapp[tx][ty]<='Z'&&mapp[tx][ty]>='A') return true;
                else return false;
            }
        }
        else return false;
    }
}
bool demove(char f,char o,int sx,int sy,int tx,int ty){
    if(!suremove(f,o,sx,sy,tx,ty)) return false;
    mapp[tx][ty]=mapp[sx][sy];
    mapp[sx][sy]='.';
    return true;
}
bool jiang(){//将军局面：存在一方(任一方)有一步合法操作能吃掉另一方的王
    int kx[2],ky[2];//0:红王'c' 1:蓝王'C'
    kx[0]=kx[1]=-1;
    for(int i=0;i<=9;i++)
        for(int j=0;j<=8;j++){
            if(mapp[i][j]=='c') kx[0]=i,ky[0]=j;
            if(mapp[i][j]=='C') kx[1]=i,ky[1]=j;
        }
    for(int i=0;i<=9;i++)
        for(int j=0;j<=8;j++){
            char p=mapp[i][j];
            if(p=='.') continue;
            int t=(p>='a'&&p<='z')?1:0;//小写(红)威胁蓝王C，大写(蓝)威胁红王c
            if(kx[t]==-1) continue;//对方王已被吃，无从谈起
            if(canmove(p,i,j,kx[t],ky[t])) return true;
        }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int xs,ys,xt,yt;
    cin>>q;
    memset(mapp,'.',sizeof(mapp));
    mapp[0][0]='r',mapp[0][1]='h',mapp[0][2]='e';
    mapp[0][3]='g',mapp[0][4]='c',mapp[0][5]='g';
    mapp[0][6]='e',mapp[0][7]='h',mapp[0][8]='r';
    mapp[2][0]='d',mapp[2][8]='d';
    mapp[3][0]='s',mapp[3][2]='s',mapp[3][4]='s';
    mapp[3][6]='s',mapp[3][8]='s';//红方初始化
    mapp[9][0]='R',mapp[9][1]='H',mapp[9][2]='E';
    mapp[9][3]='G',mapp[9][4]='C',mapp[9][5]='G';
    mapp[9][6]='E',mapp[9][7]='H',mapp[9][8]='R';
    mapp[7][0]='D',mapp[7][8]='D';
    mapp[6][0]='S',mapp[6][2]='S',mapp[6][4]='S';
    mapp[6][6]='S',mapp[6][8]='S';//蓝方初始化
    char flag='b';
    who='r';
    int en=0;
    for(int k=1;k<=q;k++){
        cin>>xs>>ys>>xt>>yt;
        if(!suremove(flag,mapp[xs][ys],xs,ys,xt,yt)||en!=0){
            cout<<"Invalid command"<<'\n';
            continue;
        }
        else{
            char c=mapp[xs][ys];
            char eat=mapp[xt][yt];//必须在demove之前记下，否则会被落子覆盖
            op(c);
            cout<<";";
            if(eat=='.') cout<<"NA";
            else op(eat);
            cout<<";";
            demove(flag,c,xs,ys,xt,yt);//两边哪一边死了都一样
            if(eat=='c'||eat=='C'){//王被移出游戏，游戏结束且不可能出现将军局面
                en=1;
                cout<<"no;yes";
            }
            else{
                if(!jiang()) cout<<"no;";
                else cout<<"yes;";
                cout<<"no";
            }
            flag=who;
            if(who=='r') who='b';
            else who='r';
            cout<<'\n';
        }
    }
    return 0;
}