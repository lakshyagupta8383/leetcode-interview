# Maximum Product Subarray

## 1. Problem Summary

Given an integer array `nums`, find the contiguous subarray within the array that has the largest product, and return the product.

The subarray must be continuous and contain at least one element.

The array may contain:
- Positive numbers
- Negative numbers
- Zeros

---

## 2. My Thought Process

Initial idea:
Try brute force — generate all subarrays and compute product.

That would be O(n²), too slow.

Observation:
This looks similar to Maximum Subarray (Kadane's Algorithm).

But multiplication behaves differently:
- Negative × Negative = Positive
- A very small (negative) value can become very large after multiplying another negative.
- Zero completely resets product chains.

So unlike sum, we cannot track only maximum.
We must also track minimum.

Why?
Because the minimum (most negative) product can become maximum if multiplied by a negative number.

This leads to tracking both maximum and minimum product at each index.

---

## 3. How I Implemented It

Maintain three variables:

- `maxProd` → maximum product ending at current index
- `minProd` → minimum product ending at current index
- `result` → global maximum product

Initialize all with `nums[0]`.

For every index `i` from 1 to n-1:

1. If `nums[i]` is negative:
   - Swap `maxProd` and `minProd`

2. Update:
   ```
   maxProd = max(nums[i], maxProd * nums[i])
   minProd = min(nums[i], minProd * nums[i])
   ```

3. Update result:
   ```
   result = max(result, maxProd)
   ```

Return result.

---

## 4. Key Insight

Track BOTH maximum and minimum product at every step.

Reason:
A negative number flips signs.

The previous minimum product might become the new maximum if multiplied by a negative number.

Without tracking `minProd`, we lose potential large positive results.

This is modified Kadane's Algorithm.

---

## 5. Complexity

Time Complexity: O(n)  
Space Complexity: O(1)

Single pass with constant extra variables.

---

## 6. Mistakes / Edge Cases

Common mistakes:

- Tracking only maximum (fails on negative chains)
- Forgetting to swap when current number is negative
- Initializing result as 0 (fails on all-negative arrays)
- Not handling zero correctly

Edge Case 1:
Input: [-2, 3, -4]  
Output: 24

Edge Case 2:
Input: [0, -2, 0]  
Output: 0

Edge Case 3:
Input: [-1]  
Output: -1

---

## 7. When To Revise

Revise if:

- I forget why swap is required
- I fail to explain why minimum is tracked
- I confuse it with normal Kadane
