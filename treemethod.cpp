using namespace std;
#include<iostream>
#include<queue>
class node {
public:
	int data;
	node* left;
	node* right;

	node(int d) {
		data = d;
	}
};
node* createtree(node* root) {
	int data;
	cout << "Enter tha data" << endl;
	cin >> data;
	root = new node(data);
	if (data == -1) {
		return NULL;
	}
	cout << "Enter the data for inserting at left" << data << endl;
	root->left = createtree(root->left);
	cout << "Enter the data for inserting at right" << data << endl;
	root->right = createtree(root->right);
	return root;
}
void levelordertraversal(node* root) {
	queue<node*> qu;
	qu.push(root);
	qu.push(NULL);
	while (!qu.empty()) {
		node* temp = qu.front();
		qu.pop();

		if (temp == NULL) {
			cout << endl;
			if (!qu.empty()) {
				qu.push(NULL);
			}
		}

		else {
			cout << temp->data << " ";
			if (temp->left) {
				qu.push(temp->left);
			}
			if (temp->right) {
				qu.push(temp->right);
			}
		}
	}
}
void inorder(node* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data;
	inorder(root->right);

}

void preorder(node* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data;
	preorder(root->left);
	preorder(root->right);
}
void postorder(node* root) {
	if (root == NULL) {
		return;
	}
	 postorder(root->left);
	 postorder(root->right);
	 cout << root->data;
}
//void findmin(node* root) {
//	if (root == NULL) {
//		return;
//	}
//	while (root->left) {
//		root = root->left;
//	}
//
//	cout << "min value is " << root->data << endl;
//}
//void findmax(node* root) {
//	if (root == NULL) {
//		return;
//	}
//	while (root->right) {
//		root = root->right;
//	}
//
//	cout << "max value is " << root->data << endl;
//}
int main() {
	node* root = NULL;
	root = createtree(root);
	findmin(root);
	findmax(root);
	cout << "level order: " << endl;
	levelordertraversal(root);
	cout << " inorder traversal:" << endl;
	inorder(root);
	cout << " preorder traversal: " << endl;
	preorder(root);
	cout << " postorder traversal: " << endl;
	postorder(root);
}
