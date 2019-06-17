#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int speed;
    cin >> speed; cin.ignore();
    int lightCount;
    cin >> lightCount; cin.ignore();
    vector<int> Dis, Dur;
    for (int i = 0; i < lightCount; i++) {
        int distance;
        int duration;
        cin >> distance >> duration; cin.ignore();
        Dis.push_back(distance);
        Dur.push_back(duration);
    }
    for (vector<int>::size_type j = 0; j != Dis.size(); j++)
    {
        if (18*Dis[j]%(10*speed*Dur[j]) >=
            5 * speed * Dur[j])
          {  --speed;
             j = -1;
          }
    }
    cout << speed << endl;
}
