/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>



int carryOver = 0;

int half_adder(int a, int b)
{
    int result = a + b + carryOver;
    carryOver = result / 10;
    return result %10;
}


int* plusOne(int* digits, int digitsSize, int* returnSize) {

    // can I see the example input and output
    // Input: digits = [1,2,3]
    // Output: [1,2,4] 

    // can input be an empty list?
    //no

    // how does a negative intiger is represented?
    // i guess it can't

    // I am going to use a half adder on repeat for the length of the array backward

    int* arrPtr = (int*) malloc((digitsSize+1) * sizeof(int));
    int increment = 1;
    int cnt = 0;
    for(int i = digitsSize -1; i>=0; i--)
    {
        *(arrPtr+i+1) = half_adder(digits[i], increment);
        printf("arrPtr[%d] = %d\n", i+1, *(arrPtr+i+1));
        increment = 0;
        cnt++;
    }
    

    if(carryOver == 1)
    {
        *(arrPtr) = half_adder(0, 0);
        cnt++;
        *returnSize = cnt;
        return arrPtr;
    }
    else
    {
        *returnSize = cnt;
        return arrPtr + 1;
    }

    
    
}


int main()
{
    int digits[] = {9,9,9};
    int digitsSize = sizeof(digits)/sizeof(digits[0]);
    int returnSize;
    int* result = plusOne(digits, digitsSize, &returnSize);
    for(int i = 0; i<returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}