#include <iostream>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int height;

    Node(int value)
    {
        data = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

class AVLTree{
    private:
        Node *node = nullptr;
        int getHeight(Node *node)
        {
            return node ? node ->height : 0;
        }
        
        int getBalanceFactor(Node *node)
        {
            return node ? getHeight(node->left) - getHeight(node->right) : 0;
        }

        void updateHeight(Node *node)
        {
            node -> height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        }

        Node *rightRotation(Node *node)
        {
            Node *newRoot = node->left;
            Node *child = node->left->right;
            node->left->right = node;
            node -> left = child;
            updateHeight(newRoot);
            updateHeight(node);
            return newRoot;
        }

        Node *leftRotation(Node *node)
        {
            Node *newRoot = node->right;
            Node *child = node->right->left;
            node->right->left = node;
            node -> right = child;
            updateHeight(newRoot);
            updateHeight(node);
            return newRoot;
        }
        Node *insert(Node *node, int value)
        {
            if(node == nullptr)
            {
                // Base condition
                return new Node(value);
            }
            else if(value < node->data)
            {
                node->left = insert(node->left, value);
            }
            else
            {
                node->right = insert(node->right, value);
            }
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
            
            int bf = this->getBalanceFactor(node);

            if(bf > 1)
            {
                // Left insertion (left heavy)
                if(value < node->left->data) // Left left
                {
                   return rightRotation(node);
                }
                else
                {
                    // Left-right case
                    node -> left = leftRotation(node->left);
                    return rightRotation(node);
                }

            }
            else if(bf < -1)
            {   
                if(value > node->right->data)
                {
                    // Right right case
                    return leftRotation(node);
                }
                else
                {
                    // Right left case
                    node->right = rightRotation(node->right);
                    return leftRotation(node);
                }
            }

            return node;
        }
        void inOrder(struct Node **root)
        {
            if(*root == nullptr)
                return;
            inOrder(&(*root)->left);
            std::cout << (*root)->data << std::endl;
            inOrder(&(*root)->right);
            return;
        }

    public:
        AVLTree *push(int value)
        {
            this->node = this->insert(this->node, value);
            return this;
        }

        AVLTree *inOrder()
        {
            this->inOrder(&this->node);
            return this;
        }

        
};

int main(void)
{
    AVLTree t;
    t.push(10)->push(20)->push(5)->push(40)->push(90)->inOrder();
}