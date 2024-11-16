template <typename T>
class BST {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };
    Node* root;

public:
    // Default constructor
    BST() : root(nullptr) {}

    // Copy constructor (deep copy)
    BST(const BST& obj) {
        root = deepCopy(obj.root);
    }

    // Helper function for deep copy
    Node* deepCopy(Node* node) 
    {
        if (node == nullptr) return nullptr;
        Node* new_node = new Node(node->data);
        new_node->left = deepCopy(node->left);
        new_node->right = deepCopy(node->right);
        return new_node;
    }

    // Function to insert a value iteratively
    void insert(T n) {
        Node* new_node = new Node(n);
        if (root == nullptr) {
            root = new_node;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;
        while (current) {
            parent = current;
            if (n < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        if (n < parent->data) {
            parent->left = new_node;
        }
        else {
            parent->right = new_node;
        }
    }

    // Function to find a value
    bool find(T value) {
        return findRecursive(root, value);
    }

    // Recursive helper function to find a value
    bool findRecursive(Node* node, T value) {
        if (node == nullptr) return false;
        if (node->data == value) return true;
        if (value < node->data) return findRecursive(node->left, value);
        return findRecursive(node->right, value);
    }

    // Function to delete a node iteratively
    bool deleteIterative(T val) {
        Node* current = root;
        Node* parent = nullptr;
        while (current) {
            if (current->data == val) {
                return deleteNode(current, parent);
            }
            parent = current;
            if (val < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }

    // Helper function to delete a node
    bool deleteNode(Node* node, Node* parent) 
    {
        if (node->left == nullptr && node->right == nullptr) {
            if (parent == nullptr) {
                root = nullptr;
            }
            else if (parent->left == node) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
            delete node;
        }
        else if (node->left == nullptr) {
            if (parent == nullptr) {
                root = node->right;
            }
            else if (parent->left == node) {
                parent->left = node->right;
            }
            else {
                parent->right = node->right;
            }
            delete node;
        }
        else if (node->right == nullptr) {
            if (parent == nullptr) {
                root = node->left;
            }
            else if (parent->left == node) {
                parent->left = node->left;
            }
            else {
                parent->right = node->left;
            }
            delete node;
        }
        else {
            Node* successor = findSuccessor(node->right);
            node->data = successor->data;
            return deleteNode(successor, node);
        }
        return true;
    }

    // Helper function to find the inorder successor
    Node* findSuccessor(Node* node)
    {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    // Recursive function to insert a value
    void insertRecursive(T value, Node*& node) {
        if (node == nullptr) {
            node = new Node(value);
        }
        else if (value < node->data) {
            insertRecursive(value, node->left);
        }
        else {
            insertRecursive(value, node->right);
        }
    }

    // Function to delete a node recursively
    bool deleteRecursive(T val) {
        return deleteRecursive(root, nullptr, val);
    }

    // Helper function to delete a node recursively
    bool deleteRecursive(Node*& node, Node* parent, T val) {
        if (node == nullptr) return false;

        if (val < node->data) {
            return deleteRecursive(node->left, node, val);
        }
        else if (val > node->data) {
            return deleteRecursive(node->right, node, val);
        }
        else {
            return deleteNode(node, parent);
        }
    }

    // Function to display the tree in increasing order
    void display() {
        displayInOrder(root);
    }

    // Helper function to display the tree in increasing order
    void displayInOrder(Node* node) {
        if (node) {
            displayInOrder(node->left);
            std::cout << node->data << " ";
            displayInOrder(node->right);
        }
    }

    // Function to calculate the total leaf nodes
    int leafSum() {
        int sum = 0;
        calculateLeafSum(root, sum);
        return sum;
    }

    // Helper function to calculate the total leaf nodes
    void calculateLeafSum(Node* node, int& sum) {
        if (node) {
            if (node->left == nullptr && node->right == nullptr) {
                sum++;
            }
            calculateLeafSum(node->left, sum);
            calculateLeafSum(node->right, sum);
        }
    }

    // Destructor to clean up the memory
    ~BST() {
        clear(root);
    }

    // Helper function to clear the tree
    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};

//#include <iostream>
//#include <queue>
//
//struct Node {
//    int data;
//    Node* left;
//    Node* right;
//    Node(int value) : data(value), left(nullptr), right(nullptr) {}
//};
//
//bool areSiblings(Node* root, int x, int y) {
//    if (root == nullptr) {
//        return false;
//    }
//
//    std::queue<Node*> q;
//    q.push(root);
//
//    while (!q.empty()) {
//        int levelSize = q.size();
//        bool xFound = false;
//        bool yFound = false;
//
//        for (int i = 0; i < levelSize; i++) {
//            Node* node = q.front();
//            q.pop();
//
//            if (node->left && node->right) {
//                if ((node->left->data == x && node->right->data == y) ||
//                    (node->left->data == y && node->right->data == x)) {
//                    return false;
//                }
//            }
//
//            if (node->data == x) {
//                xFound = true;
//            }
//            else if (node->data == y) {
//                yFound = true;
//            }
//
//            if (node->left) {
//                q.push(node->left);
//            }
//            if (node->right) {
//                q.push(node->right);
//            }
//        }
//
//        if (xFound && yFound) {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//int main() {
//    Node* root = new Node(1);
//    root->left = new Node(2);
//    root->right = new Node(3);
//    root->left->left = new Node(4);
//    root->left->right = new Node(5);
//    root->right->left = new Node(6);
//    root->right->right = new Node(7);
//
//    int x = 4;
//    int y = 5;
//
//    if (areSiblings(root, x, y)) {
//        std::cout << x << " and " << y << " are siblings." << std::endl;
//    }
//    else {
//        std::cout << x << " and " << y << " are not siblings." << std::endl;
//    }
//
//    delete root; // Don't forget to free the memory.
//
//    return 0;
//}


