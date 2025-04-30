#include <iostream>
#include <vector>
#include "queue_ca.cpp"
#include "HashMap.cpp"
#include <algorithm>

template <typename A>
class Graph {
private:
    HashMap<A, std::vector<A>> g;
    HashMap<A, bool> visited;
    int maxDepth = -1;
    A deepestNode;

    void dfs_deepest(A node, int depth) {
        visited[node] = true;

        if (depth > maxDepth) {
            maxDepth = depth;
            deepestNode = node;
        }

        for (auto &neighbor : g[node]) {
            if (!visited[neighbor]) {
                dfs_deepest(neighbor, depth + 1);
            }
        }
    }

public:
    void add_edge(A from, A to) {
        g[from].push_back(to);
        g[to].push_back(from);
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
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                    q.enqueue(neighbor);
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

    void dfs_from(A start) {
        maxDepth = -1;
        visited.clear();
        dfs_deepest(start, 0);
        std::cout << "Deepest node from " << start << " is " << deepestNode
                  << " at depth " << maxDepth << std::endl;
    }
};


int main(void)
{
    Graph<char> g;
    g.add_edge('A', 'B');
    g.add_edge('A', 'C');
    g.add_edge('B', 'D');
    g.add_edge('B', 'E');
    g.add_edge('D', 'F');
    g.add_edge('E', 'F');
    g.bfs_shortest_path('A', 'F');
    g.dfs_from('A');
}