//missing number using sum of natural numbers
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        int sum = (n*(n+1))/2;
        int sumArr = 0;

        for(int i =0; i<=n-1; i++){
            sumArr += nums[i];
        }

        return (sum - sumArr);
       
    }

};

//bruteforce -> linear search

//using xor
// number^number = 0 
// 0^number = number 

class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n = nums.size();
        int ans =0;
        for(int i =1;i<=n;i++){
            ans = ans ^ i;
        }
        for(int i =0;i<nums.size();i++){
            ans= ans^nums[i];
        }
        return ans;
    }

};