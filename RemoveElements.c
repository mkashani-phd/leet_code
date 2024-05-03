#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0 ; i < numsSize ; i++){
        if (nums[i] != val){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main()
{
    int nums[] = {0,1,2,2,3,0,4,2};
    int val = 2;
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int result = removeElement(nums, numsSize, val);
    printf("result = %d\n", result);
    return 0;
}