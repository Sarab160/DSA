using namespace std;
#include<iostream>

class heap {
public:
	int arr[100];
	int size;

	heap() {
		size = 0;
		arr[0] = -1;
	}
	void insert(int val) {
		size = size + 1;
		int index = size;
		arr[index] = val;

		while (index > 1) {
			int parent = index / 2;
			if (arr[parent] < arr[index]) {
				swap(arr[parent], arr[index]);
				index = parent;
			}
			else {
				return;
			}
		}
	}
	void delfromheap() {
		if (size == 0) {
			cout << "Nothin to delete" << endl;
			return;
		}
		arr[1] = arr[size];
		size--;

		int i = 1;
		while (size > 1) {
			int leftindex = 2 * i;
			int rightindex = 2 * i + 1;
			if (leftindex < size && arr[1] < arr[leftindex]) {
				swap(arr[1], arr[leftindex]);
				i = leftindex;
			}
			else if (rightindex < size && arr[1] < arr[rightindex]) {
				swap(arr[1], arr[rightindex]);
				i = rightindex;
			}
			else {
				return;
			}

		};
	}
	void print() {
		for (int i = 1; i <= size; i++) {
			cout << arr[i] << " ";
		}
	}
};
class minheap {
public:
	int size;
	int arr[100];
	minheap() {
		size = 0;
		arr[0] = -1;
	};
	void insert(int val) {
		size = size + 1;
		int index = size;
		arr[index] = val;
		while (index > 1) {
			int parent = index / 2;
			if (arr[parent] > arr[index]) {
				swap(arr[parent], arr[index]);
				index = parent;
			}
			else {
				return;
			}
		}
	}
	void delfromminheap() {
		if (size == 0) {
			cout << "Nothing to delete" << endl;
			return;
		}

		arr[1] = arr[size];
		size--;  

		int i = 1;
		while (2 * i <= size) { 
			int leftIndex = 2 * i;
			int rightIndex = 2 * i + 1;

			
			int smallest = i;
			if (leftIndex <= size && arr[leftIndex] < arr[smallest]) {
				smallest = leftIndex;
			}
			if (rightIndex <= size && arr[rightIndex] < arr[smallest]) {
				smallest = rightIndex;
			}

			
			if (smallest == i) {
				break;
			}

			swap(arr[i], arr[smallest]);
			i = smallest;  
		}
	}

	void print() {
		for (int i = 1; i <= size; i++) {
			cout << arr[i] << " ";
		}
	}
	
};
int main() {
	heap data;
	data.insert(20);
	data.insert(30);
	data.insert(2);
	data.insert(78);
	data.insert(12);
	data.print();
	cout<<"after deletion"<<endl;
	data.delfromheap();

	data.print();
	cout << endl;
	cout<<endl;
	cout << "=======================" << endl;
	cout << "Min Heap " << endl;
	minheap h;
	h.insert(2);
	h.insert(8);
	h.insert(1);
	h.insert(7);
	h.insert(9);
	h.insert(0);
	h.insert(66);
	h.print();
	cout<<"after deletion"<<endl;
	h.delfromminheap();
	h.print();



}





