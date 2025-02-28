#include <iostream>
#include <memory>
using namespace std;

class TreeNode {
public:
    string name;
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;

    TreeNode(string n) : name(n), left(nullptr), right(nullptr) {}

    TreeNode(TreeNode&& other)
        : name(move(other.name)), left(move(other.left)), right(move(other.right)) {}

    TreeNode(const TreeNode&) = delete;

    void addToRight(unique_ptr<TreeNode> node) {
        if (!right) {
            right = move(node);
        }
    }

    void addToLeft(unique_ptr<TreeNode> node) {
        if (!left) {
            left = move(node);
        }
    }

    void deleteNode(unique_ptr<TreeNode>& node) {
        if (node) {
            if (node->left) {
                deleteNode(node->left);
            }
            if (node->right) {
                deleteNode(node->right);
            }
            node = nullptr;
        }
    } 

    void preorderShow(const unique_ptr<TreeNode>& node) {
        if (node) {
            cout << node->name << " ";
            preorderShow(node->left);
            preorderShow(node->right);
        }
    }

    void inorderShow(const unique_ptr<TreeNode>& node) {
        if (node) {
            inorderShow(node->left);
            cout << node->name << " ";
            inorderShow(node->right);
        }
    }

    void postorderShow(const unique_ptr<TreeNode>& node) {
        if (node) {
            postorderShow(node->left);
            postorderShow(node->right);
            cout << node->name << " ";
        }
    }

    ~TreeNode() {

    }
};

class ComplexNode {
private:
    static int nodeCount;
public:
    string name;
    shared_ptr<ComplexNode> left, right;

    ComplexNode(string n) : name(n), left(nullptr), right(nullptr) {
        ++nodeCount;
    }

    ComplexNode(ComplexNode&& other)
        : name(move(other.name)), left(move(other.left)), right(move(other.right)) {}

    ComplexNode(const ComplexNode&) = delete;

    void addToRight(shared_ptr<ComplexNode> node) {
        if (!right) {
            right = node;
        }
    }

    void addToLeft(shared_ptr<ComplexNode> node) {
        if (!left) {
            left = node;
        }
    }

    void deleteNode(shared_ptr<ComplexNode>& node) {
        if (node) {
            if (node->left) {
                deleteNode(node->left);
            }
            if (node->right) {
                deleteNode(node->right);
            }
            node = nullptr;
        }
    } 

    static int getNodeCount() {
        return nodeCount;
    }

    void preorderShow(const shared_ptr<ComplexNode>& node) {
        if (node) {
            cout << node->name << " ";
            preorderShow(node->left);
            preorderShow(node->right);
        }
    }

    void inorderShow(const shared_ptr<ComplexNode>& node) {
        if (node) {
            inorderShow(node->left);
            cout << node->name << " ";
            inorderShow(node->right);
        }
    }

    void postorderShow(const shared_ptr<ComplexNode>& node) {
        if (node) {
            postorderShow(node->left);
            postorderShow(node->right);
            cout << node->name << " ";
        }
    }

    shared_ptr<ComplexNode> findByName(shared_ptr<ComplexNode> root, string n) {
        if (!root) return nullptr; 
        if (root->name == n) return root; 
        
        shared_ptr<ComplexNode> rightResult = findByName(root->right, n);
        if (rightResult) return rightResult;
        
        return findByName(root->left, n);
    }
    

    ~ComplexNode() {
        --nodeCount;
    }
};

int ComplexNode::nodeCount = 1;

int main() {
    //1
    // unique_ptr<TreeNode> head = make_unique<TreeNode>("1");

    // head->addToLeft(make_unique<TreeNode>("2"));
    // head->addToRight(make_unique<TreeNode>("3"));

    // head->inorderShow(head);
    // cout << endl;

    // head->deleteLeft();
    // head->deleteRight();

    // head->inorderShow(head);
    // cout << endl;

    //2,3 4
    // shared_ptr<ComplexNode> head = make_shared<ComplexNode>("1");
    // head->addToLeft(make_shared<ComplexNode>("2"));
    // head->addToRight(make_shared<ComplexNode>("3"));
    // head->right->addToRight(make_shared<ComplexNode>("4"));

    // cout << ComplexNode::getNodeCount() << endl;
    // head->deleteNode(head->right);
    // cout << ComplexNode::getNodeCount() << endl;

    // shared_ptr<ComplexNode> s = head->findByName(head, "2");
    // if (s) {
    //     cout << s->name << endl;
    // }
}
