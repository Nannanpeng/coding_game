#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int splitcycle(int w, int h) {
    if (w == h)
       return 1;
    else {
      int mw = 150, mh = 150;
      for (int i = 1; i != w/2; ++i)
        int mw = min(mw, splitcycle(w - i, h) + splitcycle(i, h));
      for (int i = 1; i != h/2; ++i)
        int mh = min(mh, splitcycle(w, h - i) + splitcycle(w, i));
      return min(mw, mh);
    }
}

int main()
{
    int h;
    int w;

    cin >> h >> w; cin.ignore();
    string s = h + "x" + w;
    cout << s << endl;
    cout << splitcycle(w, h) << endl;
}
