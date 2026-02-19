# Merge Intervals – Explanation

## 1. Problem Summary

Given a list of intervals where each interval is represented as [start, end], merge all overlapping intervals and return the resulting non-overlapping intervals.

The goal is to combine intervals that intersect and ensure the final output contains only disjoint intervals.

---

## 2. My Thought Process

If intervals are sorted by their starting time, overlapping intervals will always appear next to each other.

So the plan is:

1. Sort the intervals.
2. Maintain a running interval using:
   - current_start
   - current_end
3. Traverse the remaining intervals:
   - If the next interval overlaps (start <= current_end), extend the current interval.
   - Otherwise, push the current interval to the result and reset.

The core idea is to maintain a running merged boundary.

---

## 3. How I Implemented It

1. Sort the intervals using sort().
2. Initialize:
   - current_start = intervals[0][0]
   - current_end = intervals[0][1]
3. Iterate from index 1 to n-1:
   - If intervals[j][0] <= current_end:
       current_end = max(current_end, intervals[j][1])
   - Else:
       Push {current_start, current_end} to result
       Reset current_start and current_end
4. After the loop, push the final interval.

---

## 4. Key Insight

After sorting, overlapping intervals become adjacent.

We only need to track the maximum ending boundary while traversing once.

Invariant maintained:
current_end = max(current_end, next_end)

---

## 5. Complexity (Time & Space)

Time Complexity: O(n log n) due to sorting  
Space Complexity: O(n) for storing the merged intervals

---

## 6. Mistakes / Edge Cases

- Accessing intervals[0] before sorting.
- Forgetting to push the last interval after the loop.
- Not updating current_end using max().
- Edge case when n <= 1.

---

## 7. When To Revise

- Before interviews.
- While solving similar problems like Insert Interval, Meeting Rooms, or Interval Intersection.
- When practicing greedy + sorting pattern problems.
