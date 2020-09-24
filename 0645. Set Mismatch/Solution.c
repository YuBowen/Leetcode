#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Time complexity: O(n)
// Space complexity: O(1)
int *findErrorNums_MK1(int *nums, int numsSize, int *returnSize)
{
    int sum = 0, dup = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[abs(nums[i]) - 1] < 0)
            dup = abs(nums[i]);
        else
            nums[abs(nums[i]) - 1] *= -1;
        sum += abs(nums[i]);
    }
    *returnSize = 2;
    int *ret = (int *)malloc(sizeof(int) * *returnSize);
    ret[0] = dup;
    ret[1] = (((1 + numsSize) * numsSize) >> 1) - sum + dup;
    return ret;
}

// Time complexity: O(n)
// Space complexity: O(1)
// Note: (n * (n + 1) * (2 * n + 1) / 6 = 1^2 + 2^2 +...+ n^2
int *findErrorNums_MK2(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 2;
    long long sum = 0, sum2 = 0, n = numsSize;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        sum2 += nums[i] * nums[i];
    }
    int a = (((1 + numsSize) * numsSize) >> 1) - sum;
    int b = (n * (n + 1) * (2 * n + 1) / 6 - sum2) / a;
    int *ret = (int*)malloc(sizeof(int) * 2);
    ret[0] = (b - a) >> 1;
    ret[1] = (b + a) >> 1;
    return ret;
}
