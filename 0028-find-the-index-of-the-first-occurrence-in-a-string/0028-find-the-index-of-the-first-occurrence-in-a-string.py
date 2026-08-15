class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        len1=len(haystack)
        len2=len(needle)
        i=0

        while i <= len1-len2:
            j=0
            while(j<len2 and haystack[i+j]==needle[j]):
                j+=1
            if(j== len2):
                return i
            i+=1
        
        return -1