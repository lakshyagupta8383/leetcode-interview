# Sort Colors (LeetCode 75)

## 1. Problem Summary

Given an array `nums` containing only `0`, `1`, and `2`, sort the array in-place such that:
- All `0`s come first
- Then all `1`s
- Then all `2`s

Constraints:
- Must modify array in-place
- One-pass solution preferred
- Constant extra space preferred


## 2. My Thought Process

Initial thought:
Just use `sort()`.

But that gives O(n log n), which is unnecessary because:
- The array only contains three distinct values.

This is not really a sorting problem.
It is a partitioning problem.

Instead of comparing elements, I can maintain boundaries for:
- 0 region
- 1 region
- 2 region

This leads to the Dutch National Flag approach using three pointers.


## 3. How I Implemented It

Used three pointers:
- `low`  → next position for 0
- `mid`  → current scanning pointer
- `high` → next position for 2

Logic:
- If `nums[mid] == 0`
  → swap with `low`
  → increment both `low` and `mid`

- If `nums[mid] == 1`
  → just increment `mid`

- If `nums[mid] == 2`
  → swap with `high`
  → decrement `high`
  → do NOT increment `mid` (re-check swapped element)

Loop continues while `mid <= high`.


## 4. Key Insight

Maintain this invariant at all times:

[0 ... low-1]      → all 0s  
[low ... mid-1]    → all 1s  
[mid ... high]     → unknown  
[high+1 ... end]   → all 2s  

Important detail:
- When swapping with `low`, we know that position contains 1 (safe to move forward).
- When swapping with `high`, the incoming value is unknown, so we must re-check it.


## 5. Complexity (Time & Space)

Time Complexity: O(n)  
Each element is processed at most once.

Space Complexity: O(1)  
Only three pointers used.


## 6. Mistakes / Edge Cases

Common mistakes:
- Using two separate `if` instead of `if / else if`
- Incrementing `mid` after swapping with `high`
- Not understanding pointer invariants

Edge cases:
- All elements same
- Already sorted
- Reverse sorted
- Single element array


## 7. When To Revise

Revise when reviewing:
- Two pointer techniques
- Dutch National Flag pattern
- In-place partition problems
- QuickSort partition logic
- Problems with limited distinct values
