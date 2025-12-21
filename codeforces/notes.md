## 1747C Swap Game
Key insight: if a[0] == min, the player loses. Otherwise, the player wins.

# 800
## 1903A Halloumi Boxes
Key insight: reversing the subarray with two elements is enough to sort the array. Check if the array is sorted or k > 1;

## 1901A Line Trip
Key insight: track max distance between two points. Make sure to track last round trip.

## 1900A Cover in Water
Key insight: find 3 consecutive dots. If found, we can fill them out with 2 moves and then reuse middle one to fill out other dots. Return 2. Otherwise return number of dots.

## 1899A Game with Integers
Key insight: if n-1%3 or n+1%3 == 0, first player wins.

# 1000
## 1913B Swap and Delete
1913B_swap_and_delete
Key insight: count 1s and 0s. Then run a second pass to find first index when we cannot swap 0 and 1. Result is n - index.
