# Chapter 10 Notes

# Notes:
- A binary search tree (BST) is a variant of binary trees where nodes are arranged in an order
    - All nodes in the left sub-tree have a value less than the root node
    - All nodes in the right sub-tree have a value either equal to or greater than the root node
    - The same rule applies to every sub-tree in the tree
    - May or may not contain duplicate values depending on implementation
    - Searching time is greatly reduced because you don't have to traverse the entire tree
    - Average running time of search is O(log n) because at every step you eliminate half of the sub-tree
    - Worst case is O(n) when the tree is a linear chain (skewed tree)

- Properties:
    - Left sub-tree of node N contains values less than N's value
    - Right sub-tree of node N contains values greater than N's value
    - Both left and right sub-trees are also binary search trees

- Binary search trees are efficient compared to sorted arrays and linked lists:
    - Sorted arrays: search is O(log n) but insertions and deletions are expensive
    - Linked lists: insertions and deletions are easy but search is O(n)
    - BST: search, insert, and delete are all O(log n) on average

- Operations on Binary Search Trees:

    - Searching for a Node:
        - Begins at the root node
        - First check if the tree is empty → value not found
        - If not empty, check if current node's value equals search value
        - If search value is less than current node's value, recursively search left sub-tree
        - If search value is greater than current node's value, recursively search right sub-tree
        - Terminates when value is found or when reaching a NULL pointer

    - Inserting a New Node:
        - First find the correct position where insertion should be done
        - New node should not violate BST properties
        - Similar to search function until reaching a NULL position
        - If current node is NULL, add the new node there
        - If new node's value is greater than current node's value, traverse right sub-tree
        - If new node's value is less than current node's value, traverse left sub-tree
        - Continues moving down until reaching a leaf node
        - Takes O(log n) time on average, O(n) in worst case

    - Deleting a Node (Three Cases):
        - Case 1: Deleting a node with no children (leaf node)
            - Simply remove the node
            - Simplest case of deletion

        - Case 2: Deleting a node with one child
            - Replace the node with its child
            - If node is left child of its parent, node's child becomes left child of parent
            - If node is right child of its parent, node's child becomes right child of parent

        - Case 3: Deleting a node with two children
            - Replace node's value with its in-order predecessor (largest value in left sub-tree)
            - OR replace with its in-order successor (smallest value in right sub-tree)
            - Then delete the in-order predecessor or successor using case 1 or 2
            - Takes O(log n) time on average, Ω(n) in worst case

- Determining Height of a BST:
    - Calculate height of left sub-tree and right sub-tree
    - Whichever height is greater, add 1 to it
    - If tree is empty, height = 0
    - Recursively calculate for each node

- Determining Number of Nodes:
    - Similar to determining height
    - Total nodes = totalNodes(left sub-tree) + totalNodes(right sub-tree) + 1
    - If tree is empty, return 0

- Determining Number of Internal Nodes (non-leaf nodes):
    - Internal nodes = totalInternalNodes(left sub-tree) + totalInternalNodes(right sub-tree) + 1
    - If node has no children (leaf), return 0
    - If tree is empty, return 0

- Determining Number of External Nodes (leaf nodes):
    - External nodes = externalNodes(left sub-tree) + externalNodes(right sub-tree)
    - If tree is empty, external nodes = 0
    - If there is only one node, external nodes = 1

- Finding Mirror Image of a BST:
    - Obtained by interchanging the left and right sub-trees at every node
    - Recursively swap left and right pointers

- Deleting an Entire BST:
    - First delete nodes in left sub-tree
    - Then delete nodes in right sub-tree
    - Finally delete the root node
    - Uses post-order traversal (left → right → root)

- Finding the Smallest Node:
    - Smallest value is in the leftmost node of the left sub-tree
    - Traverse from root to leaf node following left pointers
    - If left sub-tree is NULL, the root node is the smallest
    - Recursive algorithm: if tree is NULL or tree→left is NULL, return tree, else recurse on left

- Finding the Largest Node:
    - Largest value is in the rightmost node of the right sub-tree
    - Traverse from root to leaf node following right pointers
    - If right sub-tree is NULL, the root node is the largest
    - Recursive algorithm: if tree is NULL or tree→right is NULL, return tree, else recurse on right

- Structure Definition:
    ```c
    struct node {
        int data;
        struct node *left;
        struct node *right;
    };
    struct node *tree;
    ```