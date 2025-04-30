#include <iostream>
#include <vector>
#include <queue>
#include "HashMap.cpp"

template <typename A>
class Graph {
private:
    HashMap<A, std::vector<std::pair<A, int>>> g;
    HashMap<A, bool> visited;

public:
    void add_edge(A from, A to, int distance) {
        g[from].push_back({to, distance});
        g[to].push_back({from, distance});
    }

    void print_graph() {
        for (auto it = g.begin(); it != g.end(); ++it) {
            std::cout << it->key << ": ";
            for (auto &neighbor : it->value) {
                std::cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            std::cout << std::endl;
        }
    }

    void bfs(A start) {
        std::queue<A> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            A current = q.front();
            q.pop();
            std::cout << current;

            for (auto &neighbor : g[current]) {
                if (!visited[neighbor.first]) {
                    q.push(neighbor.first);
                    visited[neighbor.first] = true;
                }
            }
        }

        visited.clear();
    }

    void dfs(A start) {
        if (visited[start]) return;

        std::cout << start;
        visited[start] = true;

        for (auto &neighbor : g[start]) {
            if (!visited[neighbor.first]) {
                dfs(neighbor.first);
            }
        }
    }
};


int main(void)
{
    Graph<char> g;
    g.add_edge('A', 'B', 5);
    g.add_edge('C', 'D', 2);
    g.add_edge('B', 'C', 3);
    g.dfs('A');
}