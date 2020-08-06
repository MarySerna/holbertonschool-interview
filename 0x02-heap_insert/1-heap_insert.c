#include <stdlib.h>
#include "binary_trees.h"

int leafs(heap_t *root);
void sort(heap_t **node);
int is_perfect(const heap_t *root);
heap_t *w_parent(heap_t *root);

/**
 * sort - Funtion to sort a child and parent in the tree
 * @node: inserted node
 * Return: Nothing(void)
*/
void sort(heap_t **node)
{
	heap_t *current;
	int vaux;

	current = *node;

	while (current->parent != NULL)
	{
		if (current->parent->n < current->n)
		{
			vaux = current->parent->n;
			current->parent->n = current->n;
			current->n = vaux;
			*node = current->parent;
		}
		current = current->parent;
	}
}

/**
 * is_perfect - Function to check if a tree is perfect
 * @root: pointer to the root
 * Return: 1 for true, otherwhise 0
*/
int is_perfect(const heap_t *root)
{
	int l, r;

	if (root == NULL)
		return (0);

	l = leafs(root->left);
	r = leafs(root->right);

	if (l == r)
		return (1);

	return (0);
}

/**
 * leafs - Function that count the nodes in the binary tree
 * @root: double pointer to the root
 * Return: number of nodes
*/
int leafs(heap_t *root)
{
	int l;

	if (root == NULL)
		return (0);

	if (root)
		l = 1;

	l += leafs(root->left);
	l += leafs(root->right);

	return (l);
}

/**
 * w_parent - Function to find the parent to insert the child
 * @root: double pointer to the root
 * Return: Pointer to the parent
*/
heap_t *w_parent(heap_t *root)
{
	heap_t *parent;
	int left, right, left_leaf, right_leaf;

	if (root == NULL)
		return (NULL);

	parent = root;
	left = leafs(parent->left);
	right = leafs(parent->right);
	left_leaf = is_perfect(parent->left);
	right_leaf = is_perfect(parent->right);

	if (left < 1 || right < 1)
		return (parent);

	if (left_leaf < 1 || (left_leaf && right_leaf && left == right))
		return (w_parent(parent->left));
	else if (right_leaf < 1 || (left_leaf && right_leaf && left > right))
		return (w_parent(parent->right));

	return (parent);
}


/**
 * heap_insert - Function that inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value store in the node to be inserted
 * Return: a pointer to the new node, or NULL on failure
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t *parent;

	if (!root)
		return (NULL);

	parent = w_parent(*root);
	new = binary_tree_node(parent, value);

	if (new == NULL)
		return (NULL);

	if (parent == NULL)
		*root = new;

	else if (parent->left == NULL)
		parent->left = new;
	else
		parent->right = new;

	sort(&new);

	return (new);
}
