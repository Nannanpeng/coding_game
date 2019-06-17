#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;


class Graph{
public:
  Graph(int V) { this->V = V; adj = new list<int>[V];}
  void addGates(int gate) { gates.push_back(gate); }
  void addEdge(int v, int w) { adj[v].push_back(w); adj[w].push_back(v);}
  void BFS(int S);

private:
  int V; list<int> *adj; list<int> gates;
  bool reachGate(int pos) { return gates.end() != find(gates.begin(), gates.end(), pos); }
};

void Graph::BFS(int s) {
  bool *visited = new bool[V];
  for (int i = 0; i != V; i++) {
    visited[i] = 0;
  }
  list<int> queue;
  visited[s] = 1;
  queue.push_back(s);

  while(!queue.empty()) {
    s = queue.front();
    queue.pop_front();

    for (list<int>::const_iterator i = adj[s].begin(); i != adj[s].end(); i++)
    {
      if (!visited[*i]) {
        if (reachGate(*i))
        {
          cout << s << " " << *i << endl;
          queue.clear();
          adj[s].remove(*i);
          adj[*i].remove(s);
          break;
        }
        visited[*i] = 1;
        queue.push_back(*i);
      }
    }
  }
}


int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    Graph g(N);

    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        g.addEdge(N1, N2);
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        g.addGates(EI);
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        g.BFS(SI);
    }
}
