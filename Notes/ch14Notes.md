# Chapter 14 Notes

## Key Definitions

- **Array** — collection of elements stored in sequence, accessed by index
- **VAL** — target value being searched for
- **POS** — position/index where VAL is found; initialized to -1
- **BEG / END** — boundaries of current search segment
- **MID** — middle index = (BEG + END) / 2
- **Big-O Notation** — measures steps needed as array size (n) grows
  - O(1): constant time
  - O(n): grows linearly
  - O(log n): grows logarithmically (much faster)
  - O(√n): grows by square root
- **Sorted list** — elements arranged in order (ascending or descending)
- **Unsorted list** — elements in no particular order
- **Sequential** — one after another, in order
- **Divide-and-conquer** — split problem in half repeatedly to solve faster

## Introduction

- **Searching**: process of determining whether a specific value exists in an array
  - Successful search → returns position
  - Unsuccessful search → returns message (POS = -1)
- **Sorting**: rearranging array elements into a defined order (ascending or descending)
- Searching is a fundamental operation in computer science
- Choice of searching method depends on data organization:
  - Unsorted data → Linear Search
  - Sorted data → Binary Search, Jump Search, Interpolation Search, Fibonacci Search

## Linear Search (Sequential Search)

- **Definition**: simple searching method that checks each element one-by-one until match is found
- Works on **unsorted arrays**
- No preprocessing required

### How It Works
1. Set POS = -1, I = 1
2. Start from first element
3. Compare each element with VAL
4. If match found → record POS and return
5. If end reached with no match → value not present

### Time Complexity
- Best case: O(1) → value at first position
- Worst case: O(n) → value at last position or not present
- Average case: O(n)

### Key Idea
- Simple but inefficient for large datasets

## Binary Search

- **Definition**: searching algorithm for sorted arrays that repeatedly divides search space in half
- **Requirement**: array must be sorted

### How It Works
1. Set BEG = lower bound, END = upper bound, POS = -1
2. While BEG ≤ END:
   - MID = (BEG + END) / 2
   - If A[MID] = VAL → found, exit
   - If VAL < A[MID] → search left half (END = MID - 1)
   - If VAL > A[MID] → search right half (BEG = MID + 1)
3. If BEG > END → value not present

### Time Complexity
- Best case: O(1) → found at middle
- Worst case: O(log n)
- Average case: O(log n)

### Key Idea
- Efficient because it eliminates half of the data each step

## Interpolation Search

- **Definition**: searching algorithm for sorted arrays that estimates likely position based on value distribution
- **Requirement**: sorted array (works best with uniformly distributed data)

### How It Works
- Instead of checking middle, estimate position using formula:
  - MID = LOW + (HIGH - LOW) × ((VAL - A[LOW]) / (A[HIGH] - A[LOW]))
- Compare estimated position with VAL:
  - If match → done
  - If VAL < A[MID] → search left half
  - If VAL > A[MID] → search right half

### Time Complexity
- Best case: O(1)
- Average case: O(log log n)
- Worst case: O(n) (when data is exponentially distributed)

### Key Idea
- Faster than binary search when values are evenly distributed
- Estimates position like finding a word starting with "A" near dictionary front

---

## Jump Search (Block Search)

- **Definition**: searching algorithm for sorted arrays that skips ahead in fixed-size blocks
- **Requirement**: array must be sorted

### How It Works
1. Choose step size (optimal = √n)
2. Jump ahead in blocks:
   - Compare last element of each block with VAL
   - Stop when element > VAL (boundary found)
3. Perform linear search within that block

### Example (finding 8 in {1,2,3,4,5,6,7,8,9}, step = 3)
- Check index 3 → value 3 < 8, jump ahead
- Check index 6 → value 6 < 8, jump ahead
- Check index 9 → value 9 > 8 → boundary found
- Linear search between index 6 and 9 → find 8

### Time Complexity
- Best case: O(1)
- Worst case: O(√n)
- Average case: O(√n)

### Advantages
- Over linear search: far fewer comparisons on sorted data
- Over binary search: better when backward jumps are expensive

### Key Idea
- Hybrid approach: jumping reduces search space, linear search finds exact position

## Fibonacci Search

- **Definition**: searching algorithm for sorted arrays using Fibonacci numbers to divide search space
- **Requirement**: array must be sorted

### How It Works
- Based on Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...
- Instead of dividing by 2 (binary search), subtract a Fibonacci number from index
- Uses divide-and-conquer strategy

### Time Complexity
- Best case: O(1)
- Worst case: O(log n)
- Average case: O(log n)

### Key Idea
- Lower comparison dispersion than binary search
- Useful when division operation is expensive

## Summary Comparison

| Algorithm | Requires Sorted Data | Best Case | Average Case | Worst Case | Key Idea |
|-----------|---------------------|-----------|--------------|------------|----------|
| Linear Search | No | O(1) | O(n) | O(n) | Check every element |
| Binary Search | Yes | O(1) | O(log n) | O(log n) | Divide search space in half |
| Interpolation | Yes | O(1) | O(log log n) | O(n) | Estimate position using distribution |
| Jump Search | Yes | O(1) | O(√n) | O(√n) | Jump in fixed-size blocks |
| Fibonacci Search | Yes | O(1) | O(log n) | O(log n) | Divide using Fibonacci numbers |


## Introduction to Sorting

- **Definition**: rearranging array elements into a defined order
- **Ascending order**: smallest to largest (A[0] < A[1] < ... < A[N])
- **Descending order**: largest to smallest
- **Lexicographical order**: dictionary/alphabetical order

### Types of Sorting
- **Internal sorting**: data fits in memory
- **External sorting**: data too large for memory; stored in files

### Sorting on Multiple Keys
- When one field isn't enough to identify a record, sort by multiple fields
- Example: employees sorted by department first, then alphabetically by name

### Key Idea
- Sorting enables faster searching algorithms (binary search, jump search, etc.)
