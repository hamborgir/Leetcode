#include <iostream>

using namespace std;

class Solution {
public:

    int lengthOfLongestSubstring(string s) {

        if (s.length() == 1) return 1;
        if (s == "") return 0;

        // cout << "foo";
    
        int n_count[127] = {0};
        int max = 0, max_next = 0;

        for (int i = 0; i < s.length(); i++) {
            if (n_count[s[i]] > 0) {
                break;
                // cout << s[i] << " : " << n_count[s[i] - 'a'] << endl;
            }
            max++;
            n_count[s[i]]++;
        }
        max_next = lengthOfLongestSubstring(s.substr(1, s.length()));

        return max > max_next ? max : max_next;
    }
};


int main() {
    string s = "abcdefg";

    // cout << s.substr(0,3) << endl;
    // auto i =s.substr(3,3).cbegin();

    // cout << Solution::repSubstr("abca");

    Solution sol{};

    cout << sol.lengthOfLongestSubstring("abcabcbb  *abc");
}