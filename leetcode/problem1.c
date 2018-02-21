#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int a,b;
    int *result = (int *)malloc(2 * sizeof(int));
    for(a = 0; a < numsSize;a++)
    {
        for(b = 0;b < numsSize;b++)
        {
            if(nums[a] + nums[b] == target)
            {
                if(a<b)
                {
                    result[0] = a;
                    result[1] = b;
                }
                else
                {
                    result[0]=b;
                    result[1]=a;
                }
            }
        }
    }
    int k;
    
    return result;
}

int main() {
    int array[4] = {11,5,2,7};
    int size = 4;
    int target = 9;
    int i;
    //int *res = (int *)malloc(2 * sizeof(int))
    int* res=twoSum(array,size,target);
    //res = twoSum(array, size, target);
    for(i = 0; i < 2; i++)
        printf("main：%d\n",res[i]);
    free(res);
    return 0;
}