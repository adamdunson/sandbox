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

int main() {
	struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
	tree->root = NULL;

	return EXIT_SUCCESS;
}

struct Node *newNode(int value) {
	
}

/**
 * Insert a Node into a tree.
 *
 * @param	tree	pointer to a struct Tree
 * @param	new_node	pointer to the struct Node to be inserted
 */
int insert(struct Tree *tree, struct Node *new_node) {
	// tree has no root
	if(!tree->root)
		tree->root = new_node;
	else {
		struct Node *current_node = tree->root;
		while(current_node) {
			// there is already another node with the same value
			if(new_node->value == current_node->value)
				return 0;

			// use left child/subtree
			if(new_node->value < current_node->value)
				if(current_node->left)
					current_node = current_node->left;
				else
					current_node->left = new_node;

			// use right child/subtree
			else if(new_node->value > current_node->value)
				if(current_node->right)
					current_node = current_node->right;
				else
					current_node->right = new_node;
		}
	}

	return 1;
}
