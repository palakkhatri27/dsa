#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

int main() {
    Node* node = new Node(5);
    cout<<node->key;
    return 0;
}