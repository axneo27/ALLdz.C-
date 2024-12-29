#include <iostream>
#include <vector>
using namespace std;

struct Car {
    int number;
    vector<string> OffenceList = {};

    Car* left;
	Car* right;
	Car(int data, vector<string> OL) : number(data), left(nullptr), right(nullptr), OffenceList(OL) {}
};
 
class BinaryTree {
	Car* root;
	Car* insertNode(Car* node, int value, vector<string> offenceList) {
		if (node == nullptr){
            for (const auto& offence : offenceList) {
                node->OffenceList.push_back(offence);
            }
			return new Car(value, offenceList);
		}
		if (value < node->number) {
			node->left = insertNode(node->left, value, offenceList);
		}
		else if (value > node->number) {
			node->right = insertNode(node->right, value, offenceList);
		}
		return node;
	}

    void showOffenceList(Car* node){
        for (auto& offence : node->OffenceList){
            cout << offence << endl;
        }
    }

    void Diapazone(int min, int max, Car* node) {
        if (node == nullptr) return;
        if (node->number > min) {
            Diapazone(min, max, node->left);
        }
        if (node->number >= min && node->number <= max) {
            cout << node->number << " ";
            showOffenceList(node);
        }
        if (node->number < max) {
            Diapazone(min, max, node->right);
        }
    }

	void preorderShow(Car* node) {
		if (node != nullptr)
		{
			cout << node->number << " ";
            showOffenceList(node);
			preorderShow(node->left);
			preorderShow(node->right);
		}
	}
 
	void inorderShow(Car* node) {
		if (node != nullptr) {
			inorderShow(node->left);
			cout << node->number << " ";
            showOffenceList(node);
			inorderShow(node->right);
		}
	}

	void postorderShow(Car* node) {
		if (node != nullptr) {
			postorderShow(node->left);
			postorderShow(node->right);
			cout << node->number << " ";
            showOffenceList(node);
		}
	}

	Car* searchNode(Car* node, int value) { // by number
		if (node == nullptr) {
			return nullptr;
		}
		if (node->number == value) {
			return node;
		}
		else if (value < node->number) {
			return searchNode(node->left, value);
		}
		else {
			return searchNode(node->right, value);
		}
	}
 
public:
	BinaryTree() : root(nullptr) {}
	void insert(int value, vector<string> offenceList) {
		root = insertNode(root, value, offenceList);
	}

	Car* search(int value) {
		return searchNode(root, value);
	};

    void addOffence(int number, string Offence){
        Car* car = searchNode(root, number);
        if (car != nullptr){
            car->OffenceList.push_back(Offence);
        }
        else {
            cout << "Not found" << endl;
        }
    }

    void ShowCarInfo(int number){
        Car* car = searchNode(root, number);
        if (car != nullptr){
            cout << car->number << endl;
            showOffenceList(car);
        }
        else {
            cout << "Not found" << endl;
        }
    }

    void showDiapazone(int minNum, int maxNum){
        Diapazone(minNum, maxNum, root);
    }
    
	void preorder() {
		preorderShow(root);
		cout << endl;
	}

	void inorder() {
		inorderShow(root);
		cout << endl;
	}

	void postorder() {
		postorderShow(root);
		cout << endl;
	}
};
 
 
int main() {
	
}
