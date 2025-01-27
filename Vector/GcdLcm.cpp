#include<iostream>
#include<vector>
using namespace std;

int gcdIterative(int a, int b) {
    while(a > 0) {
        int temp = a;
        a = b % a;
        b = temp;
    }
    return b;
}

int gcdRecursive(int a, int b) {
    if(a==0) {
        return b;
    }
    return gcdRecursive(b%a,a);
}

int findGCD(vector<int>& nums) {
    int result = nums[0];
    for(int i=1;i<nums.size();i++) {
        result = gcdIterative(nums[i], result);
        if(result==1) {
            return result;
        }
    }
    return result;
}

int main() {
    vector<int> arr { 2, 4, 6, 8, 16 };
    cout<<findGCD(arr);
    return 0;
}