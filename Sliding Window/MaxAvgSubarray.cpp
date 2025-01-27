#include<iostream>
#include<vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int start = 0, end = k;
    double curr_avg = 0, max_avg = 0;
    if(end>nums.size()) {
        return -1;
    }
    for(int i=start;i<end;i++) {
        curr_avg += nums.at(i);
    }
    curr_avg = curr_avg;
    max_avg = curr_avg;
    for(int i=end;i<nums.size();i++) {
        curr_avg = curr_avg+(nums.at(i)-nums.at(start));
        max_avg = max(max_avg, curr_avg);
        start++;
    }
    return max_avg/k;
}

int main() {
    vector<int> arr {1,12,-5,-6,50,3};
    int k = 4;
    cout<<findMaxAverage(arr,k);
    return 0;
}