//brute force -> just sort the array and then compare each element by looping

//optimal --> compare adjacent
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i =1; i<=n-1; i++){
            if(nums[i-1]> nums[i]) cnt++;
        }
        return true;
    }
};
