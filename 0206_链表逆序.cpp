#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode tmp(0);
        while(head){
        	ListNode *next = head->next;
			head->next = tmp.next; 
			tmp.next = head;
			head=next;
		}
		return tmp.next;
    }
    ListNode* reverseList2(ListNode* head) {
        ListNode *new_head=NULL;
        while(head){
        	ListNode *next = head->next;
			head->next = new_head; 
			new_head = head;
			head=next;
		}
		return new_head;
    }
    ListNode* reverseList3(ListNode* head,ListNode* pre) {
    	ListNode* next;
    	printf("%d %p\n",head->val,pre);
        if(!head->next) {       	
        	next=head->next;
	        head->next=pre;
	        if(pre) pre->next=next;
	        printf("%d %p %p\n", head->val, head, head->next);
			return head;
		}   
        ListNode *ret = reverseList3(head->next,head); 
        next=head->next;
        head->next=pre;
        if(pre) pre->next=next;
        printf("%d %p %p\n", head->val, head, head->next);
		return ret;	
    }
    ListNode* reverseList4(ListNode* head) {
        ListNode *new_head=NULL;
        if(!head || !head->next) return head;
        new_head = reverseList4(head->next);
        head->next->next = head;
        head->next = NULL;
		return new_head;
    }
};
int main(){
	ListNode a(10);
	
	ListNode b(20);
	ListNode c(30);
	ListNode d(40);
	ListNode e(50);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	
	ListNode *head = &a;
	printf("before reverse\n");
	while(head){
		printf("%d %p %p\n", head->val, head, head->next);
		head = head->next;
	}
	class Solution s;
	/*
	head = s.reverseList(&a);
	head = s.reverseList2(&a);
	head=s.reverseList3(&a,NULL);
	*/
	head=s.reverseList4(&a);
	printf("after reverse\n");
	while(head){
		printf("%d %p %p\n", head->val, head, head->next);
		head = head->next;
	}	
	return 0;
}


