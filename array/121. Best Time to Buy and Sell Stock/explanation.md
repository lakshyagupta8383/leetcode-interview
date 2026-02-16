# Best Time to Buy and Sell Stock (LeetCode 121) – O(n) DP Version

## 1. Problem Summary

Given an array `prices` where `prices[i]` represents the stock price on day `i`, return the maximum profit you can achieve.

Rules:
- You may complete at most ONE transaction.
- You must buy before you sell.
- If no profit is possible, return 0.

---

## 2. My Thought Process

This problem can be modeled as a state machine.

On any day, I can be in one of two states:

dp[i][0] → holding a stock  
dp[i][1] → not holding a stock  

Since only ONE transaction is allowed:
- I can buy once.
- After selling, I cannot buy again.

So the holding state should only consider:
- continuing to hold
- buying for the first time

It should NOT allow re-buying after selling.

---

## 3. How I Implemented It

State definition:

dp[i][0] = max profit on day i while holding  
dp[i][1] = max profit on day i while not holding  

Initialization:

dp[0][0] = -prices[0]  
dp[0][1] = 0  

Transition:

Holding state:
dp[i][0] = max(dp[i-1][0], -prices[i])

Not holding state:
dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i])

Final answer:
dp[n-1][1]

---

## 4. Key Insight

The holding state represents:
"The best price at which I could have bought so far."

The not-holding state represents:
"The best profit I could have achieved so far."

Because only one transaction is allowed, the holding state must NOT depend on dp[i-1][1] - prices[i].  
That would allow multiple transactions.

---

## 5. Complexity (Time & Space)

Time Complexity: O(n)  
We iterate once through the array.

Space Complexity: O(n)  
We maintain a DP table of size n × 2.

---

## 6. Mistakes / Edge Cases

- Forgetting to handle empty array.
- Accidentally allowing multiple transactions (using dp[i-1][1] - prices[i]).
- Returning dp[n-1][0] instead of dp[n-1][1].
- Always return 0 if prices are strictly decreasing.

---

## 7. When To Revise

- When revising stock DP state-machine problems.
- Before solving 122, 309, 714 (variations).
- When practicing DP transitions and state definitions.
- If you mix up 121 and 122 logic.
