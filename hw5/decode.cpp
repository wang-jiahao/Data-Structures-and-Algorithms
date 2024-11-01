#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int MAX_EMPLOYEES = 605;

class OrgChart {
public:
    string names[MAX_EMPLOYEES];
    string encoding;
    map<string, int> nameToID;
    vector<int> subs[MAX_EMPLOYEES], order;
    int empCount = 0, hasBoss[MAX_EMPLOYEES], boss[MAX_EMPLOYEES];

    int getID(const string& name) {
        if (nameToID.count(name)) return nameToID[name];
        return nameToID[name] = ++empCount;
    }

    void DFS(int curr) {
        order.push_back(curr);
        for (int sub : subs[curr]) {
            encoding += "1";
            DFS(sub);
            encoding += "0";
        }
    }

    void encode() {
        string line;
        while (getline(cin, line) && !line.empty()) {
            size_t colonPos = line.find(':');
            string leader = line.substr(0, colonPos);
            int leaderID = getID(leader);

            size_t start = colonPos + 2;
            size_t spacePos;
            while ((spacePos = line.find(' ', start)) != string::npos) {
                string emp = line.substr(start, spacePos - start);
                int empID = getID(emp);
                subs[leaderID].push_back(empID);
                hasBoss[empID] = 1;
                start = spacePos + 1;
            }

            string lastEmp = line.substr(start);
            if (!lastEmp.empty()) {
                int lastEmpID = getID(lastEmp);
                subs[leaderID].push_back(lastEmpID);
                hasBoss[lastEmpID] = 1;
            }
        }

        for (const auto& [name, id] : nameToID) {
            names[id] = name;
        }

        int rootID = 1;
        for (int i = 1; i <= empCount; ++i) {
            if (!hasBoss[i]) {
                rootID = i;
                break;
            }
        }

        DFS(rootID);

        for (int id : order) {
            cout << names[id] << endl;
        }
        cout << encoding << endl;
    }

    void decode() {
        string s;
        vector<string> empList;
        while (cin >> s) {
            if (s[0] == '0' || s[0] == '1') break;
            empList.push_back(s);
        }

        int currNode = 1, currID = 1;
        for (char c : s) {
            if (c == '1') {
                currNode++;
                subs[currID].push_back(currNode);
                boss[currNode] = currID;
                currID = currNode;
            } else {
                currID = boss[currID];
            }
        }

        for (int i = 1; i <= empList.size(); ++i) {
            if (!subs[i].empty()) {
                cout << empList[i - 1] << ":";
                for (int j : subs[i]) {
                    cout << " " << empList[j - 1];
                }
                cout << endl;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string command;
    getline(cin, command);
    OrgChart org;

    if (command == "ENCODE") {
        org.encode();
    } else if (command == "DECODE") {
        org.decode();
    }

    return 0;
}
