#include<iostream>
#include <queue>
using namespace std;
class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int dat)
	{
		data = dat;
		left = nullptr;
		right = nullptr;
	}
};

class Tree
{
public:


	Node* create_Node(int val)
	{
		Node* newNode = new Node(val);
		if (newNode == nullptr)
		{
			cout << "Space not allocated" << endl;
		}
		else
		{
			newNode->data = val;
			return newNode;
		}
	}


	Node* add_Node(Node* key, int val)
	{
		if (key == nullptr)
		{
			return create_Node(val);
		}

		if (val < key->data)
		{
			key->left = add_Node(key->left, val);
		}
		else if (val > key->data)
		{
			key->right = add_Node(key->right, val);
		}


		return key;
	}

	void Infix(Node* key)
	{
		if (key == nullptr)
			return;
		Infix(key->left);
		cout << key->data << "\t";
		Infix(key->right);
	}

	void Prefix(Node* key)
	{
		if (key == nullptr)
			return;
		cout << key->data << "\t";
		Prefix(key->left);
		Prefix(key->right);
	}

	void Postfix(Node* key)
	{
		if (key == nullptr)
			return;
		Postfix(key->left);
		Postfix(key->right);
		cout << key->data << "\t";
	}

	bool deleteNode(Node*& key, int val)
	{
		if (key == nullptr)
		{
			return false;
		}

		bool deleted = false;

		if (key->data > val)
		{
			deleted = deleteNode(key->left, val);
		}
		else if (key->data < val)
		{
			deleted = deleteNode(key->right, val);
		}
		else
		{
			if (key->left == nullptr && key->right == nullptr)
			{
				delete key;
				key = nullptr;
				deleted = true;
			}
			else if (key->left == nullptr)
			{
				Node* temp = key;
				key = key->right;
				delete temp;
				deleted = true;
			}
			else if (key->right == nullptr)
			{
				Node* temp = key;
				key = key->left;
				delete temp;
				deleted = true;
			}
			else
			{
				// Handle the Case 3: Node has two children
				Node* minRight = key->right;
				while (minRight->left != nullptr)
				{
					minRight = minRight->left;
				}
				key->data = minRight->data;
				deleted = deleteNode(key->right, minRight->data);
			}
		}

		return deleted;
	}

	void levelOrder(Node* key)
	{
		if (key == nullptr)
			return;

		queue<Node*> nodeQueue;
		nodeQueue.push(key);

		while (!nodeQueue.empty()) {
			Node* current = nodeQueue.front();
			nodeQueue.pop();

			// Process the current node (e.g., print its data)
			cout << current->data << "\t";

			if (current->left != nullptr)
				nodeQueue.push(current->left);

			if (current->right != nullptr)
				nodeQueue.push(current->right);
		}
	}

};

int main() {
	Tree tree;
	Node* root = nullptr;


	root = tree.add_Node(root, 50);
	tree.add_Node(root, 30);
	tree.add_Node(root, 70);
	tree.add_Node(root, 20);
	tree.add_Node(root, 40);


	cout << "Infix Traversal: ";
	tree.Infix(root);
	cout << endl;
	cout << "Prefix Traversal: ";
	tree.Prefix(root);
	cout << endl;
	cout << "Postfix Traversal: ";
	tree.Postfix(root);
	cout << endl;
	cout << "Level Order Traversal: ";
	tree.levelOrder(root);
	cout << endl;

	tree.deleteNode(root, 20);
	tree.deleteNode(root, 30);
	cout << endl;
	cout << endl;
	cout << "Infix Traversal: ";
	tree.Infix(root);
	cout << endl;

	cout << "Prefix Traversal: ";
	tree.Prefix(root);
	cout << endl;

	cout << "Postfix Traversal: ";
	tree.Postfix(root);
	cout << endl;
	cout << "Level Order Traversal: ";
	tree.levelOrder(root);
	cout << endl;
	return 0;
}
