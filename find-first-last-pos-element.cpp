#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int len = nums.size();
    int l = 0, r = len - 1;
    bool lfind = false, rfind = false;

    while((!lfind || !rfind) && l <= r) {
        lfind = nums[l] == target;
        rfind = nums[r] == target;
        if(!lfind) l++;
        if(!rfind) r--;
    }

    vector<int> res(2);
    if((!lfind) || (!rfind)) {
        res[0] = -1;
        res[1] = -1;
    } else {
        res[0] = l;
        res[1] = r;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    vector<int> nums = {1};
    int target = 1;
    vector<int> res = searchRange(nums, target);
    cout << res[0] << ' ' << res[1];
    return 0;
}