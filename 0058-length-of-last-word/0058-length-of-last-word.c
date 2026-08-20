int lengthOfLastWord(char* s) {
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    i--;
    /*Skip the space in end */
    while(i>=0&&s[i]==' '){
        i--;
    }
    int count =0;
    while(i>=0&&s[i]!=' '){
        count++;
        i--;
    }
    return count ;
}