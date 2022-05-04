#ifndef _TREE_H_
#define _TREE_H_

template <typename T>
struct treeNode {
    T val;
    treeNode* left = NULL;
    treeNode* right = NULL;

    treeNode(T newVal) : val(newVal)
    {
    }
};

template <typename T>
class Tree {
    public:
        //Initialize the root_ node for the Tree
        Tree(T val);
        Tree();
        
        //Should delete the entire tree.
        ~Tree();

        //Insert an element at the appropriate position in the Binary Search Tree
        void insertElement(T val);

        //Returns if the element is found in the Binary Search Tree
        bool search(const T val);

        //Delete the element from the Tree
        void deleteElement(const T val);

        //Overload Print
        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const Tree<U> &l);


    private:
        treeNode<T>* root_;
};


#endif

/*
  Function: constructor for tree with given value
  Input: value for the root_
  Returns: none
*/
template <typename T>
    Tree<T>::Tree(T val) {
        root_ = new treeNode(val);
    }

/*
  Function: default constructor for tree
  Input: none
  Returns: none
*/
template <typename T>
    Tree<T>::Tree() {
        root_ = NULL;
    }

/*
  Function: delete the tree recursively (for deconstructor)
  Input: node to delete and recursively delete subnodes
  Returns: none
*/
template <typename T>
    void deleteRecursion(treeNode<T> * curr) {
        if (curr != NULL) {
            deleteRecursion(curr->left);
            deleteRecursion(curr->right);
            delete curr;
        } else {
            return;
        }
    }

/*
  Function: deconstructor for tree. deletes entire tree
  Input: none
  Returns: none
*/
template <typename T>
    Tree<T>::~Tree() {
        deleteRecursion(root_);
    }

/*
  Function: insert the given value into the tree
  Input: value to add to the tree
  Returns: none
*/
template <typename T>
    void Tree<T>::insertElement(T val) {
        treeNode<T>* current = root_;    

        if (root_ == NULL) {
            root_ = new treeNode(val);
            return;
        }

        while (true) {
            if (val > current->val) {
                if (current->right == NULL) {
                    current->right = new treeNode(val);
                    break;
                } else {
                    current = current->right;
                }
                
            } else {
                if (current->left == NULL) {
                    current->left = new treeNode(val);
                    break;
                } else {
                    current = current->left;
                }
            }
        }
    }


/*
  Function: search the tree for the given value
  Input: value to search the tree for.
  Returns: true if value could be found, otherwise false.
*/
template <typename T>
    bool Tree<T>::search(const T val) {
        treeNode<T>* curr = root_;
        while (curr) {
            if (curr->val == val) {
                return true;
            } else if (curr->val < val) {
                curr = curr -> right;
            } else {
                curr = curr -> left;
            }
        }
        return false;
    }



/*
  Function: delete the given value from the tree and keep the tree valid.
  Input: value to delete from the tree.
  Returns: none
*/
template <typename T> 

    //LOGIC FOR THIS FUNCTION CAME FROM HERE
    //https://www.geeksforgeeks.org/binary-search-tree-set-3-iterative-delete/
    void Tree<T>::deleteElement(const T val) {
        treeNode<T>* curr = root_;
        treeNode<T>* prev = NULL;
        //Find node to delete
        while (curr != NULL && curr->val != val) {
            prev = curr;
            if (val < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        //One leaf
        if (curr->left == NULL || curr->right == NULL) {
            treeNode<T>* newCurr;
            if (curr->left == NULL)
                newCurr = curr->right;
            else
                newCurr = curr->left;

            if (prev == NULL) {
                return;
            }
    
            if (curr == prev->left) {
                prev->left = newCurr;
            } else {
                prev->right = newCurr;
            }
            free(curr);
        //two leaves
        } else {
            treeNode<T>* p = NULL;
            treeNode<T>* temp;
    
            temp = curr->right;
            while (temp->left != NULL) {
                p = temp;
                temp = temp->left;
            }

            if (p != NULL) {
                p->left = temp->right;
            } else {
                curr->right = temp->right;
            }
            curr->val = temp->val;
            free(temp);
        }
    }

/*
  Function: traverses the tree inorder (for use while printing)
  Input: output stream to append to, current tree node, and a delimiter (comma)
  Returns: none
*/
template <typename T>
void inorder(std::ostream& os, const treeNode<T>* curr, std::string *delimiter) {
    if (curr != NULL) {
        inorder(os, curr->left, delimiter);
        os << *delimiter << curr->val;
        *delimiter = ", ";
        inorder(os, curr->right, delimiter);
    }
}


/*
  Function: overloaded << operator for printing tree.
*/
template <typename U>
    std::ostream& operator<<(std::ostream& os, const Tree<U> &l) {
        os << "{";
        std::string delimiter = "";
        inorder<U>(os, l.root_, &delimiter);
        os << "}";
        return os;
    }
    
