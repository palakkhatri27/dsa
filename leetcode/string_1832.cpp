/*
A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
*/
#include<unordered_set>
#include<string>
#include<iostream>
using namespace std;


bool checkIfPangram(string sentence) {
    unordered_set<int> hashSet;
    for(int i=0;i<sentence.length();i++) {
        int curr = sentence.at(i)-97;
        hashSet.insert(curr);
    }
    if(hashSet.size()==26) {
        return true;
    }
    return false;
}

int main() {
    string s1 = "thequickbrownfoxjumpsoverthelazydog";
    string s2 = "leetcode";
    
    cout<<s1<<' '<<checkIfPangram(s1)<<endl;
    cout<<s2<<' '<<checkIfPangram(s2)<<endl;
}