#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#pragma GCC optimize(3)
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    string cmd;
    cin >> cmd;
    if (cmd == "ENCODE") {
        unordered_map<string, vector<string>> mp;
        string s;
        cin >> s;
        string leader = s.substr(0, s.size() - 1);
        string head = leader;
        while (cin >> s) {
            if (s.back() == ':') {
                leader = s.substr(0, s.size() - 1);
            } else {
                mp[leader].push_back(s);
            }
        }
        string res = "";
        function<void(string s)> dfs = [&](string s) {
            cout << s << endl;
            res += "0";
            for (auto &p : mp[s]) {
                dfs(p);
            }
            res += "1";
        };
        // queue<string> q;
        // q.push(head);
        // while (!q.empty()) {
        //   string l = q.front();
        //   q.pop();
        //   cout << l << endl;
        //   for (auto &s : mp[l]) {
        //     q.push(s);
        //   }
        // }
        cout << head << endl;
        for (auto &p : mp[head]) {
            dfs(p);
        }
        cout << res << endl;
        // for (auto &p : mp) {
        //   cout << p.first << ": ";
        //   for (auto &s : p.second) {
        //     cout << s << " ";
        //   }
        //   cout << endl;
        // }
    } else {
        vector<string> staff;
        string s;
        while (cin >> s) {
            staff.push_back(s);
        }
        string res = staff.back();
        staff.pop_back();
        unordered_map<string, vector<string>> mp;
        stack<string> cur;
        cur.push(staff[0]);
        int idx = 1;
        for (int i = 0; i < res.length(); ++i) {
            // cout << cur.top() << " " << idx << " " << res[i] << endl;
            if (res[i] == '0') {
                mp[cur.top()].push_back(staff[idx]);
                cur.push(staff[idx]);
                idx++;
            } else {
                cur.pop();
            }
        }
        queue<string> q;
        q.push(staff[0]);
        while (!q.empty()) {
            string l = q.front();
            q.pop();
            if (mp.find(l) == mp.end()) {
                continue;
            }
            cout << l << ": ";
            for (auto &s : mp[l]) {
                cout << s << " ";
                q.push(s);
            }
            cout << endl;
        }
        // for (auto &p : mp) {
        //   cout << p.first << ": ";
        //   for (auto &s : p.second) {
        //     cout << s << " ";
        //   }
        //   cout << endl;
        // }
    }
}