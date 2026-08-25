class Solution(object):
    def mySqrt(self, x):
        left = 0
        right = x
        if(x<2):
            return x
        while(left<=right):
            mid = left +(right -left)/2
            if (mid*mid==x):
                return mid
            elif (mid*mid < x):
                left = mid +1
            else : 
                right = mid-1
        
        return right
                

        