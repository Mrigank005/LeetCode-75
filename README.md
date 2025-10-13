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
├── .gitignore                      # Ignore compiled files
└── README.md                       # This file
```

## 🎯 Problem Categories

- **String Manipulation**: Merge Strings Alternately, GCD of Strings, Reverse Vowels of a String, Reverse Words in a String
- **Array Processing**: Kids With Candies, Can Place Flowers, Product of Array Except Self
- **Greedy Algorithms**: Can Place Flowers
- **Two Pointer Technique**: Reverse Vowels of a String, Reverse Words in a String
- **Prefix/Suffix Arrays**: Product of Array Except Self

## 💡 Key Algorithms & Concepts

- **Two Pointer Technique**: Used in string merging, vowel reversal, and word processing
- **GCD Algorithm**: Applied to string lengths for finding common divisors
- **Linear Search**: Finding maximum elements in arrays
- **Boolean Array Operations**: Efficient result storage
- **Greedy Algorithms**: Optimal flower placement with local decisions
- **Boundary Condition Handling**: Edge cases for array start/end positions
- **Character Classification**: Efficient vowel detection using direct comparison
- **In-Place String Modification**: Memory-efficient string manipulation
- **String Parsing**: Handling whitespace and word extraction
- **Backward Traversal**: Processing strings from end to beginning
- **Prefix/Suffix Arrays**: Computing cumulative products for array transformations
- **Space Optimization**: Reducing auxiliary space from O(n) to O(1)

## 🔧 Requirements

- C++ compiler supporting C++11 or later
- Standard Template Library (STL)

## 📈 Progress

**Current Progress**: 7/75 problems solved

---

*Happy Coding! 🚀*