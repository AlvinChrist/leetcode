#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits>

using namespace std;

int minRes = INT32_MAX;

bool isPerfectSquare(int x) { 
    int s = sqrt(x); 
    return (s*s == x); 
} 

int dfs(vector<int> &sqrt_arr, int start, int target, int acc) {
    if(start == 0) return acc + target / 1;
    if(target < 0) return -1;
    if(target == 0) {
        return acc;
    }
    for(int i = start; i >= 0; i--) {
        int nextTarget = target - sqrt_arr[i];
        if(nextTarget >= 0) {
            int res = dfs(sqrt_arr, (sqrt_arr[i] > nextTarget ? start : start-1), nextTarget, acc+1);
            if(res < minRes) {
                minRes = res;
                if(minRes == 1) return 1;
            };
        }
    }
    return minRes;
}

int numSquares(int n) {
    vector<int> sqrt_arr;
    for(int i = 1; i <= 100; i++) {
        sqrt_arr.push_back(i*i);
    }
    int mid = ceil(sqrt((double)n)) - 1;
    return dfs(sqrt_arr, mid, n, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    int num; cin >> num;
    cout << numSquares(num);
    return 0;
}