// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
        
//         priority_queue<int, vector<int> , greater<int> > pq;

//         for(int num : nums){

//             if(pq.size()<k) pq.push(num);
//             else{
//                 if(pq.top()<num){
//                     pq.pop();
//                     pq.push(num);
//                 }
//             } 
//         } 

//         return pq.top();
//     }
// };


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return nums[nums.size() - k];
    }
};
