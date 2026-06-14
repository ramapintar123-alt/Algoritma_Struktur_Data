#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node *kiri, *right;
    Node(int nilai) : data(nilai), kiri(NULL), right(NULL) {}
};

Node* insert(Node* root, int nilai) {
    if (!root) return new Node(nilai);
    if (nilai < root->data) root->kiri = insert(root->kiri, nilai);
    else root->right = insert(root->right, nilai);
    return root;
}

int hitungJarak(Node* root, int &diameter) {
    if (!root) return 0;

    int leftHeight = hitungJarak(root->kiri, diameter);
    int rightHeight = hitungJarak(root->right, diameter);

    diameter = max(diameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    int N;
    if (!(cin >> N)) return 0;

    Node* root = NULL;
    for (int i = 0; i < N; ++i) {
        int nilai;
        cin >> nilai;
        root = insert(root, nilai);
    }

    int diameter = 0;
    hitungJarak(root, diameter);

    cout << diameter << endl;

    return 0;
}