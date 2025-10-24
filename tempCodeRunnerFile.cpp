public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeroCount = 0;
        int maxLength = 0;
        
        // Expand window with right pointer
        for (int right = 0; right < nums.size(); right++) {
            // If we encounter a 0, increment zero count
            if (nums[right] == 0) {
                zeroCount++;
            }
            
            // If zero count exceeds k, shrink window from left
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            // Update maximum length (current window size)
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }