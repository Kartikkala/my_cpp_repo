#include <iostream>

struct node
{
    struct node *left;
    struct node *right;
    int data;
};

class BinarySearchTree{
    private:
        struct node *root = nullptr;
        void insert(int data, struct node **root)
        {
            if(*root == nullptr)
            {
                *root = (struct node*)malloc(sizeof(struct node));
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

        void inOrder(struct node **root)
        {
            if(*root == nullptr)
                return;
            inOrder(&(*root)->left);
            std::cout << (*root)->data << std::endl;
            inOrder(&(*root)->right);
            return;
        }
    public:
        BinarySearchTree(int data)
        {
            this->root = (struct node*)malloc(sizeof(node));
            this->root->data = data;
            this->root->left = nullptr;
            this->root->right = nullptr;
        }

        BinarySearchTree *insert(int data)
        {
            this->insert(data, &this->root);
            return this;
        }

        struct node * getRoot()
        {
            return this->root;
        }
        

        BinarySearchTree *inOrder()
        {
            this->inOrder(&this->root);
            return this;
        }
    
};


int main(void)
{
    BinarySearchTree bst(2);
    bst.insert(4)->insert(10)->insert(1)->insert(12)->inOrder();
}