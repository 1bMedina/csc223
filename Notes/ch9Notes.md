# Chapter 9 Notes

# Notes:
- A tree is a non-linear, hierarchical data structure made of nodes connected by edges
    - It is organized in levels, unlike arrays and lists which are a organized in sequences
- **Basic Terminology**:
    - Root: top node with no parent
    - Leaf: node with no children
    - Parent: node that has children
    - Child: node directly below another node
    - Siblings: nodes sharing the same parent
    - Path: sequence of edges between nodes 
    - Ancestor: any node above on path to root
    - Descendant: any node below in its branches
    - Level: `root = 0`, `children = 1`, etc.
    - Degree: number of children a node has
    - Height: number of nodes on the longest path from root to leaf
- Types of Trees:
    - A general Tree:
        - Nodes can have any number of children, but they are complex to work with and are usually converted to a binary tree
    - A Forest:
        - A collection of non-connected trees, where it can be empty because it is a set.
        - When you convert a tree into a forest, you have to delete the root, and vice versa: when you convert a forest to a tree, you have to add a new root connecting all
    - A Binary Tree:
        - Each node has 2 children at most, left and right, where there are:
            - if a tree has `n` nodes then it has exactly `n-1` edges
            - if the height `h` is the minimum number is `h` and the maximum $2^h- 1$
            - if nodes are present, then the height is at least $log_2(n+1)$ and the maximum is `n`
    - A Complete Binary Tree:
        - In a complete tree, all levels are filled except the last one (possibly), therefore nodes are packed to the left
            - For a node at index `k`:
                - the left child = 2k, the right child = 2k+1
                - the parent = floor(k/2)
            - Height = floor($log_2(n+1)$)
    - Extended Binary Tree (2-tree):
        - Every node has either 0 or 2 children, and you can replace empty children with external nodes (squares)
        - Original nodes are circles because they are internal nodes, this is used in huffman coding
    - Expression Tree:
        - Operators are internal nodes while operands are leaf nodes. 
        - Traversal through the tree changes the notation:
            - Pre-order → Prefix (+ab)
            - In-Order → Infix (a+b)
            - Post-order → Postfix (ab+)
    - Tournament Tree:
        - Leaf nodes are players, internal nodes are match winners, root is the overall winner
        - Also called a winner tree
- Memory Representation:
    - Linked Representation:
        - Each node has three parts: left pointer, data, right pointer
        - Uses `NULL` pointers for empty children
        - Root pointer points to the top node
        ```c
        struct node {
            struct node *left;
            int data;
            struct node *right;
        };
        ```
- Sequential (Array) Representation:
    - Tree stored in a 1D array with the root at index 1
    - For a node at index k, children are at 2k and 2k+1
    - Max array size is $2^h - 1$, but it wastes space if the tree is sparse

- Converting a General Tree to a Binary Tree:
    - Rule 1: root of binary tree = root of general tree
    - Rule 2: left child of node = leftmost child in general tree
    - Rule 3: right child of node = next sibling to the right in general tree

- Tree Traversals:
    - Pre-order (NLR): Node → Left → Right
        - Visit root, traverse left, traverse right
        - Also called depth-first, gives prefix notation
    - In-order (LNR): Left → Node → Right
        - Traverse left, visit root, traverse right
        - Also called symmetric traversal, gives infix notation, prints BST in sorted order
    - Post-order (LRN): Left → Right → Node
        - Traverse left, traverse right, visit root
        - Gives postfix notation
    - Level-order:
        - Visit nodes level by level, left to right
        - Also called breadth-first

- Reconstructing a Tree from Traversals:
    - You need two traversals, and one must be in-order
    - In-order + Pre-order: first element in pre-order is the root, find it in in-order to get left and right subtrees, repeat
    - In-order + Post-order: last element in post-order is the root, same splitting logic

- Huffman Coding:
    - A lossless compression algorithm where frequent characters get shorter codes and rare characters get longer codes
    - Algorithm:
        - Create a leaf node for each character with its frequency weight
        - Put all nodes in a priority queue (lowest frequency first)
        - While more than one node exists:
            - Remove the two lowest weight nodes
            - Create a parent node with weight = their sum
            - Add the parent back to the queue
        - The last node remaining is the root of the Huffman tree
        - Assign 0 to left branches and 1 to right branches
    - Important formula: $Le = Li + 2n$ where:
        - Le = external path length (sum of paths to all leaves)
        - Li = internal path length (sum of paths to all internal nodes)
        - n = number of internal nodes

- Common Applications:
    - File system directories
    - Compilers (syntax trees, expression trees)
    - Databases (B-trees for indexing)
    - Data compression (Huffman coding)
    - Operating systems (Red-black trees for scheduling)
    - Symbol tables

- Quick Reference Formulas:
    - Max nodes at level $l$: $2^l$
    - Max nodes in a tree with height $h$: $2^h - 1$
    - Min height for $n$ nodes: $\lceil log_2(n+1) \rceil$
    - Max height for $n$ nodes: $n$
    - Edges in a tree with $n$ nodes: $n - 1$
    - Height of a complete tree: $\lfloor log_2(n+1) \rfloor$
        