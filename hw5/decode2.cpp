#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;
struct node
{
    string name;
    vector<node *> childrens;
    node(node &t) : name(t.name), childrens(t.childrens) {};
    node(string t) : name(t), childrens() {};
};
struct tobedecode
{
    int binstart;
    int binover;
    int offsetofnode;
    tobedecode(int start, int over, int offset) : binstart(start), binover(over), offsetofnode(offset) {};
};
void printNames(node *root)
{
    if (!root)
        return;
    cout << root->name << endl;
    for (auto child : root->childrens)
    {
        printNames(child);
    }
}
void encodeDFS(node *node, string &result)
{
    if (!node)
        return;
    result.push_back('1');
    for (auto child : node->childrens)
    {
        encodeDFS(child, result);
    }
    result.push_back('0');
}
void decodepro(string &recusepassword, vector<string> &nodelot, int start)
{
    string rootnode = nodelot[start];
    cout << rootnode << ':' << ' ';
    vector<tobedecode> Tobe;
    int pos = 1, defaultoffset = start+1;
    while (pos < recusepassword.length() - 1)
    {
        int level = 0, offsetadd = 0;
        int i = pos;
        for (; i <= recusepassword.length() - 1; i++)
        {
            if (recusepassword.at(i) == '1')
            {
                level++;
                if (level == 1)
                {
                    cout << nodelot[defaultoffset] << ' ';
                }
                offsetadd++;
            }
            else
            {
                level--;
            }
            if (level == 0)
            {
                Tobe.push_back(tobedecode{pos, i, defaultoffset});
                break;
            }
        }
        pos = i + 1;
        defaultoffset += offsetadd;
    }
    cout << endl;
    for (auto j : Tobe)
    {
        if (j.binover - j.binstart > 2)
        {
            string newpassword = recusepassword.substr(j.binstart, j.binover - j.binstart + 1);
            decodepro(newpassword, nodelot, j.offsetofnode);
        }
    }
}
int main()
{
    string t, root;

    cin >> t;
    if (t == "ENCODE")
    {
        unordered_map<string, node *> nodeMap;
        cin >> root;
        node Ceo{root.substr(0, root.length() - 1)};
        node *nownode = &Ceo;
        while (cin >> t)
        {
            if (t.at(t.length() - 1) == ':')
            {
                nownode = nodeMap[t.substr(0, t.length() - 1)];
                continue;
            }
            node *newnode = new node(t);
            nownode->childrens.push_back(newnode);
            nodeMap[t] = newnode;
        }
        printNames(&Ceo);
        string ans;
        encodeDFS(&Ceo, ans);
        cout << ans;
    }
    else if (t == "DECODE")
    {
        vector<string> names;
        string name;
        while (cin >> name)
        {
            names.push_back(name);
        }
        string encoded = names.back();
        names.pop_back();
        decodepro(encoded, names, 0);
    }
}