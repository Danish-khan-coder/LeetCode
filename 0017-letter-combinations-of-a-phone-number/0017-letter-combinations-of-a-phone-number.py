def get_letters(num):
    letters = {
        2: ["a", "b", "c"],
        3: ["d", "e", "f"],
        4: ["g", "h", "i"],
        5: ["j", "k", "l"],
        6: ["m", "n", "o"],
        7: ["p", "q", "r", "s"],
        8: ["t", "u", "v"],
        9: ["w", "x", "y", "z"],
        
    }

    return letters.get(num, [])

class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        numbers=[int(digit) for digit in digits]
        lists=[]
        for number in numbers:
            lists.append(get_letters(number))  

        result=[""]

        for List in lists:
            new_result=[]
            for existing in result:
                for char in List:
                    new_result.append(existing + char)
            
            result=new_result
        
        return result


        