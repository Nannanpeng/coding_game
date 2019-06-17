#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;


class Graph{
public:
  Graph(int V) { this->V = V; adj = new list<int>[V]; dis_closest_gw = new int[V]; }
  void addGates(int gate) { gates.push_back(gate); }
  void addEdge(int v, int w) { adj[v].push_back(w); adj[w].push_back(v);}
  void BFS(int S);
  void NodeDistance();
  void ToGwCount();
  void output(int SI);
  bool operator ()(int n, int m) { return dis_closest_gw[n] >= dis_closest_gw[m];}
  void DFStry(int v, bool visited[]);

private:
  int V; list<int> *adj, *adjgw; list<int> gates; int *dis_closest_gw, *connect_gw;
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
    for (list<int>::const_iterator i = adj[s].begin(); i != adj[s].end(); ++i)
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
//distance to the closet gateways
void Graph::NodeDistance() {
  list<int> queue;
  bool *visited = new bool[V];
  for (int i = 0; i != V; i++)
  {
    if (reachGate(i)) {
      dis_closest_gw[i] = 0;
      queue.push_back(i);
      visited[i] = 1;
    } else {
      dis_closest_gw[i] = 10000;
      visited[i] = 0;
    }
  }
  while(!queue.empty()) {
    int s = queue.front();
    queue.pop_front();
    for (list<int>::const_iterator i = adj[s].begin(); i != adj[s].end(); ++i)
    {
      if (!visited[*i]) {
        visited[*i] = 1;
        queue.push_back(*i);
        int idis = dis_closest_gw[s] + 1;
        if (idis < dis_closest_gw[*i])
          dis_closest_gw[*i] = idis;
      }
    }
  }
}

//count how many neighbors are gw and who they are
void Graph::ToGwCount() {
  int connect_gw[V] = {0};
  for (int i = 0; i != V; ++i) {
    for (list<int>::const_iterator j = adj[i].begin(); j != adj[i].end(); ++j) {
      if (reachGate(i))
        break;
      if ( reachGate(*j) ) {
        connect_gw[i] += 1;
        adjgw[i].push_back(*j);
      }
    }
  }
}

void Graph::output(int SI) {
  bool *visited = new bool[V];
  for (int i = 0; i != V; ++i)
    visited[i] = 0;
  list<int> queue;
  visited[SI] = 1;
  queue.push_back(SI);

  while(!queue.empty()) {
    int s = queue.front();
    queue.pop_front();
    for (list<int>::const_iterator i = adj[s].begin(); i != adj[s].end(); ++i)
    {
      if (s == SI && connect_gw[*i] == 0)
        cout << s << ' ' << *i << endl;
      else if (s == SI && connect_gw[*i] >= 2)
        cout << *i << ' ' << adjgw[*i].front();
      else
        DFStry(*i, visited);
    }
  }
}

void Graph::DFStry(int v, bool visited[])
{
  visited[v] = 1;
  list<int> queue = adj[v];
  if (queue.size() >= 2)
    queue.sort((*this));
  int s = queue.front();
  queue.pop_front();
  while (!queue.empty()) {
    if (connect_gw[s] > dis_closest_gw[s]) {
      cout << s << ' ' << adjgw[s].front() << endl;
      break;
    }
    else
      DFStry(s, visited);
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
    g.NodeDistance();
    g.ToGwCount();

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        g.output(SI);
    }
}
