#include<vector>
#include<iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
	Node(int key) {
		data = key;
		left = nullptr;
		right = nullptr;
	}
};

Node* InsertNode(Node *root, int data) {
	if(root==nullptr) {
		return new Node(data);
	}
	queue<Node*> q;
	q.push(root);

	while(!q.empty()) {
		Node *curr = q.front();
		q.pop();
		Node *left = curr->left;
		Node *right = curr->right;

		if(left!=nullptr) {
			q.push(left);
		}
		else {
			curr->left = new Node(data);
			return root;
		}
		if(right!=nullptr) {
			q.push(right);
		}
		else {
			curr->right = new Node(data);
			return root;
		}
	}
}


void deleteDeepestNode(Node* root, Node* dnode){
	queue<Node*> q;
	q.push(root);
	Node* curr;

	while(!q.empty()) {
		curr = q.front();
		q.pop();

		if(curr->right!=nullptr) {
			if (curr->right == dnode) {
                curr->right = nullptr;
                delete (dnode);
                return;
            } 
			q.push(curr->right);
		}

		if(curr->left!=nullptr) {
			if (curr->left == dnode) {
                curr->left = nullptr;
                delete (dnode);
                return;
            } 
			q.push(curr->left);
		}
	}
 }

Node* DeleteNode(Node *root, int key) {
	if(root==nullptr) {
		return nullptr;
	}

	if(root->left==nullptr && root->right==nullptr) {
		if(root->data==key) {
			return nullptr;
		}
		else {
			return root;
		}
	}

	queue<Node*> q;
	q.push(root);

	Node *curr;
	Node *keyNode = nullptr;

	while(!q.empty()) {
		curr = q.front();
		q.pop();
		if(curr->data==key) {
			keyNode = curr;
		}
		if(curr->left!=nullptr) {
			q.push(curr->left);
		}
		if(curr->right!=nullptr) {
			q.push(curr->right);
		}
	} 

	if(keyNode!=nullptr) {
		int x = curr->data;

		keyNode->data = x;
		
		//need to figure this out later
		deleteDeepestNode(root, curr);
		//deletDeepest(root, curr);
	}

	return root;
}

void inOrderDFS(Node *node) {
	if(node==nullptr) {
		return;
	}
	inOrderDFS(node->left);
	cout<<node->data<<' ';
	inOrderDFS(node->right);
}

void preOrderDFS(Node *node) {
	if(node==nullptr) {
		return;
	}
	cout<<node->data<<' ';
	preOrderDFS(node->left);
	preOrderDFS(node->right);
}

void postOrderDFS(Node *node) {
	if(node==nullptr) {
		return;
	}
	inOrderDFS(node->left);
	inOrderDFS(node->right);
	cout<<node->data<<' ';
}

void BFS(Node* node) {
	if(node==nullptr) {
		return;
	}
	queue<Node*> q;
	q.push(node);

	while(!q.empty()) {
		Node *curr = q.front();
		Node *left = curr->left;
		Node *right = curr->right;

		if(left!=nullptr) {
			q.push(left);
		}
		if(right!=nullptr) {
			q.push(right);
		}

		cout<<curr->data<<' ';
		q.pop();
	}
}

int height(Node *node) {
	if(node==nullptr) {
		return 0;
	}
	return max(height(node->left),height(node->right)) +1;
}

int heightBFS(Node* node) {
	if(node==nullptr) {
		return 0;
	}
	queue<Node*> q;
	int height = 0;
	q.push(node);
	q.push(nullptr);

	while(!q.empty()) {
		Node *curr = q.front();
		q.pop();

		if(curr==nullptr) {
			height++;
			if(!q.empty()) {
				q.push(nullptr);
			}
		}
		else {
			if(curr->left!=nullptr) {
				q.push(curr->left);
			}
			if(curr->right!=nullptr) {
				q.push(curr->right);
			}
		}
	}
	return height;
}

int heightLevel(Node* node) {
	if(node==nullptr) {
		return 0;
	}
	queue<Node*> q;
	int height = 0;
	q.push(node);

	while(!q.empty()) {
		int levelSize = q.size();
		for(int i=0;i<levelSize;i++) {
			Node *curr = q.front();
			q.pop();
			if(curr->left!=nullptr) {
				q.push(curr->left);
			}
			if(curr->right!=nullptr) {
				q.push(curr->right);
			}
		}
		height++;
	}
	return height;
}

int main() {
	vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
	
	Node* root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(5);
	root->left->right = new Node(6);
	root->right->left = new Node(7);
	root->right->right = new Node(8);
	root->right->left->left = new Node(9);

	InsertNode(root,20);

	cout << "In-order DFS: ";
    inOrderDFS(root);

	cout << "\nPre-order DFS: ";
    preOrderDFS(root);
   
    cout << "\nPost-order DFS: ";
    postOrderDFS(root);

	cout << "\nBFS: ";
    BFS(root);

	cout<<"\nHeight of tree: ";
	cout<<height(root);

	cout<<"\nHeight of tree using BFS with nullptr: ";
	cout<<heightBFS(root);

	cout<<"\nHeight of tree using BFS without nullptr: ";
	cout<<heightLevel(root);

	DeleteNode(root,5);
	// Node *curr = root->right->left->left;
	// root->right->left->left = nullptr;
	// delete curr;
	// curr = nullptr;

	cout << "\nIn-order DFS: ";
    inOrderDFS(root);

	cout << "\nBFS: ";
    BFS(root);

	return 0;
}
	