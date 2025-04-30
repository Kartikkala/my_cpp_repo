#include <iostream>

template <typename Key, typename Value>
struct HashNode {
    Key key;
    Value value;
    HashNode* next;

    HashNode(Key k, Value v) : key(k), value(v), next(nullptr) {}
};

template <typename Key, typename Value>
class HashMap {
private:
    static const int TABLE_SIZE = 100;
    HashNode<Key, Value>* table[TABLE_SIZE];

    int hash(Key key) {
        if constexpr (std::is_same<Key, int>::value) {
            return key % TABLE_SIZE;
        } else if constexpr (std::is_same<Key, char>::value) {
            return (key - 'A') % TABLE_SIZE;
        } else {
            static_assert(sizeof(Key) == 0, "Unsupported key type");
        }
    }

public:
    HashMap() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

    void push(Key key, Value value) {
        int index = hash(key);
        HashNode<Key, Value>* head = table[index];

        while (head) {
            if (head->key == key && head->value == value) {
                return; // already exists, do nothing
            }
            head = head->next;
        }

        HashNode<Key, Value>* newNode = new HashNode<Key, Value>(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    bool has(Key key, Value value) {
        int index = hash(key);
        HashNode<Key, Value>* head = table[index];

        while (head) {
            if (head->key == key && head->value == value)
                return true;
            head = head->next;
        }
        return false;
    }

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            HashNode<Key, Value>* head = table[i];
            while (head) {
                HashNode<Key, Value>* temp = head;
                head = head->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashMap<char, int> map;

    map.push('A', 10);
    map.push('A', 20);
    map.push('B', 30);

    std::cout << map.has('A', 10) << std::endl; // 1 (true)
    std::cout << map.has('A', 15) << std::endl; // 0 (false)
    std::cout << map.has('B', 30) << std::endl; // 1
    std::cout << map.has('C', 40) << std::endl; // 0

    return 0;
}
