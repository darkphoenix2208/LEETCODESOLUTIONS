// Problem  : Design a Food Rating System
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Design, Heap (Priority Queue), Ordered Set
// URL      : https://leetcode.com/problems/design-a-food-rating-system/
// Solved on: 2026-04-09 00:11
// ──────────────────────────────────────────────────



#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
public:
    
    unordered_map<string, string> foodToCuisine;   
    unordered_map<string, int> foodToRating;    
    unordered_map<string, set<pair<int, string>>> cuisineMap; 
    

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            string f = foods[i], c = cuisines[i];
            int r = ratings[i];
            foodToCuisine[f] = c;
            foodToRating[f] = r;
            cuisineMap[c].insert({-r, f});
        }
    }

    void changeRating(string food, int newRating) {
        string c = foodToCuisine[food];
        int oldRating = foodToRating[food];

        cuisineMap[c].erase({-oldRating, food});

        cuisineMap[c].insert({-newRating, food});
        foodToRating[food] = newRating;
    }

    string highestRated(string cuisine) {

        return cuisineMap[cuisine].begin()->second;
    }
};


// Auto-commit update
