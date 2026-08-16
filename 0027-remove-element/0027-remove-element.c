int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int n = numsSize;

    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1]; // Overwrite with the last element
            n--;                   // Reduce the search range
        } else {
            i++;
        }
    }
    return n;
}