#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;
struct ListNode {
  int val;
  struct ListNode *next;
 };


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
  ListNode *ptr1, *ptr2;
  ListNode *resPoint, *resTail;
  ListNode *resNumberList = (ListNode*)malloc(sizeof(ListNode));
  int number1 = 0, number2 = 0;

  l1 = l1->next;
  l2 = l2->next;

  resTail=resNumberList;
  ptr1 = l1;
  ptr2 = l2;

  while(ptr1 || ptr2)
  {
    number1 = ptr1->val;
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
  }//end for while(ptr1 || ptr2)
  resTail->next = NULL;

  printf("result:\n");
	resNumberList = resNumberList->next;
	while (resNumberList!=NULL)
	{
		printf("%d ", resNumberList->val);
		resNumberList = resNumberList->next;
	}

	return resNumberList;
}

int main()
{
	ListNode *point1, *rail1;
	ListNode *point2, *rail2;
	ListNode *resList;
	int i;
	int n = 3;
	int num;

	ListNode* numberList1 = (ListNode*)malloc(sizeof(ListNode));
	rail1 = numberList1;

	ListNode* numberList2 = (ListNode*)malloc(sizeof(ListNode));
	rail2 = numberList2;

	printf("The first number list:\n");
	for (i = 0; i < n; i++)
	{
		point1 = (ListNode*)malloc(sizeof(ListNode));
		scanf("%d", &num);
		point1->val = num;
		rail1->next = point1;
		rail1 = point1;
	}
	rail1->next = NULL;

	printf("The second number list:\n");
	for (i = 0; i < n; i++)
	{
		point2 = (ListNode*)malloc(sizeof(ListNode));
		scanf("%d", &num);
		point2->val = num;
		rail2->next = point2;
		rail2 = point2;
	}
	rail2->next = NULL;

	resList = mergeTwoLists(numberList1, numberList2);

	system("pause");
	return 0;
}
