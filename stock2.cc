#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cassert>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();
    int values[n];
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        values[i] = v;
    }

    int loss = 0;
    int maxSeen = values[0];
    int minSeen = values[0];
    vector<int> store;
    store.push_back(0);
    for (int i = 1; i < n; ++i)
    {
        if (values[i] > maxSeen)
            maxSeen = values[i];
        else if (values[i] < maxSeen)
        {
            minSeen = values[i];
            loss = minSeen - maxSeen;
            store.push_back(loss);
        }
    }
    auto minValue = min_element(store.begin(), store.end());
    cout << *minValue << endl;
}
