#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x){//构造函数->初始化
        data=x;
        next=NULL;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    Node* head=new Node(1);
    Node* tail = head; 
    for(int i=2;i<=n;i++){
        tail->next=new Node(i); tail=tail->next;
    }
    tail->next=head;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-1;j++){
            tail=tail->next;
        }
        Node* cur=tail->next;
        cout<<cur->data<<" ";
        tail->next=cur->next;
        delete cur;
    }
    return 0;
}