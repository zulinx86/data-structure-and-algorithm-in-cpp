#include <iostream>
#include <random>

using namespace std;

struct node {
	int value;
	node *next;
};

class list {
public:
	list() {
		head = new node;
		head->value = -1;
		head->next = NULL;
	}

	~list() {
		node *curr = head, *next;
		while (curr) {
			next = curr->next;
			delete curr;
			curr = next;
		}
	}

	void insert(node *n, int value) {
		node *nn = new node;
		nn->value = value;
		nn->next = n->next;
		n->next = nn;
	}

	void insert_head(int value) {
		insert(head, value);
	}

	void erase(node *n) {
		for (node *p = head; p->next != NULL; p = p->next) {
			if (p->next == n) {
				p->next = n->next;
				delete n;
				return;
			}
		}
	}

	void erase_head() {
		erase(head->next);
	}

	node *search(int value) {
		for (node *n = head->next; n != NULL; n = n->next) {
			if (n->value == value)
				return n;
		}
		return NULL;
	}

	void show() {
		for (node *n = head->next; n != NULL; n = n->next)
			cout << n->value << " -> ";
		cout << endl;
	}

private:
	node *head;
};

int main() {
	int n;
	cin >> n;

	list l;
	random_device rnd;
	for (int i = 0; i < n / 10; ++i) {
		int value = rnd() % (n / 10);
		l.insert_head(value);
	}

	for (int i = 0; i < n; ++i) {
		int act = rnd() % 3;
		int value = rnd() % (n / 10);

		if (act == 0) {
			cout << "insert " << value << endl;
			l.insert_head(value);
		} else if (act == 1) {
			cout << "erase " << value << endl;
			node *n = l.search(value);
			if (n) l.erase(n);
		} else if (act == 2) {
			cout << "search " << value;
			node *n = l.search(value);
			if (n) cout << " (found)" << endl;
			else cout << " (not found)" << endl;
		}

		l.show();
	}

	return 0;
}