#include <iostream>
#include <stdio.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

void insertSort(int a[],int n){
    int tmp,i,p;
    for( p=1;p<n;p++){
        tmp=a[p];
        for(i=p;i>0&&a[i-1]>tmp;i--){
            a[i]=a[i-1];
        }
        a[i]=tmp;
    }
}

ListNode *insertionSortList(ListNode *head){
    ListNode *sortedHead=new ListNode(-1);
    while(head){
        ListNode *temp=head->next;
        ListNode *cur=sortedHead;
        while(cur->next&&cur->next->val<head->val){
            cur=cur->next;
        }
        head->next=cur->next;
        cur->next=head;
        head=temp;
    }
    return sortedHead->next;
}

int main()
{
    ListNode *p=new ListNode(3);
    ListNode *p2=new ListNode(1);
    ListNode *p3=new ListNode(0);
    p->next=p2;
    p2->next=p3;
    ListNode* r =insertionSortList(p);
    while(r){
        printf("%d ",r->val);
        r=r->next;
    }
    return 0;
}
