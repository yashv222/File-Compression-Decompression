struct Node {
    char data;
    unsigned freq;
    Node *left, *right;

    Node(char data, unsigned freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

// For comparison of two heap nodes (needed in priority queue)
struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};

// Function to build Huffman Tree
Node* buildHuffmanTree(char arr[], int freq[], int unique_size) {
    Node *left, *right, *top;

    // Create a min heap & inserts all characters of data[]
    std::priority_queue<Node*, std::vector<Node*>, compare> minHeap;

    for (int i = 0; i < unique_size; ++i)
        minHeap.push(new Node(arr[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
        // Extract the two minimum freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes' frequencies.
        // Make the two extracted node as left and right children of this new node.
        // Add this node to the min heap
        // '$' is a special value for internal nodes, not used
        top = new Node('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // The remaining node is the root node and the tree is complete.
    return minHeap.top();
}
