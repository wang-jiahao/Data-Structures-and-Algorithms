#include <iostream>
#include <vector>
using namespace std;

int main() {
    //pair
    auto prices= make_pair(3,1.1);
    prices.first=8;
    auto [x,y]=prices;//structured binding
    //tuple
    auto values= make_tuple(1,3,5,string("hello"));
    get<2>(values)=get<1>(values);
    auto [a,b,c,d]=values;//structured binding

    return 0;
}