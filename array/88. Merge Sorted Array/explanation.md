# LeetCode 88 – Merge Sorted Array

## 1. Problem Summary

We are given two sorted arrays:

- nums1 of size m + n
  - The first m elements are valid.
  - The last n elements are placeholders.
- nums2 of size n.

We must merge nums2 into nums1 in-place so that nums1 remains sorted.

Constraints:
- Modify nums1 directly.
- Do not use extra space.
- Target time complexity: O(m + n).

---

## 2. My Thought Process

Since both arrays are already sorted, sorting again would increase time complexity unnecessarily.

If we merge from the beginning, we risk overwriting valid elements in nums1.

To avoid overwriting, the correct strategy is to merge from the end:

- Compare the largest remaining elements from both arrays.
- Place the larger one at the last available position in nums1.
- Move pointers backward.

This ensures that we never lose any required values.

---

## 3. How I Implemented It

I used three pointers:

- One pointer at the last valid element of nums1.
- One pointer at the last element of nums2.
- One pointer at the last index of nums1.

Steps followed:

1. Compare elements from the back of both arrays.
2. Place the larger element at the back of nums1.
3. Move pointers accordingly.
4. If nums2 still has elements remaining after the main loop, copy them into nums1.
5. If nums1 has remaining elements, no action is required because they are already correctly placed.

---

## 4. Key Insight

Merging from the back prevents overwriting valid data.

Since nums1 already has enough space at the end, we can safely fill it starting from the largest elements.

Only leftover elements from nums2 need explicit copying.

---

## 5. Complexity (Time & Space)

Time Complexity: O(m + n)  
Space Complexity: O(1)

---

## 6. Mistakes / Edge Cases

Common mistakes:
- Merging from the front and overwriting elements.
- Incorrect loop condition causing index out-of-bounds.
- Forgetting to copy remaining nums2 elements.

Edge cases:
- m = 0 → copy all elements from nums2.
- n = 0 → nums1 remains unchanged.
- Duplicate values are handled naturally.
- Negative numbers require no special handling.

---

## 7. When To Revise

- Before interviews covering two-pointer techniques.
- When revising in-place array manipulation problems.
- While reviewing merge logic concepts used in merge sort.
