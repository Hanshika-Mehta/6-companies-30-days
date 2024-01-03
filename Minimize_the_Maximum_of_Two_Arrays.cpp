//2513. Minimize the Maximum of Two Arrays
class Solution {
public:
    int minimizeSet(int div1, int div2, int cnt1, int cnt2) {
        // Calculate the least common multiple (LCM) of div1 and div2
        long long lcm = (static_cast<long long>(div1) * div2) / __gcd(div1, div2);

        
        // Initialize variables for binary search
        long long total = cnt1 + cnt2;
        long long l = total, r = 1e12;
        long long ans = 0;

        // Perform binary search
        while (l <= r) {
            long long mid = (l + r) / 2;

            // Calculate the count of numbers divisible by both div1 and div2
            long long both = mid / lcm;
            // Calculate the count of numbers divisible only by div2
            long long onlyA = mid / div2 - both;
            // Calculate the count of numbers divisible only by div1
            long long onlyB = mid / div1 - both;

            // Calculate the total count of numbers that satisfy the conditions
            total = max(0ll, cnt1 - onlyA) + max(0ll, cnt2 - onlyB);

            // Check if the current mid satisfies the conditions
            if (mid - onlyA - onlyB >= total + both) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        // Return the minimum possible maximum integer
        return ans;
    }
};
//DRY RUN 
/*
divisor1 = 2
divisor2 = 7
uniqueCnt1 = 1
uniqueCnt2 = 3


1. Calculate the LCM of divisor1 and divisor2: lcm = (2 * 7) / gcd(2, 7) = 14 / 1 = 14
2. Initialize total as the sum of cnt1 and cnt2: total = 1 + 3 = 4
3. Initialize the search space for the binary search: l = total = 4 and r = 1e12 (a very large number)
4. Perform binary search:
5. In each iteration, calculate counts for numbers divisible by both, only by div1, and only by div2.
6. Adjust the total count based on the numbers that satisfy the conditions.
7. Update the answer (ans) if the current mid satisfies the conditions.
8. Narrow down the search space based on the results of the current mid.
9 .The binary search concludes, and the final answer is returned.
With the given inputs, the output should be 4, which is the minimum possible maximum integer satisfying the conditions.*/