typedef struct ListNode ListNode;


ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    ListNode * resNumberList=(ListNode*)malloc(sizeof(ListNode));
    ListNode * ptr=resNumberList;
    int tempVal,more=0;
    int numList1[1000]={0},numList2[1000]={0};
    int count1=0,count2=0,total;
    while(l1)
    {
        numList1[count1]=l1->val;
        count1++;
        l1=l1->next;
    }
    while(l2)
    {
        numList2[count2]=l2->val;
        count2++;
        l2=l2->next;
    }
    
    (count1>=count2)?(total=count1):(total=count2);

    for(int i=0;i<total;i++)
    {
        ListNode * resNode=(ListNode*)malloc(sizeof(ListNode));
        resNode->next=NULL;
        tempVal=numList1[i]+numList2[i]+more;
        resNode->val=tempVal%10;
        more=tempVal/10;
        if(more>0&&i==total-1)
            total++;
        ptr->next=resNode;
        ptr=ptr->next;
    }

    resNumberList=resNumberList->next;
    

	return resNumberList;
}