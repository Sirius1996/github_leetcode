typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
  ListNode *ptr1, *ptr2;
  ListNode *resPoint, *resTail;
  ListNode *resNumberList = (ListNode*)malloc(sizeof(ListNode));
  int number1 = 0, number2 = 0;

  //l1 = l1->next;
  //l2 = l2->next;

  resTail=resNumberList;
  ptr1 = l1;
  ptr2 = l2;

  while(ptr1 || ptr2)
  {
    if(ptr1)
        number1 = ptr1->val;
    if(ptr2)
        number2 = ptr2->val;
    resPoint = (ListNode*)malloc(sizeof(ListNode));

    if(ptr1 && ptr2)
    {
      if(number1 > number2)
      {
        resPoint->val = number2;
        ptr2 = ptr2->next;
      }
      else
      {
        resPoint->val = number1;
        ptr1 = ptr1->next;
      }
      resTail->next = resPoint;
      resTail=resPoint;
    }
    else if(ptr1 && !ptr2)
    {
      resPoint->val = number1;
      resTail->next = resPoint;
      resTail=resPoint;
      ptr1 = ptr1->next;
    }
    else
    {
      resPoint->val = number2;
      resTail->next = resPoint;
      resTail=resPoint;
      ptr2 = ptr2->next;
    }
    //ptr1,ptr2=null
  }//end for while(ptr1 || ptr2)
  resTail->next = NULL;

  printf("result:\n");
	resNumberList = resNumberList->next;
	

	return resNumberList;
}