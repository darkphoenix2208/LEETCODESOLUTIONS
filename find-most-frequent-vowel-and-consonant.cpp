// Problem  : Find Most Frequent Vowel and Consonant
// Difficulty: Easy
// Tags     : Hash Table, String, Counting
// URL      : https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/
// Solved on: 2026-04-09 00:12
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int>freq;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        int sum=0;
        sum=max(sum,freq['a']);
        sum=max(sum,freq['e']);
        sum=max(sum,freq['i']);
        sum=max(sum,freq['o']);
        sum=max(sum,freq['u']);
        freq.erase('a');
        freq.erase('e');
        freq.erase('i');
        freq.erase('o');
        freq.erase('u');

          auto maxElem = std::max_element(
        freq.begin(), freq.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        }
    );
    sum+=maxElem->second;
    return sum;
    }
};

// Auto-commit update
