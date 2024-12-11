using namespace std;
#include<iostream>
class stack {
public:
	int* arr;
	int size;
	int top;

	stack(int value) {
		size = value;
		arr = new int[size];
		top = -1;
	}

	void push(int value) {
		if (size - top > 0) {
			top++;
			arr[top] = value;
		}
		else {
			cout << "stack is overflow" << endl;
		}
	}

	void pop() {
		if (top >= 0) {
			top--;
		}
		else {
			cout << "stack is underflow" << endl;
		}
	}

	int peek() {
		if (top >= 0) {
			return arr[top];
		}
		else {
			cout << "stack is empty" << endl;
			return -1;
		}
	}

	bool isempty() {
		if (top == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isfull() {
		if (top == size) {
			return true;

		}
		else {
			return false;
		}
	}
	void display() {
		if (isempty()) {
			cout << "stack is empty" << endl;

		}
		else {
			for (int i = 0; i < top + 1; i++) {
				cout << arr[i] << " ";
			}
		}
	}
};

int main() {
	stack st(5);
	st.push(1);
	st.push(2);
	st.push(6);
	st.push(8);
	st.push(9);
	st.push(7);
	st.push(0);
	st.display();
	cout << endl;
	cout << "Pooping" << endl;
	st.pop();
	st.display();
	system("pause");

}
