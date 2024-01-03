// Query Kth Smallest Trimmed Number
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto x:queries)
        {
            priority_queue<pair<string,int>> pq;
            for(int i=0;i<nums.size();i++)
            {
                int t=nums[i].length()-x[1];
                string p=nums[i].substr(t,x[1]);
                if(pq.size()<x[0])
                    pq.push({p,i});
                else
                {
                    if(pq.top().first > p)
                    {
                        pq.pop();
                        pq.push({p,i});
                    }
                }
            }
            int value=pq.top().second;
            ans.push_back(value);
        }
        return ans;
    }
};

// DRY RUN
/*
Let's dry run the provided code using the given input:


nums = ["102","473","251","814"]
queries = [[1,1],[2,3],[4,2],[1,2]]
First Query [1,1]:

Trim each number in nums to its rightmost 1 digit:

nums = ["2","3","1","4"]
Use a priority queue to find the index of the 1st smallest trimmed number.
Initially, the priority queue is empty, so push the first element.

pq = [("2", 0)]
The smallest number is "1" at index 2.
Reset nums to its original state.
Add the result (index 2) to the answer vector.
Second Query [2,3]:

Trim each number in nums to its rightmost 3 digits (no change in nums).
Use a priority queue to find the index of the 2nd smallest trimmed number.
Initially, the priority queue is empty, so push the first two elements.

pq = [("251", 2), ("473", 1)]
The 2nd smallest number is "251" at index 2.
Reset nums to its original state.
Add the result (index 2) to the answer vector.
Third Query [4,2]:

Trim each number in nums to its rightmost 2 digits:

nums = ["02","73","51","14"]
Use a priority queue to find the index of the 4th smallest trimmed number.
Initially, the priority queue is empty, so push the first four elements.

pq = [("14", 3), ("51", 2), ("73", 1), ("02", 0)]
The 4th smallest number is "73" at index 1.
Reset nums to its original state.
Add the result (index 1) to the answer vector.
Fourth Query [1,2]:

Trim each number in nums to its rightmost 2 digits:

nums = ["02","73","51","14"]
Use a priority queue to find the index of the 1st smallest trimmed number.
Initially, the priority queue is empty, so push the first element.

pq = [("14", 3)]
The smallest number is "2" at index 0.
Reset nums to its original state.
Add the result (index 0) to the answer vector.
The final result is ans = [2, 2, 1, 0], which is the output for the given input.
*/