# LeetCode 75 Solutions

A collection of solutions to the LeetCode 75 problems implemented in C++.

## 📋 Problems Solved

| # | Problem | Solution | Difficulty |
|---|---------|----------|------------|
| 1 | [Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately/) | [merge_strings_alternately.cpp](merge_strings_alternately.cpp) | Easy |
| 2 | [Greatest Common Divisor of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/) | [gcd_of_strings.cpp](gcd_of_strings.cpp) | Easy |
| 3 | [Kids With the Greatest Number of Candies](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/) | [kids_with_candies.cpp](kids_with_candies.cpp) | Easy |
| 4 | [Can Place Flowers](https://leetcode.com/problems/can-place-flowers/) | [can_place_flowers.cpp](can_place_flowers.cpp) | Easy |
| 5 | [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/) | [reverse_vowels.cpp](reverse_vowels.cpp) | Easy |
| 6 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) | [reverse_words.cpp](reverse_words.cpp) | Medium |
| 7 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | [product_except_self.cpp](product_except_self.cpp) | Medium |
| 8 | [Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/) | [increasing_triplet.cpp](increasing_triplet.cpp) | Medium |
| 9 | [String Compression](https://leetcode.com/problems/string-compression/) | [string_compression.cpp](string_compression.cpp) | Medium |
| 10 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | [move_zeroes.cpp](move_zeroes.cpp) | Easy |
| 11 | [Is Subsequence](https://leetcode.com/problems/is-subsequence/) | [is_subsequence.cpp](is_subsequence.cpp) | Easy |
| 12 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | [container_with_most_water.cpp](container_with_most_water.cpp) | Medium |
| 13 | [Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs/) | [max_k_sum_pairs.cpp](max_k_sum_pairs.cpp) | Medium |
| 14 | [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/) | [maximum_average_subarray.cpp](maximum_average_subarray.cpp) | Easy |
| 15 | [Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/) | [max_vowels_in_substring.cpp](max_vowels_in_substring.cpp) | Medium |
| 16 | [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) | [max_consecutive_ones_iii.cpp](max_consecutive_ones_iii.cpp) | Medium |
| 17 | [Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/) | [longest_subarray_after_deleting_one.cpp](longest_subarray_after_deleting_one.cpp) | Medium |

## 🚀 How to Run

1. **Compile**: Use any C++ compiler (g++, clang++, etc.)
   ```bash
   g++ -o solution_name solution_name.cpp
   ```

2. **Run**: Execute the compiled binary
   ```bash
   ./solution_name
   ```

## 📁 Project Structure

```
├── merge_strings_alternately.cpp    # String manipulation problem
├── gcd_of_strings.cpp              # String GCD using mathematical approach
├── kids_with_candies.cpp           # Array traversal with max finding
├── can_place_flowers.cpp           # Greedy algorithm with boundary checks
├── reverse_vowels.cpp              # Two-pointer technique for character swapping
├── reverse_words.cpp               # Backward traversal with space handling
├── product_except_self.cpp         # Prefix/suffix arrays with space optimization
├── increasing_triplet.cpp          # Greedy algorithm with optimal tracking
├── string_compression.cpp          # Two-pointer in-place compression
├── move_zeroes.cpp                 # Two-pointer array partitioning
├── is_subsequence.cpp              # Two-pointer subsequence matching
├── container_with_most_water.cpp   # Two-pointer area maximization
├── max_k_sum_pairs.cpp             # Hash map frequency counting
├── maximum_average_subarray.cpp    # Sliding window technique
├── max_vowels_in_substring.cpp     # Sliding window with character counting
├── max_consecutive_ones_iii.cpp    # Variable-size sliding window
├── longest_subarray_after_deleting_one.cpp  # Variable-size sliding window with deletion
├── .gitignore                      # Ignore compiled files
└── README.md                       # This file
```

## 🎯 Problem Categories

- **String Manipulation**: Merge Strings Alternately, GCD of Strings, Reverse Vowels of a String, Reverse Words in a String, String Compression, Is Subsequence, Maximum Number of Vowels in a Substring of Given Length
- **Array Processing**: Kids With Candies, Can Place Flowers, Product of Array Except Self, Increasing Triplet Subsequence, Move Zeroes, Container With Most Water, Max Number of K-Sum Pairs, Maximum Average Subarray I, Max Consecutive Ones III, Longest Subarray of 1's After Deleting One Element
- **Greedy Algorithms**: Can Place Flowers, Increasing Triplet Subsequence, Container With Most Water
- **Two Pointer Technique**: Reverse Vowels of a String, Reverse Words in a String, String Compression, Move Zeroes, Is Subsequence, Container With Most Water, Max Number of K-Sum Pairs
- **Sliding Window**: Maximum Average Subarray I, Maximum Number of Vowels in a Substring of Given Length, Max Consecutive Ones III, Longest Subarray of 1's After Deleting One Element
- **Hash Map Techniques**: Max Number of K-Sum Pairs
- **Prefix/Suffix Arrays**: Product of Array Except Self
- **Subsequence Problems**: Increasing Triplet Subsequence, Is Subsequence
- **In-Place Algorithms**: String Compression, Move Zeroes
- **Array Partitioning**: Move Zeroes
- **Optimization Problems**: Container With Most Water, Max Number of K-Sum Pairs, Maximum Average Subarray I, Maximum Number of Vowels in a Substring of Given Length, Max Consecutive Ones III, Longest Subarray of 1's After Deleting One Element

## 💡 Key Algorithms & Concepts

- **Two Pointer Technique**: Used in string merging, vowel reversal, word processing, in-place compression, array partitioning, subsequence matching, area maximization, and k-sum pair finding
- **Sliding Window Technique**: Fixed-size and variable-size window optimization for subarray/substring problems with efficient add/remove operations
- **Variable-Size Sliding Window**: Dynamic window expansion and contraction based on conditions (e.g., maintaining constraint while maximizing window size)
- **Sliding Window with Deletion Constraint**: Special case where at most k elements can be flipped/deleted to maximize subarray length
- **Character Counting in Windows**: Tracking specific character types (vowels) within sliding windows
- **Hash Map Operations**: Frequency counting, complement search, and O(1) lookup for pair finding
- **GCD Algorithm**: Applied to string lengths for finding common divisors
- **Linear Search**: Finding maximum elements in arrays
- **Boolean Array Operations**: Efficient result storage
- **Greedy Algorithms**: Optimal flower placement, subsequence tracking, and container selection with local decisions
- **Boundary Condition Handling**: Edge cases for array start/end positions
- **Character Classification**: Efficient vowel detection using direct comparison and lambda functions
- **In-Place String Modification**: Memory-efficient string manipulation and compression
- **String Parsing**: Handling whitespace and word extraction
- **Backward Traversal**: Processing strings from end to beginning
- **Prefix/Suffix Arrays**: Computing cumulative products for array transformations
- **Space Optimization**: Reducing auxiliary space from O(n) to O(1)
- **Frequency Counting**: Using hash maps to track element occurrences for efficient pair matching
- **Window Sum Maintenance**: Efficiently maintaining sum of elements in a sliding window
- **Window Constraint Management**: Tracking and maintaining conditions (like count of specific elements) within windows
- **Lambda Functions**: Concise helper functions for character classification and conditions
- **Subsequence Detection**: Identifying patterns in arrays and strings with optimal state tracking
- **Greedy State Management**: Maintaining minimal necessary information for decision making
- **Read/Write Pointers**: Independent pointer movement for in-place array modification
- **Multi-Digit Number Handling**: Converting integers to character arrays efficiently
- **Array Partitioning**: Segregating elements while maintaining relative order
- **Element Relocation**: Moving specific elements to designated positions efficiently
- **Sequential Matching**: Finding ordered patterns across strings efficiently
- **Area/Volume Maximization**: Optimizing geometric problems with two-pointer approach
- **Greedy Pointer Movement**: Moving pointers based on potential for improvement

## 🔧 Requirements

- C++ compiler supporting C++11 or later
- Standard Template Library (STL)

## 📈 Progress

**Current Progress**: 17/75 problems solved

---

*Happy Coding! 🚀*