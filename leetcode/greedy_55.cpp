/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/


#include <vector>
#include <iostream>
using namespace std;

bool canJump(vector<int>& nums) {
    int goal = nums.size()-1;
    for(int i=nums.size()-2;i>=0;i--) {
        if((nums[i]+i)>=goal) {
            goal=i;
        }
    }
    return goal==0;
}

int main() {
    vector<int> nums1 {2,3,1,1,4};
    cout<<canJump(nums1)<<endl;
    vector<int> nums2 {3,2,1,0,4};
    cout<<canJump(nums2)<<endl;
    return 0;
}