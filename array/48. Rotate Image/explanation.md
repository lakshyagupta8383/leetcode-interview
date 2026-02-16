# Rotate Image (LeetCode 48)

## 1. Problem Summary

Given an `n x n` 2D matrix representing an image, rotate the image by 90 degrees clockwise.

Constraints:
- You must rotate the matrix **in-place**.
- You cannot allocate another 2D matrix.
- Only constant extra space is allowed.

---

## 2. My Thought Process

Initial instinct:
If I directly apply the rotation formula:

(i, j) → (j, n - 1 - i)

It becomes messy to implement in-place because elements would overwrite each other.

So instead of performing rotation directly, I broke it into two simpler operations that together achieve the same effect:

1. Transpose the matrix
2. Reverse every row

Both operations can be done in-place using swaps.

This makes the solution clean, safe, and easy to reason about under interview pressure.

---

## 3. How I Implemented It

### Step 1: Transpose

Transpose means:
matrix[i][j] ↔ matrix[j][i]

We only swap elements in the upper triangle to avoid double swapping.

Code logic:

for i from 0 to n-1
    for j from i to n-1
        swap(matrix[i][j], matrix[j][i])

After transpose:
Rows become columns.

---

### Step 2: Reverse Each Row

Once transposed, we reverse every row.

for each row:
    reverse(row.begin(), row.end())

This converts the transposed matrix into the final rotated form.

---

## 4. Key Insight

90° clockwise rotation can be decomposed into:

Transpose  →  Reverse rows

Mathematically:

Original position:
(i, j)

After transpose:
(j, i)

After row reverse:
(j, n - 1 - i)

Which is exactly 90° clockwise rotation.

This avoids complex 4-way swaps and keeps the solution elegant.

---

## 5. Complexity

Time Complexity: O(n²)
- We visit each cell once during transpose.
- We reverse each row in O(n).

Space Complexity: O(1)
- Only constant extra space used.
- All swaps happen in-place.

---

## 6. Mistakes / Edge Cases

- Forgetting to start `j` from `i` (or `i + 1` in some implementations).
- Swapping full matrix instead of upper triangle, causing double swaps.
- Forgetting that matrix is guaranteed to be square.
- Trying to allocate another matrix (violates in-place constraint).

---

## 7. When To Revise

- When revising matrix transformations.
- When practicing in-place operations.
- Before interviews where spatial reasoning problems are common.
- When revising transpose-based tricks.

