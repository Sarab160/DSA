#include<iostream>
using namespace std;
class queue {
private:
	int* arr;
	int qfront;
	int rear;
	int size;
public:
	queue(int size) {
		this->size = size;
		arr = new int[size];
		qfront =0;
		rear =0;
	}
	void enqueue(int data) {
		if (rear == size) {
			cout << "Queue is full" << endl;
		}
		else {
			arr[rear] = data;
			rear++;
		}
	}

	int dqueue() {
		if (qfront == rear) {
			return -1;
		}
		else {
			int ans = arr[qfront];
			arr[qfront] = -1;
			qfront++;
			if (qfront == rear) {
				qfront = 0;
				rear = 0;
			}
			return ans;
		}
	}

	int getfront() {
		if (qfront == rear) {
			return -1;
		}
		else {
			return arr[qfront];
		}
	}

	bool isempty() {
		if (qfront == rear) {
			return true;
		}
		else {
			return false;
		}
	}

	void print() {
		if (isempty()) {
			cout << "empty" << endl;
		}
		else {
			for
				(int i = 0; i < size; i++) {
				cout << arr[qfront + i] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	queue q(3);
	q.enqueue(3);
	q.enqueue(5);
	q.enqueue(8);
	cout << q.getfront() << endl;
	q.print();
}