# Experiment 9 - Partition Array with Minimum Difference

## Problem Description

Given an array of `n` positive integers, divide it into two subsets such that the difference between their sums is minimized.

In other words, split the array into two subsets **S1** and **S2** such that:

`| sum(S1) - sum(S2) |` is as small as possible.

**Reference:** [https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1](https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1)

---

## Algorithm

```
1. Compute totalSum = sum of all elements in the array
2. Create a boolean array dp[0...totalSum]
   where dp[j] tells whether a subset with sum j is possible
3. Initialize dp[0] = true
4. For each element in the array:
       For j from totalSum down to the element value:
           dp[j] = dp[j] OR dp[j - element]
5. Traverse from totalSum/2 down to 0:
       The first j where dp[j] is true gives:
       minimum difference = totalSum - 2*j
```

---

## Code (C++)

```cpp
class Solution {
public:
    int minDifference(vector<int>& arr) {
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }

        vector<bool> dp(totalSum + 1, false);
        dp[0] = true;

        for (int num : arr) {
            for (int j = totalSum; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        for (int j = totalSum / 2; j >= 0; j--) {
            if (dp[j]) {
                return totalSum - 2 * j;
            }
        }

        return 0;
    }
};
```

---
## Dry Run

**Input:** 
`n = 4`, `arr = [3, 1, 4, 2]`

**Step 1:Total Sum**

Total sum = 3 + 1 + 4 + 2 = 10

**Step 2: Initialize DP**

We create a DP array where:
dp[i] = true means subset with sum i is possible

**Initially:**
dp[0] = true (empty subset)

**Step 3:** 
Build Possible Subset Sums:

- After 3 → {0, 3}
- After 1 → {0, 1, 3, 4}
- After 4 → {0, 1, 3, 4, 5, 7, 8}
- After 2 → {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

**Step 4: Find Minimum Difference**

We check from totalSum / 2 = 5 downwards:

- dp[5] = true
- So subset sums are:
- One subset = 5
- Other subset = 10 - 5 = 5

Minimum difference = |5 - 5| =**0**

---

## Time and Space Complexity

| Metric           | Value       | Description                          |
|------------------|-------------|--------------------------------------|
| Time Complexity  | O(n × sum)  | DP computation over all sums         |
| Space Complexity | O(sum)      | Boolean DP array                     |

> Constraints: n ≤ 100, arr[i] ≤ 1000

---

## Example

**Input:**
```
1
4
1 6 11 5
```

**Output:**
```
1
```

**Explanation:**  
One possible partition is `{1, 5, 6}` (sum = 12) and `{11}` (sum = 11).  
The difference between sums is **1**.

---

## Code Accepted Screenshot

![Code Accepted](./output.png)
