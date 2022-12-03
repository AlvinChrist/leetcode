#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

unordered_map<char, int> mp;

int firstUniqChar(string s) {
    for(char ch: s) {
        !mp[ch] ? mp[ch] = 1 : mp[ch]++;
    }

    for(int i = 0; i < s.size(); i++) {
        if(mp[s[i]] == 1) {
            // cout << ch << '\n';
            return i;
        }
    }
    // for(auto it: mp) {
    //     cout << it.first << ' ' << it.second.first << ' ' << it.second.second << '\n';
    // }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    cout << firstUniqChar(s);
    return 0;
}