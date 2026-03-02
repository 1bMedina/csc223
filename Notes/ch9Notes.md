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
    - Level: `root = 0`, `children=  1`, etc.
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
        - In a complete tree, all levels are filled except the last one (ppssibly), therefore nodes are packed to the left
            - For a node at index `k`:
                - the left child = 2k, the right child = 2k+1
                - the parent = floor(k/2)
            - Height = floo
        