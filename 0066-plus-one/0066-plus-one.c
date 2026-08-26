/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }

    // Edge case: all digits were 9 (e.g., [9, 9] -> [1, 0, 0])
    *returnSize = digitsSize + 1;
    int* result = (int*)calloc(*returnSize, sizeof(int));
    result[0] = 1;

    return result;
}