#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();
    int stockValue[n];
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        stockValue[i] = v;
    }
    vector<int> storemax;
    for (int i = 0; i != n; ++i) {
        auto iter = min_element(stockValue + i, stockValue + n);
        int maxm = *iter - stockValue[i];
        storemax.push_back(maxm);
    }
    auto minValue = min_element(storemax.begin(), storemax.end());
    cout << *minValue << endl;
}
