#include <iostream>
#include <random>
#include <chrono>

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

	void insert_tail(int value) {
		insert(head->prev, value);
	}

	void insert_head(int value) {
		insert(head, value);
	}

	void insert(node *n, int value) {
		node *nn = new node;
		nn->value = value;
		nn->prev = n;
		nn->next = n->next;
		n->next->prev = nn;
		n->next = nn;
	}

	void erase(node *n) {
		n->prev->next = n->next;
		n->next->prev = n->prev;
		delete n;
	}

	node *search(int value) {
		for (node *n = head->next; n != head; n = n->next) {
			if (n->value == value) {
				n->prev->next = n->next;
				n->next->prev = n->prev;

				n->next = head->next;
				n->prev = head;
				head->next->prev = n;
				head->next = n;

				return n;
			}
		}
		return NULL;
	}

private:
	node *head;
};

int main() {
	int n;
	cin >> n;

	list l;

	random_device rnd;
	for (int i = 0; i < n; ++i)
		l.insert_tail(rnd() % (10 * n));

	auto start = chrono::system_clock::now();
	for (int i = 0; i < n; ++i) {
		int query = rnd() % (10 * n);
		node *n = l.search(query);
	}
	auto end = chrono::system_clock::now();

	cout << "time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " [ms]" << endl;
	return 0;
}