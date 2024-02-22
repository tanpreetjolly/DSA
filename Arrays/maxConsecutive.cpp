class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxNumber = 0;
        int count =0;

        for(int i =0; i<nums.size();i++){
            if(nums[i]&1){
                count++;
                maxNumber= max(count, maxNumber);
            }
            else{
                count=0;
            }
        }

        return maxNumber;
    }
};