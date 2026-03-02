#include <stdio.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *tree;

struct node *insert();
int preorder();
int inorder();
int postorder();
struct node *smallest();
struct node *largest();
struct node *deleteNode();
int countNodes();
int countExt();
int countInt();
int height();
struct node *mirrorTree();
struct node *deleteTree();

char *alloc();
int free();

int main()
{
    int op;
    int val;
    struct node *p;
    tree = NULL;
    op = 0;

    while(op != 14){
        printf("\nMENU\n");
        printf("1 insert\n");
        printf("2 preorder\n");
        printf("3 inorder\n");
        printf("4 postorder\n");
        printf("5 smallest\n");
        printf("6 largest\n");
        printf("7 delete\n");
        printf("8 count nodes\n");
        printf("9 count external\n");
        printf("10 count internal\n");
        printf("11 height\n");
        printf("12 mirror\n");
        printf("13 delete tree\n");
        printf("14 exit\n");
        scanf("%d",&op);

        if(op==1){
            scanf("%d",&val);
            tree = insert(tree,val);
        }
        else if(op==2){
            preorder(tree);
        }
        else if(op==3){
            inorder(tree);
        }
        else if(op==4){
            postorder(tree);
        }
        else if(op==5){
            p = smallest(tree);
            if(p) printf("%d\n",p->data);
        }
        else if(op==6){
            p = largest(tree);
            if(p) printf("%d\n",p->data);
        }
        else if(op==7){
            scanf("%d",&val);
            tree = deleteNode(tree,val);
        }
        else if(op==8){
            printf("%d\n",countNodes(tree));
        }
        else if(op==9){
            printf("%d\n",countExt(tree));
        }
        else if(op==10){
            printf("%d\n",countInt(tree));
        }
        else if(op==11){
            printf("%d\n",height(tree));
        }
        else if(op==12){
            tree = mirrorTree(tree);
        }
        else if(op==13){
            tree = deleteTree(tree);
        }
    }
    return 0;
}

struct node *insert(tree,val)
struct node *tree;
int val;
{
    struct node *n;
    n  = alloc(6);

    n->data = val;
    n->left = NULL;
    n->right = NULL;

    if(tree==NULL){
        return n;
    }

    if(val < tree->data){
        tree->left = insert(tree->left,val);
    } else {
        tree->right = insert(tree->right,val);
    }
    return tree;
}

int preorder(tree)
struct node *tree;
{
    if(tree){
        printf("%d ",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
    return 0;
}

int inorder(tree)
struct node *tree;
{
    if(tree){
        inorder(tree->left);
        printf("%d ",tree->data);
        inorder(tree->right);
    }
    return 0;
}

int postorder(tree)
struct node *tree;
{
    if(tree){
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ",tree->data);
    }
    return 0;
}

struct node *smallest(tree)
struct node *tree;
{
    if(!tree) return NULL;
    while(tree->left){
        tree = tree->left;
    }
    return tree;
}

struct node *largest(tree)
struct node *tree;
{
    if(!tree) return NULL;
    while(tree->right){
        tree = tree->right;
    }
    return tree;
}

struct node *deleteNode(tree,val)
struct node *tree;
int val;
{
    if(!tree) return NULL;

    if(val < tree->data){
        tree->left = deleteNode(tree->left,val);
    }
    else if(val > tree->data){
        tree->right = deleteNode(tree->right,val);
    }
    else{
        if(!tree->left)
        {
            struct node *r;
            r = tree->right;
            free(tree);
            return r;
        }
        else if(!tree->right){
            struct node *l;
            l = tree->left;
            free(tree);
            return l;
        }
        else{
            struct node *s;
            s  = smallest(tree->right);
            tree->data = s->data;
            tree->right = deleteNode(tree->right,s->data);
        }
    }
    return tree;
}

int countNodes(tree)
struct node *tree;
{
    if(!tree) return 0;
    return 1 + countNodes(tree->left) + countNodes(tree->right);
}

int countExt(tree)
struct node *tree;
{
    if(!tree) return 0;
    if(!tree->left && !tree->right) return 1;
    return countExt(tree->left) + countExt(tree->right);
}

int countInt(tree)
struct node *tree;
{
    if(!tree) return 0;
    if(!tree->left && !tree->right) return 0;
    return 1 + countInt(tree->left) + countInt(tree->right);
}

int height(tree)
struct node *tree;
{
    if(!tree) return 0;
    int l;
    l = height(tree->left);
    int r;
    r = height(tree->right);
    return (l>r?l:r)+1;
}

struct node *mirrorTree(tree)
struct node *tree;
{
    if(tree){
        struct node *tmp;
        tmp = tree->left;
        tree->left = tree->right;
        tree->right = tmp;
        mirrorTree(tree->left);
        mirrorTree(tree->right);
    }
    return tree;
}

struct node *deleteTree(tree)
struct node *tree;
{
    if(tree){
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
    return NULL;
}