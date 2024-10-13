#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "avl.h"

// Instantiate a new Node:
Letter *NewLetter(char character)
{
	Letter *letter = (Letter *)malloc(sizeof(Letter));
	if (letter == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}
	letter->Character = character;
	letter->Left = letter->Right = NULL;
	letter->Height = 1;  // Initial height of a new node is 1
	letter->Balance = 0;
	return letter;
}

// Check the validation of the key:
bool IsUpperCase(int key)
{
	return key >= 65 && key <= 90;  // Ensure the key is an uppercase ASCII letter
}

// Get the maximum between two Operands:
int Max(int left, int right)
{
	return (left > right) ? left : right;
}

// A method to get the height of nodes:
int GetHeight(Letter* node)
{
	if (node == NULL)
	{
		return 0;
	}
	return node->Height;
}

// rotate right when the balance is positive:
Letter* RotateRight(Letter* Node) {
	Letter*  leftChild = Node->Left;
	Letter*  Temp = leftChild->Right;
	// Apply the rotation:
	leftChild->Right = Node;
	Node->Left = Temp;
	// Adjust the height of the Nodes:
	Node->Height = 1 +  Max(GetHeight(Node->Left),GetHeight(Node->Right));
	Node->Balance = GetHeight(Node->Left) - GetHeight(Node->Right);
	leftChild->Height = 1 + Max(GetHeight(Node->Left), GetHeight(leftChild->Right));
	leftChild->Balance = GetHeight(Node->Left) - GetHeight(leftChild->Right);
	return leftChild;
}

// Rotate left when the balance is negative:
Letter* RotateLeft(Letter* Node) {
	Letter* rightChild = Node->Right;
	Letter* Temp = rightChild->Left;
	// Apply the left rotation:
	rightChild-> Left = Node;
	Node->Right = Temp;
	// Adjust the height of the Nodes:
	Node->Height = 1 +  Max(GetHeight(Node->Left), GetHeight(Node->Right));
	Node->Balance = GetHeight(Node->Left) - GetHeight(Node->Right);
	rightChild->Height = 1 + Max(GetHeight(rightChild->Left), GetHeight(rightChild->Right));
	rightChild->Balance = GetHeight(rightChild->Left)- GetHeight(rightChild->Right);
	return rightChild;
}


// Insert a new Node:
Letter* InsertLetter(Letter *root, int key)
{
	// Validate if the key is an uppercase letter
	if (!IsUpperCase(key))  // Add parentheses to call the function
	{
		printf("The input is invalid\n");  // Use lowercase "printf"
		return NULL;
	}

	// Insert logic based on the character
	if (root == NULL)
	{
		return NewLetter((char)key);  // Create a new node
	}

	if (key < (int)root->Character)
	{
		root->Left = InsertLetter(root->Left, key);
	}
	else if (key > (int)root->Character)
	{
		root->Right = InsertLetter(root->Right, key);
	}
	else
	{
		return root;  // Duplicates are not allowed
	}

	// Update the height of the current node
	root->Height = 1 + Max(GetHeight(root->Left), GetHeight(root->Right));
	root->Balance = GetHeight(root->Left) - GetHeight(root->Right);
	// Balance the unbalance:
	if(root->Balance > 1 && key < (int)root->Left->Character) {
		return RotateRight(root);
	}
	if (root->Balance < -1 && key > (int)root->Right->Character) {
		return RotateLeft(root);
	}
	if (root->Balance > 1 && key > (int)root->Left->Character) {
		root->Left = RotateLeft(root->Left);
		return RotateRight(root);
	}

	if (root->Balance < -1 && key < (int)root->Right->Character) {
		root->Right = RotateRight(root->Right);
		return RotateLeft(root);
	}
	return root;  // Return the root node after insertion
}

// In order traversal:
void InOrderTraversal(Letter *root) {
if (root != NULL) {
	InOrderTraversal(root->Left);
	printf("the key is: %d and the letter is: %c and resides at height: %d and the balance factor is %d\n", (int)root->Character, root->Character, root->Height, root->Balance);
	InOrderTraversal(root->Right);
}
}