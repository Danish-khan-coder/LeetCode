#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int* result = (int*)malloc(2 * sizeof(int));

    // Hash table size
    int tableSize = numsSize * 2 + 1;

    int* keys = (int*)malloc(tableSize * sizeof(int));
    int* values = (int*)malloc(tableSize * sizeof(int));
    int* used = (int*)calloc(tableSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {

        int complement = target - nums[i];

        // Find complement in hash table
        unsigned int hash = (unsigned int)complement % tableSize;

        while (used[hash]) {

            if (keys[hash] == complement) {

                result[0] = values[hash];
                result[1] = i;

                *returnSize = 2;

                free(keys);
                free(values);
                free(used);

                return result;
            }

            hash = (hash + 1) % tableSize;
        }

        // Store current number
        hash = (unsigned int)nums[i] % tableSize;

        while (used[hash]) {
            hash = (hash + 1) % tableSize;
        }

        used[hash] = 1;
        keys[hash] = nums[i];
        values[hash] = i;
    }

    *returnSize = 0;

    free(keys);
    free(values);
    free(used);
    free(result);

    return NULL;
}