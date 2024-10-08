#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int Size = 0;
vector<int> train;

bool judge(int);

int main() {
    string line;
    getline(cin,line);
    istringstream iss(line);
    string number;
    while (iss>>number){
        int num = std::stoi(number);
        train.push_back(num);
        Size++;
    }
    for (int i = 0; i < Size-1; ++i) {
        if (!judge(i)){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}

bool judge(int x){
    int tok=train[x];
    for (int i = x+1; i < Size; ++i) {
        if (train[i]<train[x]){
            if (train[i]<tok){
                tok=train[i];
            } else{
                return 0;
            }
        }
    }
    return 1;
}