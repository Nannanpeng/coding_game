#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int change(string s) {
  if (s.size() == 3)
      return 10;
  else {
    s.pop_back();
    static string letters[] = {"J", "Q", "K", "A"};
    auto iter = find(letters, letters + 4, s);
    if (iter == letters + 4)
        return stoi(s);
    else
        return int(distance(letters, iter)) + 11;
  }
}

int battle(vector<int>& l1, vector<int>& l2) {
  if (l1[0] != l2[0]) {
     if (l1[0] > l2[0]) {
       l1.push_back(l1[0]);
       l1.push_back(l2[0]);
       l1.erase(l1.begin());
       l2.erase(l2.begin());
     } else {
       l2.push_back(l1[0]);
       l2.push_back(l2[0]);
       l2.erase(l2.begin());
       l1.erase(l1.begin());
     }
    return 1;
  } else
    return 0;
}

int war(vector<int>& l1, vector<int>& l2) {
  int min_size = min(l1.size(), l2.size());
  int index = 4;
  int m = 1;
  do {
      if (l1[index] > l2[index]) {
        rotate(l1.begin(), l1.begin() + index + 1, l1.end());
        l1.insert(l1.end(), l2.begin(), l2.begin() + index + 1);
//        l1.erase(l1.begin(), l1.begin() + index + 1);
        l2.erase(l2.begin(), l2.begin() + index + 1);
        return 1;
      } else if (l1[index] < l2[index]) {
          l2.insert(l2.end(), l1.begin(), l1.begin() + index + 1);
          rotate(l2.begin(), l2.begin() + index + 1, l2.end());
          l1.erase(l1.begin(), l1.begin() + index + 1);
//          l2.erase(l2.begin(), l2.begin() + index + 1);
          return 1;
       } else {
         ++m;
         if (int(l1.size()) >= m*index && int(l2.size()) >= m*index)
             index += 4;
         else {
             cout << "PAT" << endl;
             return 0;
          }
        }
  } while(index < min_size);
  return 1;
}

int main() {
    int n; // the number of cards for player 1
    cin >> n; cin.ignore();
    vector<int> p1, p2;
    for (int i = 0; i < n; i++) {
        string cardp1; // the n cards of player 1
        cin >> cardp1; cin.ignore();
        p1.push_back(change(cardp1));
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp2; // the m cards of player 2
        cin >> cardp2; cin.ignore();
        p2.push_back(change(cardp2));
    }



    int counter = 0;
    while (1) {
      if (battle(p1, p2)) {
          ++counter;
          if (p1.empty()) {
             cout << 2 << " " << counter << endl;
             break;
          } else if (p2.empty()) {
             cout << 1 << " " << counter << endl;
             break;
            }
     } else if ((int(p1.size()) < 4) | (int(p2.size()) < 4)) {
          cout << "PAT" << endl;
          break;
     } else {
       if (war(p1, p2)) {
          ++counter;
/*
          for (int i = 0; i != p1.size(); ++i)
             cout << p1[i] << " " ;
          cout << endl;
          for (int i = 0; i != p2.size(); ++i)
             cout << p2[i] << " " ;
          cout << endl;
*/
          if (p1.empty()) {
             cout << 2 << " " << counter << endl;
             break;
          } else if (p2.empty()) {
             cout << 1 << " " << counter << endl;
             break;
           }
       } else
          break;
     }
   }
}
