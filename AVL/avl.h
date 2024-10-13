#ifndef AVL_H
#define AVL_H

#include <stdio.h>   // For printf
#include <stdlib.h>  // For malloc, free
#include <stdbool.h> // For bool type

// Declare the Letter structure (node for the AVL tree)
typedef struct Letter
{
    char Character;
    struct Letter *Left;
    struct Letter *Right;
    int Height;
    int Balance;
} Letter;

// Function prototypes
Letter* NewLetter(char character);  // Create a new node
Letter* InsertLetter(Letter *root, int key);  // Insert a node into the tree
void InOrderTraversal(Letter *root);
int GetHeight(Letter *node);  // Get the height of a node
bool IsUpperCase(int key);  // Check if a key is an uppercase letter

#endif // AVL_H
