int strStr(char* haystack, char* needle) {
    int len1=strlen(haystack);
    int len2 = strlen(needle);
    int i=0;int j=0;
    if(len1<len2){
        return -1;
    }
    while(i<=len1-len2){
        j=0;
        while(j<len2&&haystack[i+j]==needle[j]){
            j++;
        }
        if(j==len2){
            return i;
        }
        i++;
    }

    return -1;


}