#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;


bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> mp;
    bool seen[1000] = {};

    for(int num: arr) {
        if(!mp[num]) {
            mp[num] = 1;
        }
        else {
            mp[num]++;
        }
    }
    for(auto it: mp) {
        if(seen[it.second]) return false;
        seen[it.second] = true;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> arr = {1,2};
    cout << uniqueOccurrences(arr);
    return 0;
}