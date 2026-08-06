#include <stdio.h>



int maxArea(int* height, int heightSize) {
   int MaxArea=0;
   int left =0;
   int right = heightSize-1;
   int width=0;
   int area;
   while(left<right){
       width=right-left;
       int H =(height[left] < height[right]) ? height[left] : height[right];
       area =width*H;
       if (area>MaxArea){
           MaxArea=area;
       }
       (height[left]<height[right]) ? left++:right--;
   }
    return MaxArea;
}