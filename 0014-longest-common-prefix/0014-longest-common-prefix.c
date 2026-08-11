char* longestCommonPrefix(char** strs, int strsSize) {
    int len = strlen(strs[0]);

    for (int i = 1; i < strsSize; i++) {

        int j = 0;

        while (j < len &&
               j < strlen(strs[i]) &&
               strs[0][j] == strs[i][j]) {
            j++;
        }

        len = j;

        if (len == 0) {
            return "";
        }
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        result[i] = strs[0][i];
    }

    result[len] = '\0';

    return result;
}