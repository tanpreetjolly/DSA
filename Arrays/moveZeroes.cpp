// move all non zeroes element to start

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nonZeroIndex = 0;
        for(int i = 0; i<n; i++){
           if(nums[i]!=0){
               swap(nums[nonZeroIndex], nums[i]);
               nonZeroIndex++;
           }
        }
    }
};


//two pointer approach
// j is the pointer to point at zero and i is non zero pointer
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1;

        for(int i =0; i<=n-1; i++){
            if(nums[i]==0){
                j = i;
                break;
            }
        }

        if (j == -1) return;

        for(int i = j+1; i<=n-1;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};