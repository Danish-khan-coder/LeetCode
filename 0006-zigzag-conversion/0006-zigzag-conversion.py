class Solution(object):
    def convert(self, s, numRows):
        
        # If there is only one row,
        # zigzag conversion changes nothing
        if numRows == 1:
            return s
        
        rows = [""] * numRows
        
        current_row = 0
        direction = 1
        
        for char in s:
            
            # Add character to current row
            rows[current_row] += char
            
            # If we reach the top, move downward
            if current_row == 0:
                direction = 1
            
            # If we reach the bottom, move upward
            elif current_row == numRows - 1:
                direction = -1
            
            # Move to next row
            current_row += direction
        
        # Join all rows together
        return "".join(rows)