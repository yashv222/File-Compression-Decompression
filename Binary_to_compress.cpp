#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cstring>

// Node structure for the Huffman Tree
struct Node {
    char character;
    int freq;
    Node *left, *right;
    
    Node(char character, int freq) : character(character), freq(freq), left(nullptr), right(nullptr) {}
};

// Structure to hold the Huffman code
struct Code {
    char k;
    int l;
    int code_arr[16];
    Code* p;
};

// Function to check if a given node is a leaf node
bool isLeaf(Node* root) {
    return !(root->left) && !(root->right);
}

// Function to convert a binary code to a decimal number
int convertBinaryToDecimal(int arr[], int n) {
    int decimal = 0;
    for (int i = 0; i < n; ++i) {
        decimal = decimal * 2 + arr[i];
    }
    return decimal;
}

// Function to print codes into file
void printCodesIntoFile(std::ofstream& outFile, Node* root, std::vector<int>& t, int top = 0) {
    if (root->left) {
        t[top] = 0;
        printCodesIntoFile(outFile, root->left, t, top + 1);
    }

    if (root->right) {
        t[top] = 1;
        printCodesIntoFile(outFile, root->right, t, top + 1);
    }

    if (isLeaf(root)) {
        auto data = std::make_unique<Code>();
        data->k = root->character;
        data->l = top;
        std::memcpy(data->code_arr, t.data(), top * sizeof(int));
        data->p = nullptr;

        outFile.put(root->character); // Write character

        outFile.write(reinterpret_cast<char*>(&data->l), sizeof(int)); // Write length of the code

        int decimal = convertBinaryToDecimal(t.data(), top);
        outFile.write(reinterpret_cast<char*>(&decimal), sizeof(int)); // Write the decimal representation

        static Code* front = nullptr;
        static Code* rear = nullptr;
        static int k = 0;

        if (k == 0) {
            front = rear = data.release();
            k++;
        } else {
            rear->p = data.release();
            rear = rear->p;
        }
    }
}

