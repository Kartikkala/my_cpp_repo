#include <iostream>

struct BSTNode
{
    struct BSTNode *left;
    struct BSTNode *right;
    int data;
    BSTNode(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

struct BSTNode *root = nullptr;

void insert(int data, struct BSTNode **root)
{
    if(*root == nullptr)
    {
        *root = (struct BSTNode*)malloc(sizeof(struct BSTNode));
        (*root)->left = nullptr;
        (*root)->right = nullptr;
        (*root)->data = data;
        return;
    }
    if((*root)->data > data)
    {
        return insert(data, &(*root)->left);
    }
    insert(data, &(*root)->right);
}

void remove(int data, BSTNode **root)
{
    if(*root == nullptr)
        return;
    if(data < (*root)->data)
    {
        remove(data, &(*root)->left);
    }
    else if(data > (*root)->data)
    {
        remove(data, &(*root)->right);
    }
    else
    {
        if(!(*root)->right && !(*root)->left)
        {
            free(*root);
            *root = nullptr;
            return;
        }
        else if(!(*root)->left)
        {
            struct BSTNode *temp = (*root)->right;
            free(*root);
            *root = temp;
            return;
        }
        else if(!(*root)->right)
        {
            struct BSTNode *temp = (*root)->left;
            free(*root);
            *root = temp;
            return;
        }
        else{
            struct BSTNode *succesor = (*root)->right;
            while (succesor->left)
            {
                succesor = succesor->left;
            }
            (*root)->data = succesor->data;
            remove(succesor->data, &(*root)->right);
        }
    }
}
void inOrder(struct BSTNode **root)
{
    if(*root == nullptr)
        return;
    inOrder(&(*root)->left);
    std::cout << (*root)->data << std::endl;
    inOrder(&(*root)->right);
    return;
}
void insert(int data)
{
    insert(data, &root);
}
void remove(int value) {
    remove(value, &root);
}
struct BSTNode * getRoot()
{
    return root;
}

void inOrder()
{
    inOrder(&root);
}


int main(void)
{
    root = new BSTNode(2);
    insert(45);
    insert(42);
    insert(55);
    insert(15);
    insert(35);
    insert(55);
    insert(75);
    inOrder();
}