#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int candy(vector<int>& ratings) {
        int sum = 0, level, offset;

        for (int i = 0; i < ratings.size(); i++) {
            if (i == 0) {
                // if (ratings[i] > ratings[i+1]) offset = 2;
                // else offset = 1;

                level = offset = 1;
                sum += offset;
                continue;
            }
            else if (i == ratings.size()-1) {
                if (ratings[i] > ratings[i-1]) offset++;
                else offset--;

                if (offset < level) {
                    sum += (i+1);
                    offset++;
                    level = level < offset ? level : offset;
                } 
                else {
                    sum += offset;
                }

                continue;
            }
            int prev = ratings[i-1], curr = ratings[i], next = ratings[i+1];

            if (curr > prev) offset++;

            // TODOS: FIX THIS CONDT
            else if ((prev < curr || curr > next)) offset++;
            else offset--;

            if (offset < level) {
                sum += (i+1);
                offset++;
                level = level < offset ? level : offset;
            } 
            else {
                sum += offset;
            }

        }

        return sum;
    }
};

int main() {
    Solution sol{};
    vector tc1{1,3,2,2,1};

    cout << sol.candy(tc1) << endl;
}