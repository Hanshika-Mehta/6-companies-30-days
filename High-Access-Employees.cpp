//2933. High-Access Employees


class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        //name-> access_times 
        unordered_map<string , vector<int> >mp;
        for(auto &it : access_times){
            int time= stoi(it[1]);
            mp[it[0]].push_back(time);
        }
        //sort each employee access times
        for(auto &it : mp)
        {
            sort(it.second.begin() ,it.second.end());
        }

        //scan sorted access timesto check if accessed > = 3 times
        vector<string>ans;
        for(auto &it :mp){
            vector<int> &time = it.second;
            for(int i = 2; i<time.size(); i++)
            {
                if(time[i] - time[i-2] < 100){
                //store employee in ans and move to other employee
                ans.push_back(it.first);
                break;
                }
            }
        }
        return ans;
    }
};

// time complexity - o(n) + logn + o(n) = o(n)
//DRY RUN
/*

Let's dry run the provided code using the given input:


access_times = [["a","0549"],["b","0457"],["a","0532"],["a","0621"],["b","0540"]]
Build the Map:

mp (unordered map) is created to store the access times for each employee.
After processing the input, mp will look like this:

a: [532, 549, 621]
b: [457, 540]

Sort the Access Times:
For each employee in mp, sort their access times in ascending order.
After sorting, mp becomes:

a: [532, 549, 621]
b: [457, 540]

Identify High-Access Employees:
Iterate through each employee in mp.
For each employee, iterate through their sorted access times starting from the third time.
Check if the time difference between the current and the second previous access time is less than 100.
If the condition is met, add the employee to the result vector ans.
Let's go through the iterations:

Employee "a":

Start iterating from the third access time (621).
Calculate the time difference (621 - 532 = 89), which is less than 100.
Add "a" to the result vector ans.
Employee "b":

Start iterating from the third access time (540), but there are only two access times, so no further iteration.
"b" does not meet the condition.
The final result is ans = ["a"], which is the output for the given input.

This indicates that "a" is a high-access employee according to the given conditions.*/