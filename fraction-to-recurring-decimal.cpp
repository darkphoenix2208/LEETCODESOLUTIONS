// Problem  : Fraction to Recurring Decimal
// Difficulty: Medium
// Tags     : Hash Table, Math, String
// URL      : https://leetcode.com/problems/fraction-to-recurring-decimal/
// Solved on: 2026-04-09 00:10
// ──────────────────────────────────────────────────

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;
        if ((numerator < 0) ^ (denominator < 0))
            result += "-";

        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        result += to_string(num / den);
        long long remainder = num % den;

        if (remainder == 0)
            return result;

        result += ".";
        unordered_map<long long, int> remainderMap;

        while (remainder != 0) {
            if (remainderMap.count(remainder)) {
                int index = remainderMap[remainder];
                result.insert(index, "(");
                result += ")";
                break;
            }

            remainderMap[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }

        return result;
    }
};


// Auto-commit update
