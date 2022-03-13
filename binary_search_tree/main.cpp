#include <iostream>

using namespace std;

class BinarySearchTree {
private:
	struct Node {
		int val;
		Node *parent, *left, *right;

		Node(int val) : val(val), parent(NULL), left(NULL), right(NULL) {}
		Node(int val, Node *parent) : val(val), parent(parent), left(NULL), right(NULL) {}
	};

	Node *root;

public:
	BinarySearchTree() : root(NULL) {}
	~BinarySearchTree() {
		__free(root);
	}

	void add(int val) {
		Node *node = root;

		if (!root) {
			root = new Node(val);
			return;
		}

		while (true) {
			if (val < node->val) {
				if (!node->left) {
					node->left = new Node(val, node);
					return;
				}

				node = node->left;
			} else { // val >= node->val
				if (!node->right) {
					node->right = new Node(val, node);
					return;
				}

				node = node->right;
			}
		}
	}

	void remove(int val) {
		Node *node = __search(val);

		if (!node)
			return;

		if (node->left && node->right) { // two children
			Node *rep = node->left;

			while (rep->right)
				rep = rep->right;

			node->val = rep->val;

			if (rep == node->left)
				node->left = rep->left;
			else
				rep->parent->right = rep->left;

			delete rep;
		} else { // only one or no child
			__remove(node);
		}
	}

	bool search(int val) {
		return __search(val) != NULL;
	}

	void show() {
		__show(root);
		cout << endl;
	}

private:
	void __free(Node *node) {
		if (!node)
			return;

		__free(node->left);
		__free(node->right);
		delete node;
	}

	void __remove(Node *node) {
		Node *parent = node->parent, *child = NULL;

		if (node->right && node->left)
			return;

		if (node->right)
			child = node->right;
		if (node->left)
			child = node->left;

		if (parent) {
			if (parent->left == node)
				parent->left = child;
			else if (parent->right == node)
				parent->right = child;
		} else {
			root = child;
		}

		delete node;
	}

	Node *__search(int val) {
		Node *node = root;

		while (node) {
			if (val == node->val)
				return node;
			else if (val < node->val)
				node = node->left;
			else // val >= node->val
				node = node->right;
		}

		return NULL;
	}

	void __show(Node *node) {
		if (!node)
			return;

		__show(node->left);
		cout << node->val << " ";
		__show(node->right);
	}
};


int main() {
	int act, val;
	BinarySearchTree bst;

	while (true) {
		cout << "select action (-1: exit, 0: show, 1: add value, 2: remove value)" << endl;
		cout << "> ";
		cin >> act;

		switch (act) {
		case -1:
			return 0;
		case 0:
			bst.show();
			break;
		case 1:
			cout << "input value" << endl;
			cout << "> ";
			cin >> val;
			bst.add(val);
			break;
		case 2:
			cout << "input value" << endl;
			cout << "> ";
			cin >> val;
			bst.remove(val);
			break;
		default:
			cout << "invalid action" << endl;
		}

		cout << endl;
	}

	return 0;
}
