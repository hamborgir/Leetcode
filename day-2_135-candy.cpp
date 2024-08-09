#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int candy(vector<int>& ratings) {
        int sum = 0, level = 1, offset;

        for (int i = 0; i < ratings.size(); i++) {
            if (i == 0) {
                if (ratings[i] > ratings[i+1]) offset = 2;
                else offset = 1;

                if (offset < level) {
                    level = level < offset ? level : offset;
                    sum += (i+1);
                } 
                else {
                    sum += offset;
                }
                continue;
            }
            else if (i == ratings.size()-1) {
                if (ratings[i] > ratings[i-1]) offset++;
                else offset--;

                if (offset < level) {
                    level = level < offset ? level : offset;
                    sum += (i+1);
                } 
                else {
                    sum += offset;
                }
                continue;
            }
            int prev = ratings[i-1], next = ratings[i+1], curr = ratings[i];

            if (prev < curr || curr > next) {
                offset++;
            } 
            else {
                offset--;
            }
            if (offset < level) {
                level = level < offset ? level : offset;
                sum += (i+1);
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
    vector tc1{1,2,2,2};

    cout << sol.candy(tc1) << endl;
}