# 118. Pascal's Triangle

## 1. Problem Summary
Given an integer numRows, return the first numRows of Pascal's triangle.

Each number is the sum of the two numbers directly above it.

---

## 2. My Thought Process

Observation:
- First and last elements of every row are always 1.
- Every middle element is:
  previous_row[j - 1] + previous_row[j]

Idea:
Build the triangle row by row.
For each row:
- Initialize a vector of size (i + 1) filled with 1.
- Only compute the middle values.
- Use the previous row to calculate them.

This avoids complicated boundary checks because:
The first and last elements are already 1.

---

## 3. How I Implemented It

Step 1:
Create a result vector of size numRows.

Step 2:
For each row index i from 0 to numRows - 1:
- Create a temporary vector of size (i + 1) initialized with 1.

Step 3:
For indices j from 1 to i - 1:
- Set:
  current[j] = res[i - 1][j - 1] + res[i - 1][j]

Step 4:
Assign the constructed row to res[i].

Step 5:
Return the result.

---

## 4. Key Insight I Want To Remember

- Every row starts and ends with 1.
- Only compute values strictly inside the row.
- Use the previous row as reference.
- No need for extra conditions for edges if initialized with 1.

This is a classic bottom-up construction pattern.

---

## 5. Complexity

Time Complexity: O(n^2)  
Space Complexity: O(n^2)

Where n = numRows.

---

## 6. Mistakes / Edge Cases To Watch

- Incorrect loop bounds for j (must be 1 to i - 1).
- Forgetting that row size is i + 1.
- Accessing res[i] before it is constructed.
- Off-by-one errors in indexing.

---

## 7. When To Revise This

- Before combinatorics or triangle-based DP problems.
- If I struggle with 2D vector construction.
- When reviewing bottom-up dynamic building patterns.
