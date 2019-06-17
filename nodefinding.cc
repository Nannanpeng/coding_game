#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    vector<string> store;
    for (int i = 0; i != height; i++)
    {
      string line;
      getline(cin, line);
      store.push_back(line);
    }

    for (vector<string>::size_type y = 0; y != store.size(); y++)
    {
      string firstline = store[y];
      for (int x = 0; x != width; x++)
      {
          if (firstline[x] == '0') {
            cout << x << ' ' << y;

            size_t x1 = firstline.find('0', x + 1);
            if (x1 != string::npos)
              cout << ' ' << x1 << ' ' << y;
            else
              cout << ' ' << -1 << ' ' << -1;

            int y1 = y + 1;
            while( y1 != height)
            {
               if (store[y1][x] == '0')
               {
                 cout << ' ' << x << ' ' << y1 << endl;
                 break;
               }
               ++y1;
            }
            if (y1 == height)
              cout << ' ' << -1 << ' ' << -1 << '\n';
          }
        }
    }
}
