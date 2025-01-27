#include <iostream>
#include <vector>
using namespace std;

bool twoSum(vector<int> a, int target) {
    int i=0,j=a.size()-1,sum=0;

    while(i<j) {
        sum = a.at(i)+a.at(j);
        if(sum==target) {
            return true;
        }
        else if(sum<target) {
            i++;
        }
        else {
            j--;
        }
    }

    return false;
}

int main(){
    vector<int> arr = {-3, -1, 0, 1, 2};
    int target = -2;
    if (twoSum(arr, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}