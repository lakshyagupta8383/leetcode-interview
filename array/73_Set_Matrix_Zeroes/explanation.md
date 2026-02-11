# 73. Set Matrix Zeroes

## 1. Problem Summary
Given an m x n matrix, if any element is 0, set its entire row and column to 0.
The solution must be in-place with O(1) extra space.

---

## 2. My Thought Process

First instinct:
Using two extra arrays to store which rows and columns should become zero.
That would take O(m + n) space.

Optimized idea:
Use the first row and first column as marker arrays instead of creating new ones.

Important realization:
If I directly use first row and first column as markers, I might lose whether they originally contained zero.
So I must store that information separately using two boolean variables.

---

## 3. How I Implemented It

Step 1:
Check if the first column contains any zero.
If yes → set `firstRow = true`.

Step 2:
Check if the first row contains any zero.
If yes → set `firstCol = true`.

Step 3:
Traverse the entire matrix.
Whenever I find a zero at (i, j):
- Mark the row by setting matrix[i][0] = 0
- Mark the column by setting matrix[0][j] = 0

Step 4:
Traverse again starting from index (1,1).
If matrix[i][0] == 0 OR matrix[0][j] == 0:
Set matrix[i][j] = 0.

Step 5:
If `firstCol` is true → zero out the entire first row.

Step 6:
If `firstRow` is true → zero out the entire first column.

---

## 4. Key Insight I Want To Remember

First row and first column act as storage for row and column markers.
But I must preserve their original state using two boolean variables.

The trick is:
Mark first → then update → then fix first row and first column at the end.

---

## 5. Complexity

Time Complexity: O(m × n)  
Space Complexity: O(1)

---

## 6. Mistakes / Edge Cases To Watch

- Forgetting to track first row and first column separately.
- Updating first row/column too early.
- Starting second traversal from (0,0) instead of (1,1).
- Mixing up which boolean controls row vs column.

---

## 7. When To Revise This

- If I forget how to reduce space from O(m + n) to O(1).
- If I struggle with in-place matrix marking problems.
- Before interviews where matrix manipulation questions are common.
