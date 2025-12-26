from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        
        # Step 1: Transpose the matrix
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        # Step 2: Reverse each row
        for i in range(n):
            matrix[i].reverse()
            # Alternative: matrix[i] = matrix[i][::-1]


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    matrix1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print("Example 1:")
    print(f"Input: {matrix1}")
    solution.rotate(matrix1)
    print(f"Output: {matrix1}")
    print()
    
    # Example 2
    matrix2 = [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]
    print("Example 2:")
    print(f"Input: [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]")
    solution.rotate(matrix2)
    print(f"Output: {matrix2}")

"""
Time Complexity: O(n^2) - we visit each element twice (transpose + reverse)
Space Complexity: O(1) - in-place rotation, no extra space used

Approach:
1. Transpose: Convert rows to columns (swap matrix[i][j] with matrix[j][i])
2. Reverse: Reverse each row to complete the 90° clockwise rotation

Example visualization for [[1,2,3],[4,5,6],[7,8,9]]:
Original:       After Transpose:    After Reverse Rows:
1 2 3           1 4 7               7 4 1
4 5 6     -->   2 5 8         -->   8 5 2
7 8 9           3 6 9               9 6 3
"""
