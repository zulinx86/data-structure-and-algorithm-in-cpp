#include <iostream>
#include <random>

using namespace std;

struct node {
	int value;
	node *prev;
	node *next;
};

class list {
public:
	list() {
		head = new node;
		head->value = -1;
		head->prev = head;
		head->next = head;
	}

	~list() {
		node *curr = head->next, *next;
		while (curr != head) {
			next = curr->next;
			delete curr;
			curr = next;
		}
		delete head;
	}

	void insert(node *n, int value) {
		node *nn = new node;
		nn->value = value;
		nn->prev = n;
		nn->next = n->next;
		n->next->prev = nn;
		n->next = nn;
	}

	void insert_head(int value) {
		insert(head, value);
	}

	void insert_tail(int value) {
		insert(head->prev, value);
	}

	void erase(node *n) {
		n->prev->next = n->next;
		n->next->prev = n->prev;
		delete n;
	}

	void erase_head() {
		erase(head->next);
	}

	void erase_tail() {
		erase(head->prev);
	}

	node *search(int value) {
		for (node *n = head->next; n != head; n = n->next) {
			if (n->value == value)
				return n;
		}
		return NULL;
	}

	void show() {
		for (node *n = head->next; n != head; n = n->next)
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
			cout << "erase " << value;
			node *n = l.search(value);
			if (n) {
				l.erase(n);
				cout << " (found)" << endl;
			} else cout << " (not found)" << endl;
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