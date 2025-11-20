#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

template<typename K, typename V>
class MyHashMap {
private:
    static const int INITIAL_SIZE = 16;
    static const int MAXIMUM_CAPACITY = 1 << 30;

    // Node definition (similar to Entry class in Java)
    struct Entry {
        K key;
        V value;
        Entry* next;

        Entry(K k, V v) : key(k), value(v), next(nullptr) {}
    };

    vector<Entry*> hashTable;
    int capacity;

    // Utility to get next power of 2 >= cap
    int tableSizeFor(int cap) {
        int n = cap - 1;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        return (n < 0) ? 1 : (n >= MAXIMUM_CAPACITY) ? MAXIMUM_CAPACITY : n + 1;
    }

    // Hash function
    int getIndex(K key) {
        return hash<K>{}(key) % capacity;
    }

public:
    MyHashMap(int cap = INITIAL_SIZE) {
        capacity = tableSizeFor(cap);
        hashTable.resize(capacity, nullptr);
    }

    void put(K key, V value) {
        int index = getIndex(key);
        Entry* node = hashTable[index];

        if (!node) {
            hashTable[index] = new Entry(key, value);
        } else {
            Entry* prev = nullptr;
            while (node) {
                if (node->key == key) {
                    node->value = value;
                    return;
                }
                prev = node;
                node = node->next;
            }
            prev->next = new Entry(key, value);
        }
    }

    V get(K key) {
        int index = getIndex(key);
        Entry* node = hashTable[index];

        while (node) {
            if (node->key == key) {
                return node->value;
            }
            node = node->next;
        }

        // Handle non-existent keys (return default-constructed value)
        return V();
    }

    // Destructor to clean up memory
    ~MyHashMap() {
        for (Entry* head : hashTable) {
            while (head) {
                Entry* temp = head;
                head = head->next;
                delete temp;
            }
        }
    }
};
