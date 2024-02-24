// Brute Force --> Just keep looping with 2 variables and 2 loops and then use another loop to calculate the sume and then compare the length using max

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int length = 0;
    int n = a.size();

    for(int i = 0; i<=n-1; i++){
        for(int j = i; j<=n-1; j++){
            long long sum = 0;
            for(int k = i; k<=j; k++){
                sum+=a[k];
            }

            if(sum==k){
                length = max(length,j-i+1 );
            }
        }
    }

    return length;

    
}

// optimizing the brute force --> just keep adding the a[j] whenever the pointer is moving to the previous sum

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int length = 0;
    int n = a.size();

    for(int i = 0; i<=n-1; i++){
        long long sum = 0;
        for(int j = i; j<=n-1; j++){
            sum = sum +a[j];

            if(sum==k){
                length = max(length,j-i+1 );
            }
        }
    }

    return length;

    
}

//third approach using hashmap storing indexes and prefix sum
#include<map>

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int length = 0;
    int n = a.size();
    map<long long, int> preSumMap; //prefix sum and index of the sum
    long long sum = 0;

    for(int i = 0; i<=n-1; i++){
        sum += a[i]; //keep adding to calculate the prefix sum upto that index

        if(sum == k){
            length = i+1; //if the sum is achieved is received at the last element the complete array length is the longest subarray
        }

        long long rem = sum - k; // the sum from the prefix sum index to current index (subarray sum)

        if (preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem]; // calculate the length is the remaining part only if it's not pointing to end
                length = max(length, len); //update the length
        }
        
        preSumMap[sum] = i; // add the prefix sum with index to map
    

    }

    return length;

    
}


//hashmaps but for arrays with zero
 int length = 0;
    int n = a.size();
    map<long long, int> preSumMap;
    long long sum = 0;

    for(int i = 0; i<=n-1; i++){
        sum += a[i];

        if(sum == k){
            length = i+1;
        }

        long long rem = sum - k;

        if (preSumMap.find(rem)!=preSumMap.end()) {
                int len = i - preSumMap[rem];
                length = max(length, len);
        }
        
        if(preSumMap.find(sum)==preSumMap.end()){

        preSumMap[sum] = i;
        }
    

    }

    return length;



//optimal approach --> two pointers 
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int length = 0;
    int n = a.size();
    int left = 0,  right =0;
    long long sum = a[0];

    while(right<n){

        // shrink the subarray by moving the left pointer if the sum exceeds target
        while (left <= right && sum > k) { 
            sum -= a[left];
            left++;
        }

        // update the length if required sum is achieved
        if (sum == k) {
            length = max(length, right - left + 1);
        }

        //update the right pointer
        right++;

        //if the right pointer is still in the correct place after updating then add the array element
        if(right<n)sum+=a[right];
    }
    

    return length;

    
}