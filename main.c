#include <stdio.h>
#include "AVL/avl.h"  // Include the header file for your AVL logic

int main() {
    // Assign the root
    Letter* Root = NULL;

    // Start the insertion
    Root = InsertLetter(Root, 75);  // Insert root node 'K'
    Root = InsertLetter(Root, 71);  // Insert node 'G'
    Root = InsertLetter(Root, 78);  // Insert node 'N'
    Root = InsertLetter(Root, 82);  // Insert node 'R'
    Root = InsertLetter(Root, 77);  // Insert node 'M'
    Root = InsertLetter(Root, 90);  // Insert node 'Z'
    Root = InsertLetter(Root, 67);  // Insert node 'C'
    Root = InsertLetter(Root, 65);  // Insert node 'A'
    Root = InsertLetter(Root, 68);  // Insert node 'D'
    Root = InsertLetter(Root, 69);  // Insert node 'E'
    Root = InsertLetter(Root, 85);  // Insert node 'U'
    Root = InsertLetter(Root, 88);  // Insert node 'X'
    Root = InsertLetter(Root, 81);  // Insert node 'Q'
    Root = InsertLetter(Root, 66);  // Insert node 'B'
    Root = InsertLetter(Root, 76);  // Insert node 'L'
    Root = InsertLetter(Root, 70);  // Insert node 'F'
    Root = InsertLetter(Root, 80);  // Insert node 'P'
    Root = InsertLetter(Root, 83);  // Insert node 'S'
    Root = InsertLetter(Root, 79);  // Insert node 'O'
    Root = InsertLetter(Root, 72);  // Insert node 'H'
    Root = InsertLetter(Root, 74);  // Insert node 'J'
    Root = InsertLetter(Root, 73);  // Insert node 'I'
    Root = InsertLetter(Root, 86);  // Insert node 'V'
    Root = InsertLetter(Root, 84);  // Insert node 'T'
    Root = InsertLetter(Root, 87);  // Insert node 'W'
    Root = InsertLetter(Root, 89);  // Insert node 'Y'

    // Perform an in-order traversal
    printf("In-order traversal of the AVL tree:\n");
    InOrderTraversal(Root);
    
    return 0;  // Ensure that the return statement is present
}
