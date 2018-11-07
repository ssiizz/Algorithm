#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	int pos=1;
    	ListNode* ret = head;
    	ListNode* pre_head = NULL;
    	ListNode* new_tail = NULL;
    	ListNode* next = NULL;
    	ListNode tmp(0);
    	
		if(!head) return head;
		 
        while(head && pos < m-1){
			pos++;
			head=head->next;
		}
		if(1==m){
			pre_head=&tmp;
			new_tail = head;
			ret=tmp.next;			
		}else{
			pre_head = head;
			new_tail = head->next;
			head=head->next;
			pos++;	
		}

		//printf("Begin %d %p %p\n", head->val, head, head->next);
		
		while(head && pos <= n){
			//printf("%d:%d %p %p\n", pos,head->val, head, head->next);
			pos++;
			next = head->next;
			head->next = pre_head->next;
			pre_head->next = head;
			head=next;
		}
		new_tail->next = head;
		if(1==m)
			ret = tmp.next;
		
		return ret;
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
