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

        void remove(int data, node **root)
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
                    // No children
                    free(*root);
                    *root = nullptr;
                    return;
                }
                else if(!(*root)->left)
                {
                    struct node *temp = (*root)->right;
                    free(*root);
                    *root = temp;
                    return;
                }
                else if(!(*root)->right)
                {
                    struct node *temp = (*root)->left;
                    free(*root);
                    *root = temp;
                    return;
                }
                else{
                    struct node *succesor = (*root)->right;
                    while (succesor->left)
                    {
                        succesor = succesor->left;
                    }
                    (*root)->data = succesor->data;
                    remove(succesor->data, &(*root)->right);
                }
            }
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

        BinarySearchTree* remove(int value) {
            remove(value, &this->root);
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
    BinarySearchTree bst(45);
    bst.insert(25)->insert(65)->insert(15)->insert(35)->insert(55)->insert(75)->remove(25)->inOrder();
}