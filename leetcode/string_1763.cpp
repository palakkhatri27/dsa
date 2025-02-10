/*
A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.
*/
#include<unordered_map>
#include<string>
#include<iostream>
#include <ctype.h>
using namespace std;


bool isNice(string s, int i, int j) {
    unordered_map<int, bool> u_map;
    for(int x=i;x<=j;x++) {
        u_map[s.at(x)] = true;
    }
    for(int x=i;x<=j;x++) {
        if(islower(s.at(x))) {
            if(u_map[s.at(x)-32]==false) {
                return false;
            }
        }
        else {
            if(u_map[s.at(x)+32]==false) {
                return false;
            }
        }
    }
    return true;
}
string longestNiceSubstring(string s) {
    string res = "";
    for(int i=0;i<s.length();i++) {
        for(int j=i;j<s.length();j++) {
            if(isNice(s,i,j)) {
                if((j-i+1)>res.size()) {
                    res = s.substr(i, j - i + 1);
                }
            }
        }
    }
    return res;
}
int main() {
    string s1 = "YazaAay";
    string s2 = "Bb";
    string s3 = "c";
    
    cout<<s1<<' '<<longestNiceSubstring(s1)<<endl;
    cout<<s2<<' '<<longestNiceSubstring(s2)<<endl;
    cout<<s3<<' '<<longestNiceSubstring(s3)<<endl;
    return 0;
}