# Maximum Subarray (Kadane’s Algorithm)

## 1. Problem Summary

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

The subarray must be continuous.

Constraints:
- Array can contain positive, negative, and zero values.
- At least one element exists.

---

## 2. My Thought Process

Initial thought:
Try generating all subarrays and calculate their sums.

Brute force:
- Generate all subarrays → O(n²)
- Compute sum each time → O(n³) or optimize to O(n²)

Too slow for large inputs.

Key observation:
If the running sum becomes negative, it will only reduce the sum of any future subarray.

So instead of checking all subarrays, we decide at each index:

Should I:
- Extend the previous subarray?
- Or start a new subarray from this element?

This leads to Kadane’s Algorithm.

---

## 3. How I Implemented It

Maintain two variables:

- `currentSum` → maximum subarray sum ending at current index
- `maxSum` → maximum subarray sum found so far

At each index:

```
currentSum = max(nums[i], currentSum + nums[i])
maxSum = max(maxSum, currentSum)
```

Logic:
- If previous sum is harmful (negative), start fresh.
- Otherwise extend it.

Initialize both with `nums[0]`.

---

## 4. Key Insight

If the running sum becomes negative, discard it.

A negative prefix can never help build a maximum future subarray.

At every index, we choose:
Start fresh OR extend previous.

That local decision guarantees global maximum.

---

## 5. Complexity

Time Complexity: O(n)  
Space Complexity: O(1)

Single pass, constant space.

---

## 6. Mistakes / Edge Cases

Common mistakes:

- Initializing `maxSum` as 0 (fails for all-negative arrays)
- Forgetting that subarray must contain at least one element
- Not handling single-element arrays

Edge Case:

Input: [-3, -2, -5]  
Correct answer: -2  
Must not return 0.

---

## 7. When To Revise

Mark for revision if:

- I forget why negative prefix is discarded
- I confuse it with sliding window
- I fail on all-negative test case

Revision Level:
- R1 if minor confusion
- R2 if pattern not immediately recognized
- INTERVIEW-FAVORITE (very common question)
