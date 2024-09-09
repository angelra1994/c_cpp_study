/**
* brief:
* Created by lzy on 2024-09-05.
*/
#include <stdio.h>
int search(int* nums, int numsSize, int target);
int binarySearch(int * nums, int target, int left, int right);
int binary_search_use_while(int * nums, int target, int left, int right);

int main(int argc, char** argv)
{


    int nums[] = {-1,0,3,5,9,12};
    int target = 9;
    int ret = binary_search_use_while(nums, target, 0, 5);
    printf("ret = %d\n", ret);

}

int search(int* nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize; ++i)
    {
        if (target == nums[i])
        {
            return i;
        }
    }
    return -1;
}

int search_1(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; ++i)
    {
        if (target == nums[i])
        {
            return i;
        }

        // 数组有序，某一个数比 target大，后面的数就不需要遍历了
        if (nums[i] > target) {
            break;
        }
    }
    return -1;
}

//left代表左边界，right代表右边界
int binarySearch(int * nums, int target, int left, int right) {
    if(left > right) {
        return -1;   //如果左边大于右边，那么肯定就找完了，所以直接返回
    }
    int mid = (right - left) / 2  + left;   //这里计算出中间位置
    if(nums[mid] == target) {
        return mid; //直接比较，如果相等就返回下标
    }
    if(nums[mid] > target) {
        //这里就是大于或小于的情况了，这里mid+1和mid-1很多人不理解，实际上就是在下一次寻找中不算上当前的mid，因为这里已经比较过了，所以说左边就-1，右边就+1
        return binarySearch(nums, target, left, mid - 1);   //如果大于，那么说明肯定不在右边，直接去左边找
    } else {
        return binarySearch(nums, target, mid + 1, right); //如果小于，那么说明肯定不在左边，直接去右边找
    }
}

int binary_search_use_while(int * nums, int target, int left, int right)
{
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}
