#include<bits/stdc++.h>
using namespace std;
string word,text;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //cin读不了回车和空格
    //getline可以读空格读不了回车
    cin>>word;
    string temp;
    getline(cin,temp);
    getline(cin,text);
    int lenw=word.size();
    int lent=text.size();//长度
    int s=0,l=0;
    for(int i=0;i<lenw;i++) 
        word[i]=tolower(word[i]);
    for(int i=0;i<lent;i++) 
        text[i]=tolower(text[i]);
    word=" "+word+" ";
    text=" "+text+" ";
    int pos=text.find(word);
    if(pos==string::npos){
        cout<<"-1";
        return 0;
    }
    int fpos=pos;
    int cnt=0;
    while(pos!=string::npos){
        cnt++;
        pos=text.find(word,pos+1);
    }
    cout<<cnt<<" "<<fpos;
    return 0;
}