/**
 * bst.c
 *
 * Demonstrate usage of a Binary Search Tree ADT.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *left;
	struct Node *right;
	int value;
};

struct Tree {
	struct Node *root;
};


int searchTree(struct Tree *tree, int value);
struct Node *newNode(int value);
int insertNode(struct Tree *tree, struct Node *node);

int main() {
	struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
	tree->root = NULL;

	insertNode(tree, newNode(5));
	insertNode(tree, newNode(10));
	insertNode(tree, newNode(20));
	insertNode(tree, newNode(13));
	insertNode(tree, newNode(4));
	insertNode(tree, newNode(1));
	insertNode(tree, newNode(80));
	insertNode(tree, newNode(-5));
	insertNode(tree, newNode(19));
	insertNode(tree, newNode(15));

	int n = 0;
	while(n != -1) {
		printf("Input the number to search for: ");
		scanf("%d", &n);
		if(searchTree(tree, n)) {
			printf("Found it!\n");
		} else {
			printf("Didn't find it. :(\n");
		}
	}

	return EXIT_SUCCESS;
}

int searchTree(struct Tree *tree, int value) {
	// tree has no root
	if(!tree->root)
		return 0;
	else {
		struct Node *current = tree->root;
		while(current) {
			printf("%d\n", current->value);

			// found it
			if(value == current->value) {
				return 1;
			}

			// search left child/subtree
			if(value < current->value)
				current = current->left;
			// search right child/subtree
			else if(value > current->value)
				current = current->right;
		}
	}

	return 0;
}

/**
 * Create a new struct Node.
 *
 * @param	value	integer value to be the value of the new struct Node
 * @return	pointer to the new struct Node
 */
struct Node *newNode(int value) {
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));

	node->left = NULL;
	node->right = NULL;
	node->value = value;

	return node;
}

/**
 * Insert a Node into a tree.
 *
 * @param	tree	pointer to a struct Tree
 * @param	new_node	pointer to the struct Node to be inserted
 * @return	integer code indicating whether or not the struct Node was inserted
 */
int insertNode(struct Tree *tree, struct Node *node) {
	// tree has no root
	if(!tree->root)
		tree->root = node;
	else {
		struct Node *current = tree->root;
		while(current) {
			// there is already another node with the same value
			if(node->value == current->value)
				return 0;

			// use left child/subtree
			if(node->value < current->value)
				if(current->left)
					current = current->left;
				else
					current->left = node;

			// use right child/subtree
			else if(node->value > current->value)
				if(current->right)
					current = current->right;
				else
					current->right = node;
		}
	}

	return 1;
}
