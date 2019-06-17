#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n = -10; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    if (n == -10){
        cout << 0 << endl;
        return 0;
    }
    int result = 100000;
    for (int i = 0; i < n; i++) {
        int t = -10000; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        if (t == -10000){
            cout << 0 << endl;
            return 0;
        }
        int inter = result;
        result = min(abs(inter), abs(t));
        if (abs(inter) == abs(t))
          result = abs(inter);
        else if (result == abs(t))
           result = t;
        else if (result == abs(inter))
           result = inter;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    cout << result << endl;
    return 0;
}
