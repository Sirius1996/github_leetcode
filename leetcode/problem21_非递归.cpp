#include<iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *resList=new ListNode(0);
        ListNode *ptr1=l1, *ptr2=l2,*temp=resList;
        while(ptr1!=NULL&&ptr2!=NULL)
        {
            if(ptr1->val<=ptr2->val)
            {
                temp->next=ptr1;
                ptr1=ptr1->next;
            }
            else
            {
                temp->next=ptr2;
                ptr2=ptr2->next;
            }
            temp=temp->next;
        }
        if(ptr1!=NULL)
        {
            temp->next=ptr1;
            ptr1=ptr1->next;
        }
        else if(ptr2!=NULL)
        {
            temp->next=ptr2;
            ptr2=ptr2->next;
        }
        resList=resList->next;
        return resList;
        
    }
};