#include <iostream>
#include <map>
#include <unordered_map>
#include <list>
#include <chrono>

using namespace std;
using namespace std::chrono;

void testMap() {
    map<string, list<string>> g;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        string u = "Node_" + to_string(i);
        string v = "Node_" + to_string(i + 1);
        g[u].push_back(v);
    }
    auto end = high_resolution_clock::now();

    cout << "std::map Insertion Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    cout << "Traversal Order:\n";
    int count = 0;
    for (auto& node : g) {
        cout << node.first << " -> " << node.second.front() << endl;
        if (++count >= 5) break;
    }
}

void testUnorderedMap() {
    unordered_map<string, list<string>> g;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        string u = "Node_" + to_string(i);
        string v = "Node_" + to_string(i + 1);
        g[u].push_back(v);
    }
    auto end = high_resolution_clock::now();

    cout << "std::unordered_map Insertion Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    cout << "Traversal Order:\n";
    int count = 0;
    for (auto& node : g) {
        cout << node.first << " -> " << node.second.front() << endl;
        if (++count >= 5) break;
    }
}

int main() {
    testMap();
    cout << "----------------------------------\n";
    testUnorderedMap();
    return 0;
}
