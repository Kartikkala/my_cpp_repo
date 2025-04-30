#include <iostream>
#include <vector>
#include <type_traits>
#include "tree.cpp"


template <typename Key, typename Value>
struct HashNode{
    Key key;
    Value value;
};

template <typename Key, typename Value>
class HashMap {
private:
    std::vector<HashNode<Key, BinarySearchTree<Value>*>*> hashTable;
    const float loadFactorThreshold = 0.7;
    
    long hash(Key key) {
        if constexpr (std::is_same<Key, int>::value) {
            return key % this->hashTable.size();
        } else if constexpr (std::is_same<Key, char>::value) {
            return (key - 'A') % this->hashTable.size();
        } else {
            throw std::runtime_error("Invalid type");
        }
    }

public:
    HashMap() {
        
        this->hashTable.resize(100, nullptr);
    }
    
    ~HashMap() {
        
        for (auto node : hashTable) {
            if (node != nullptr) {
                delete node->value; 
                delete node;
            }
        }
    }

    void push(Key key, Value value) {
        int index = hash(key);
        if (hashTable[index] == nullptr) {
            hashTable[index] = new HashNode<Key, BinarySearchTree<Value>*>();
            hashTable[index]->key = key;
            hashTable[index]->value = new BinarySearchTree<Value>();
        }
        
        hashTable[index]->value->insert(value);
    }

    bool has(Key key, Value value) {
        int index = hash(key);
        if (hashTable[index] == nullptr) {
            return false;
        }
        return hashTable[index]->value->has(value);
    }
};

int main(void)
{
    HashMap<char, int> h;
    h.push('A', 2);
    h.push('A', 3);
    h.push('A', 5);
    h.push('A', 6);
    h.push('A', 8);
    std::cout << h.has('A', 0);
}