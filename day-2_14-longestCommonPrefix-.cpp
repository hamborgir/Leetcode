#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        int max = 0;
        int idx = 0, stridx;

        bool is_same = 1;
        
        while (is_same) {
            if (strs[0].empty()) break;
            if ((strs[0].length()-1) < idx) break;
            char c = strs[0][idx];


            for (int i = 1; i < strs.size(); i++) {
                if ((strs[i].length()-1) < idx) {
                    is_same = 0;
                    break;
                }

                char d = strs[i][idx];


                if (c != d) {
                    // cout <<"foo";
                    is_same = 0;
                    break;
                }

            }
            if (is_same) idx++;
        }
        return strs[0].substr(0, idx);
    }
};

int main() {
    Solution sol{};
    vector<string> tc1{"flower", "flow", "fl"};

    cout << sol.longestCommonPrefix(tc1);
}