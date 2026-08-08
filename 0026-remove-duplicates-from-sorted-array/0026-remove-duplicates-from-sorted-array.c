void shiftLeft(int arr[],int size,int skip){
    for(int i=skip;i<size-1;i++){
        arr[i]=arr[i+1];
    }
}
int removeDuplicates(int* nums, int numsSize) {
   int i=0;
   while(i<numsSize-1){
    if(nums[i]==nums[i+1]){
        shiftLeft(nums,numsSize,i+1);
        numsSize--;
    }
    else{
        ++i;}
    }
    return numsSize;
}