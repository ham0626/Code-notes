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
int len(Node* p){//链表长度
    int n=0;
    while(p){
        p=p->next;
        n++;
    }
    return n;
}
void showf(Node* head){//链表反向遍历
    if(head==NULL) return;
    showf(head->next);
    cout<<head->data<<" ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    Node* head=new Node(1);
    Node* tail=head;
    for(int i=2;i<=10;i++){
        tail->next=new Node(i); tail=tail->next;
    }
    showf(head);
    return 0;
}