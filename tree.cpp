#include <iostream>

template <typename A>
struct node
{
    struct node<A> *left;
    struct node<A> *right;
    A data;
};

template <typename A>
class BinarySearchTree{
    private:
        struct node<A> *root = nullptr;
        void insert(int data, struct node<A> **root)
        {
            if(*root == nullptr)
            {
                *root = (struct node<A>*)malloc(sizeof(struct node<A>));
                (*root)->left = nullptr;
                (*root)->right = nullptr;
                (*root)->data = data;
                return;
            }
            if ((*root)->data > data) {
                insert(data, &(*root)->left);
            } else {
                insert(data, &(*root)->right);
            }
        }

        bool has(int data, node<A> *root)
        {
            if(root == nullptr)
                return false;
            if(root->data == data)
            {
                return true;
            }
            else if(root->data < data)
            {
                return has(data, root->right);
            }
            else if(root->data > data){
                return has(data, root->left);
            }
            return false;
        }
        

        void remove(A data, node<A> **root)
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
                    struct node<A> *temp = (*root)->right;
                    free(*root);
                    *root = temp;
                    return;
                }
                else if(!(*root)->right)
                {
                    struct node<A> *temp = (*root)->left;
                    free(*root);
                    *root = temp;
                    return;
                }
                else{
                    struct node<A> *succesor = (*root)->right;
                    while (succesor->left)
                    {
                        succesor = succesor->left;
                    }
                    (*root)->data = succesor->data;
                    remove(succesor->data, &(*root)->right);
                }
            }
        }

        void inOrder(struct node<A> **root)
        {
            if(*root == nullptr)
                return;
            inOrder(&(*root)->left);
            std::cout << (*root)->data << std::endl;
            inOrder(&(*root)->right);
            return;
        }
    public:
        BinarySearchTree(A data)
        {
            this->root = (struct node<A>*)malloc(sizeof(node<A>));
            this->root->data = data;
            this->root->left = nullptr;
            this->root->right = nullptr;
        }

        BinarySearchTree()
        {

        }

        BinarySearchTree *insert(A data)
        {
            this->insert(data, &this->root);
            return this;
        }

        bool has(A data)
        {
            return this->has(data, this->root);
        }

        BinarySearchTree* remove(A value) {
            remove(value, &this->root);
            std::cout << "\nRemoved node: " << value<< std::endl << std::endl;
            return this;
        }

        struct node<A> * getRoot()
        {
            return this->root;
        }
        

        BinarySearchTree *inOrder()
        {
            this->inOrder(&this->root);
            return this;
        }
    
};


// int main(void)
// {
//     BinarySearchTree<int> bst(45);
//     bst.insert(25)->insert(65)->insert(15)->insert(35)->insert(55)->insert(75)->inOrder()->remove(25)->inOrder();
// }