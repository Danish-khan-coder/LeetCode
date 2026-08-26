#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;

    // Allocate space for max possible digits + null terminator
    char* result = (char*)malloc(sizeof(char) * (maxLen + 2));

    int i = lenA - 1;
    int j = lenB - 1;
    int carry = 0;
    int k = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i--] - '0';
        }
        if (j >= 0) {
            sum += b[j--] - '0';
        }

        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    result[k] = '\0';

    // Reverse the string in-place
    for (int left = 0, right = k - 1; left < right; left++, right--) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
    }

    return result;
}