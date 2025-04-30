#include <iostream>
#include <vector>

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

    void push_back(Key key, Value value) {
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

    void clear() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            HashNode<Key, Value>* head = table[i];
            while (head) {
                HashNode<Key, Value>* temp = head;
                head = head->next;
                delete temp;
            }
            table[i] = nullptr;
        }
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

    Value& operator[](Key key) {
        int index = hash(key);
        HashNode<Key, Value>* head = table[index];
    
        while (head) {
            if (head->key == key)
                return head->value;
            head = head->next;
        }

        HashNode<Key, Value>* newNode = new HashNode<Key, Value>(key, Value());
        newNode->next = table[index];
        table[index] = newNode;
        return newNode->value;
    }

    
    Value &get(Key key) {
        int index = hash(key);
        HashNode<Key, Value>* head = table[index];

        while (head) {
            if (head->key == key) return head->value;
            head = head->next;
        }

        throw std::runtime_error("Key not found");
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

// int main() {
//     HashMap<char, std::vector<char>> map;

//     map.push('A', std::vector<char>({'A', 'B'}));
//     map.push('A', std::vector<char>({'C', 'D'}));
//     map.push('B', std::vector<char>({'E', 'F'}));

//     std::vector<char> array = map.get('B');
//     for(char a: array)
//     {
//         std::cout << a << std::endl;
//     }

//     return 0;
// }
