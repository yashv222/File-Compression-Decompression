typedef struct Tree {
    char g;
    int len;
    int dec;
    struct Tree* f;
    struct Tree* r;
} Tree;

// Function to extract Huffman codes
// from a compressed file
void ExtractCodesFromFile(int fd1)
{
    read(fd1, &t->g, sizeof(char));
    read(fd1, &t->len, sizeof(int));
    read(fd1, &t->dec, sizeof(int));
}

// Function to rebuild the Huffman tree
void ReBuildHuffmanTree(int fd1, int size)
{
    int i = 0, j, k;
    tree = (Tree*)malloc(sizeof(Tree));
    tree_temp = tree;
    tree->f = NULL;
    tree->r = NULL;
    t = (Tree*)malloc(sizeof(Tree));
    t->f = NULL;
    t->r = NULL;
    for (k = 0; k < size; k++) {
        tree_temp = tree;
        ExtractCodesFromFile(fd1);
        int bin[MAX], bin_con[MAX];
        for (i = 0; i < MAX; i++) {
            bin[i] = bin_con[i] = 0;
        }
        convertDecimalToBinary(bin, t->dec, t->len);
        for (i = 0; i < t->len; i++) {
            bin_con[i] = bin[i];
        }

        for (j = 0; j < t->len; j++) {
            if (bin_con[j] == 0) {
                if (tree_temp->f == NULL) {
                    tree_temp->f
                        = (Tree*)malloc(sizeof(Tree));
                }
                tree_temp = tree_temp->f;
            }
            else if (bin_con[j] == 1) {
                if (tree_temp->r == NULL) {
                    tree_temp->r
                        = (Tree*)malloc(sizeof(Tree));
                }
                tree_temp = tree_temp->r;
            }
        }
        tree_temp->g = t->g;
        tree_temp->len = t->len;
        tree_temp->dec = t->dec;
        tree_temp->f = NULL;
        tree_temp->r = NULL;
        tree_temp = tree;
    }
}
