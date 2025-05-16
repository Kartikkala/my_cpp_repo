#include <iostream>
#include <vector>
#include "queue_ca.cpp"
#include "HashMap.cpp"
#include <algorithm>

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
        Queue<A> q;
        q.enqueue(start);
        visited[start] = true;

        while (!q.empty()) {
            A current = q.front();
            q.dequeue();
            std::cout << current;

            for (auto &neighbor : g[current]) {
                if (!visited[neighbor.first]) {
                    q.enqueue(neighbor.first);
                    visited[neighbor.first] = true;
                }
            }
        }

        visited.clear();
    }

    void bfs_shortest_path(A start, A end) {
        Queue<A> q;
        HashMap<A, A> parent;
        visited[start] = true;
        q.enqueue(start);
    
        while (!q.empty()) {
            A current = q.front_value();
            q.dequeue();
    
            if (current == end) break;
    
            for (auto &neighbor : g[current]) {
                if (!visited[neighbor.first]) {
                    visited[neighbor.first] = true;
                    parent[neighbor.first] = current;
                    q.enqueue(neighbor.first);
                }
            }
        }
    
        if (!visited[end]) {
            std::cout << "No path found from " << start << " to " << end << std::endl;
        } else {
            std::vector<A> path;
            for (A at = end; at != start; at = parent[at]) {
                path.push_back(at);
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
    
            std::cout << "Shortest path from " << start << " to " << end << ": ";
            for (auto &node : path) {
                std::cout << node << " ";
            }
            std::cout << std::endl;
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
    // map
    /*

        HashMap map<char, vector<char>>;

        map[A].push(B);
        map[B].push(A);
        map[A].push(C);

    */
    // 1, [B, C]
    // B, [A]
    // C, [A]
    Graph<char> g;
    g.add_edge('A', 'B', 5);
    g.add_edge('C', 'D', 2);
    g.add_edge('B', 'C', 3);
    g.bfs_shortest_path('A', 'C');
}