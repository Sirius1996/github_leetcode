#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode ListNode;

struct ListNode {
	int val;
	struct ListNode *next;
};

ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int number = 0, carry = 0, copyNumber = 0;
	ListNode *ptr1, *ptr2;
	ListNode *resPoint,* resRail;
	ListNode *resNumberList = (ListNode*)malloc(sizeof(ListNode));

	resRail = resNumberList;
	ptr1 = l1;
	ptr2 = l2;//leetcode版上无头结点要这么写

	while (ptr1 || ptr2)
	{
		if(ptr1 && ptr2)
		{
			number = ptr1->val + ptr2->val + carry;
			// printf("number1:%d\n", number);
			resPoint = (ListNode*)malloc(sizeof(ListNode));

			resPoint->val = number%10;
			carry=number/10;
			resRail->next = resPoint;
			resRail = resPoint;



			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else if(ptr1 && !ptr2)
		{
			number = ptr1->val + carry;
			/*printf("ptr1->val:%d\n", ptr1->val);
			printf("carry:%d\n", carry);
			printf("number2:%d\n", number);*/
			resPoint = (ListNode*)malloc(sizeof(ListNode));
			resPoint->val = number%10;
			carry=number/10;
			printf("resPoint:%d\n", resPoint->val);
			resRail->next = resPoint;
			resRail = resPoint;
			ptr1 = ptr1->next;
		}
		else
		{
			number = ptr2->val + carry;
			resPoint = (ListNode*)malloc(sizeof(ListNode));
			resPoint->val = number%10;
			carry=number/10;
			resRail->next = resPoint;
			resRail = resPoint;
			ptr2 = ptr2->next;
		}
	}
	if(carry)
	{
		resPoint = (ListNode*)malloc(sizeof(ListNode));
		resPoint->val = carry;
		resRail->next = resPoint;
		resRail = resPoint;
	}
	resRail->next = NULL;


	resNumberList = resNumberList->next;


	return resNumberList;

}

int main()
{
	ListNode* point1, *rail1;
	ListNode* point2, *rail2;
	ListNode* resList;
	int i;
	int n = 3;
	int num;

	ListNode* numberList1 = (ListNode*)malloc(sizeof(ListNode));
	rail1 = numberList1;

	ListNode* numberList2 = (ListNode*)malloc(sizeof(ListNode));
	rail2 = numberList2;

	printf("The first number list:\n");
	for (i = 0; i < 3; i++)
	{
		point1 = (ListNode*)malloc(sizeof(ListNode));
		scanf("%d", &num);
		point1->val = num;
		rail1->next = point1;
		rail1 = point1;
	}
	rail1->next = NULL;

	printf("The second number list:\n");
	for (i = 0; i < 1; i++)
	{
		point2 = (ListNode*)malloc(sizeof(ListNode));
		scanf("%d", &num);
		point2->val = num;
		rail2->next = point2;
		rail2 = point2;
	}
	rail2->next = NULL;

	resList = addTwoNumbers(numberList1, numberList2);

	system("pause");
	return 0;
}
