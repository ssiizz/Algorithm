#include <stdio.h>


struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){} 
}; 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode tmp(0);
		if(NULL == l1)return l2;
		if(NULL == l2)return l1;
		if(l1->val < l2->val)
			tmp.next = l1;
		else
			tmp.next = l2;
		while(l1 && l2){
			
		} 
    }
};

int main(){
	ListNode a(10);
	ListNode b(20);
	ListNode c(30);
	ListNode d(40);
	ListNode e(50);
	ListNode f(60);
	ListNode g(70);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	
	ListNode *head = &a;
	printf("before reverse\n");
	while(head){
		printf("%d %p %p\n", head->val, head, head->next);
		head = head->next;
	}
	class Solution s;

	head=s.reverseBetween(&a,1,7);
	printf("after reverse\n");
	while(head){
		printf("%d %p %p\n", head->val, head, head->next);
		head = head->next;
	}	
	return 0;
}
