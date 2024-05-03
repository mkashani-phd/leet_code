#include <stdio.h>
#include <stdlib.h>


int searchInsert(int* nums, int numsSize, int target) {

    // sorted array of distinct integer
    // if exist return the index
    // else return the index where it should be inserted

    // algo must be log(n)

    // can I see an example input and output
    // Input: nums = [1,3,5,6], target = 5
    // Output: 2

    // Input: nums = [1,3,5,6], target = 2
    // Output: 1


    // can the nums be an empty list? no

    int lowerBound = 0;
    int upperBound = numsSize;
    int middle = (upperBound + lowerBound)/2;

    while((upperBound - lowerBound) != 1)
    {
        if(nums[middle] == target)
        {
            return middle;
        }
        else if (nums[middle]> target)
        {
            upperBound = middle;
        }
        else
        {
            lowerBound = middle;
        }
        middle = (upperBound + lowerBound)/2;
    }

    return target > nums[lowerBound] ? upperBound : lowerBound;
    
    
}

int main()
{
    int nums[] = {1,3,5,6};
    int target = 5;
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int result = searchInsert(nums, numsSize, target);
    printf("result = %d\n", result);
    return 0;
}