/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

#include <vector>
#include <iostream>
using namespace std;

int maxArea(vector<int>& height) {
    int i=0,j=height.size()-1;
    int max_area = 0;
    while(i<j) {
        int curr_area = (j-i)*min(height.at(j),height.at(i));
        max_area = max(max_area, curr_area);
        if(height.at(i)<height.at(j)) {
            i++;
        }
        else {
            j--;
        }
    }   
    return max_area;
}

int main() {
    vector<int> height1 {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height1)<<endl;
    vector<int> height2 {1,1};
    cout<<maxArea(height2)<<endl;
    return 0;
}