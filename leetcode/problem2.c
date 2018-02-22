#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int number1 = 0, number2 = 0, resNumber = 0;
    int m = 1, n = 1;
    ListNode point1, point2;
    ListNode resPoint, resRail;

    *resNumberList = (ListNode)malloc(sizeof(ListNode));
    resRail = *resNumberList;

    point1 = l1->next;
    while(point1)
    {
    	number1 = number1 + (point1->val)*(pow(10,m-1));
    	m++;
	}

	point2 = l2->next;
    while(point2)
    {
    	number2 = number2 + (point2->val)*(pow(10,n-1));
    	n++;
	}

    resNumber = numbeer1 + number2;
    while(resNumber)
    {
    	resPoint = (ListNode*)malloc(sizeof(ListNode));
    	resPoint->val = resNumber % 10;
    	resRail->next = resPoint;
    	resRail = resPoint;
    	resNumber = resNumber / 10;
	}

	return resNumberList;

}

int main()
{
	ListNode point1, rail1;
	ListNode point2, rail2;
	int i;
	int n = 3;

	*numberList1 = (ListNode)malloc(sizeof(ListNode));
	rail1 = *numberList1;

	*numberList2 = (ListNode)malloc(sizeof(ListNode));
	rail2 = *numberList2;

	printf("The first number list:\n");
	for(i = 0; i < n; i++)
	{
		point1 = (ListNode*)malloc(sizeof(ListNode));
		scanf("%d",&num);
		point1->val = num;
		rail1->next = point1;
		rail1 = point1;
	}
	rail1->next = null;

	printf("The second number list:\n");
	for(i = 0; i < n; i++)
	{
		point2 = (ListNode*)malloc(sizeof(ListNode));
		scanf("%d",&num);
		point2->val = num;
		rail2->next = point2;
		rail2 = point2;
	}
	rail2->next = null;

	return 0;
}
