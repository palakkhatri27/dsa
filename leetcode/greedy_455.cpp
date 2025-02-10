/*
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int i=0,j=0,count=0;
    while(i<g.size() && j<s.size()) {
        if(g.at(i)<=s.at(j)) {
            count++;
            i++;
            j++;
        }
        else {
            j++;
        }
    }
    return count;
}

int main() {
    vector<int> g1 {1,2};
    vector<int> s1 {1,2,3};
    cout<<findContentChildren(g1,s1)<<endl;
    vector<int> g2 {1,2,3};
    vector<int> s2 {1,1};
    cout<<findContentChildren(g2,s2)<<endl;
    return 0;
}