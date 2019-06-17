#include <iostream>
#include <list>
#include <algorithm>
using namespace::std;

class Test {
//friend bool comp(int n, int m);
public:
  Test(int N) {this->N = N; dis_closest_gw = new int[N]; }
  void addvalue(int n, int m) { dis_closest_gw[n] = m; }
  bool operator ()(int n, int m) { return dis_closest_gw[n] > dis_closest_gw[m];}
  void sorted(list<int> lint) {
     lint.sort();
  }
  int getvalue(int n) { return dis_closest_gw[n];}
private:
  int N; int *dis_closest_gw;
};




int main() {
  string s = "Ql";
  cout << change(s) << endl;
//  cout << change(s) << endl;
}
