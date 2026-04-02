# Experiment 7: Cheapest Flights Within K Stops

## Problem Statement
There are n cities connected by flights. Each flight is represented as:
[from, to, price]

Find the cheapest price from source (src) to destination (dst) with at most k stops.
If no such route exists, return -1.

---

## Algorithm (Step-by-Step)

Step 1: Create an adjacency list from the given flights array.

Step 2: Initialize a queue to store (current_city, total_cost, stops).

Step 3: Create a distance array and initialize all values to infinity.

Step 4: Set distance[src] = 0 and push (src, 0, 0) into the queue.

Step 5: While the queue is not empty:
- Remove the front element (node, cost, stops).
- If stops > k, skip this path.
- For each neighbor of the current node:
  - Calculate new cost = cost + price.
  - If new cost < distance[neighbor]:
    - Update distance[neighbor].
    - Push (neighbor, new cost, stops + 1) into queue.

Step 6: After traversal:
- If distance[dst] is still infinity, return -1.
- Otherwise, return distance[dst].

---

## Dry Run

Input:
n = 4
flights = [[0,1,100],[1,2,100],[0,2,500],[2,3,200],[1,3,600]]
src = 0
dst = 3
k = 1

### Step-by-step Execution:

- Start from city 0  
  Possible paths:
   -0 → 1  cost = 100
   -0 → 2  cost = 500

- From city 1:
  - 1 → 2  cost = 100 + 100 = 200
  - 1 → 3  cost = 100 + 600 = 700

- From city 2:
  - 2 → 3  cost = 500 + 200 = 700

- From city 3:
  - 3 → 4
    - From path (0 → 1 → 3): cost = 600 + 150 = 750
    - From path (0 → 2 → 3): cost = 400 + 150 = 550

### Valid paths within k = 1 stops:
- 0 → 1 → 3   cost = 700
- 0 → 2 → 3   cost = 700

### Final Answer:
700
---

## Time Complexity
O(E + V)

---

## Space Complexity
O(V + E)

---
