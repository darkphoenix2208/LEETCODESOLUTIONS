// Problem  : Find Resultant Array After Removing Anagrams
// Difficulty: Easy
// Tags     : Array, Hash Table, String, Sorting
// URL      : https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
// Solved on: 2026-04-09 00:09
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string prevSorted = "";

        for (string w : words) {
            string sortedWord = w;
            sort(sortedWord.begin(), sortedWord.end());  

            if (sortedWord != prevSorted) { 
                result.push_back(w);
                prevSorted = sortedWord;
            }
        }

        return result;
    }
};

// Auto-commit update
