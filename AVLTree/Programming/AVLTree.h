#pragma once
#include "AVLNode.h"
template<class T> class AVLTree 
{
    public:
    //AVLNode node;
    AVLTree();
    ~AVLTree();
    AVLTree () :root{nullptr};
    AVLTree(const AVLTree &rhs) : root{nullptr};
    operator=(const AVLTree &rhs);
    //AVLTree<AVLNode> *Leftptr;
    //AVLTree<AVLNode> *Rightptr;
    bool isEmpty() const;//determines if the tree is empty-returns 1. if it is empty returns 0.
    int AVLHeight(AVLNode *T);//returns the AVLHeight of the node or -1 if a nullptr.
    void insert(T &&x, AVLNode *&t);//inserts data into the tree- must abide by AVL Balancing properties.
    void remove(const T &x, AVLNode&t);//removes a specific item from the tree - must abide by AVL balancing properties
    void clear();//removes all nodes from the tree
    void rotateLeftChild(AVLTree *&k2);
    void doubleLeftChild(AVLTree *&k3);
    AVLTree *findmin(AVLTree *t)const;//returns smallest item in the tree
    AVLTree *findmax(AVLTree *t)const;//returns the largest item in the tree
    int printinOrder();
    //void GetAVLAVLHeight();//grabing the avl AVLHeight from avl node class.
    //void SetAVLAVLHeight(node*);
    private:
    AVLTree *AVLNode;//a pointer to the root AVLNode
};

template<typename T>
AVLTree<T>::AVLTree()
{
    
}

template<typename T>
AVLTree<T>::~AVLTree()
{
    clear();
}

//deep copying. Note doesn't work its expecting an explicit somewhere.
/*
template<typename T>
AVLTree&AVLTree<T> operator=(const AVLTree &rhs)
{
    AVLTree copy =rhs;
    std::swap(*this, copy);
    return *this;
}*/
//Moving, Same as note above doesn't work expecting an explicit somewhere.
/*
template<typename T>
AVLTree<T>::operator=(AVLTree &&rhs)
{
    std::swap(root, rhs.root);
    return *this;
}*/
template<typename T>
AVLTree<T>::AVLTree(const AVLTree &rhs) : root{nullptr}
{
    root = clone(rhs.root);
}

template<typename T>
void AVLNode<T>::insert(T && x, AVLNode *&t)
{
    if (t == NULL)
    {
        t = new AVLNode(x,NULL,NULL);
        else if(x<t->element)
        {
            insert(x,t->pleft)
            {
                if(height(t->pleft) - height(t->pright)==2)
                {
                    if(x<t->pleft->T)
                    {
                        rotateLeftChild(t);
                    }
                    else
                    {
                        doubleLeftChild(t);
                    }
                    else if(t->T<x)
                    {
                        insert(x,t->pright);
                        if(height(t->pright)-height(t->pleft)==2)
                        {
                            rotateRightChild(t);
                        }
                        else
                        {
                            doubleRightChild(t);
                        }
                        else
                        {
                            //Duplicate and do nothing.
                            t->height=max(height(t->pleft), height(t->pright)) + 1;
                        }
                        
                        
                    }
                    
                }
            }
        }
    }
}

template<typename T>
 void AVLNode<T>::remove(const T &x, AVLNode*&t)
 {
     if(t==nullptr)
     {
         return;//if item not found it does nothing.
     }
     if(x<t->element<x)
     {
         remove(x,t->pright);
     }
     else if(t->pleft !=nullptr && t->pright !=nullptr)//two children
     {
         t->element = findMin(t->pright)->element;
         remove( t->element, t->right);
     }
     else
     {
         AVLNode *oldNode = t;
         t = (t->pleft !=nullptr) ? t->pleft:t->pright;
         delete oldNode;
     }
     balance(t);
     
 }

template<typename T>
void AVLNode<T>::balance(AVLNode *&t)
{
    if(t==nullptr)
    {
        return;
    }
    if(AVLHeight(t->pleft)-AVLHeight(t->pright)>Allowed_Imbalance)
    {
        if(AVLHeight(t->pright->pright)>=AVLHeight(t->pleft->pright))
        {
            rotateRightChild(t);
        }
        else
        {
            doubleRightChild(t);
        }
        
        t->AVLHeight=max(AVLHeight(t->pleft), AVLHeight(t->pright))+1;
    }
}
//Finding the smallest item in a subtree t.
//Returns the node containing in the smallest item.
template<typename T>
AVLNode<T> *findmin(AVLNode<T> *t) //const
{
    //
    if(isEmpty())
    {
       throw "It's empty!";
    }
    if(t==nullptr)
    {
        return nullptr;
    }
    if(t->pLeft == nullptr)
    {
        return t;
    }
    return findmin(t->pleft);
}

template<typename T>
AVLNode<T> *findMax(AVLNode<T> *t) //const
{
    if (t!=nullptr)
    {
        while(t->pright !=nullptr)
        {
            t=t->pright;
        }
        return t;
    }
}

//I am not sure about this because I tried AVLNode but it was expecting a typename 
//in the (T*&K2) I originally did (AVLNode *&k2).
template<typename T>
void AVLTree<T>::rotateLeftChild(AVLTree*&k2)
{
    T *k1 = k2->pleft;
    k2->pleft = k1->pright;
    k1->pright=k2;
    k2->height = max(height(k2->pleft), height(k2->pright))+1;
    k1->height = max(height(k1->pleft), k2->height)+1;
    k2=k1;
}
//Doesn't like to have AVLNode here compared to the AVLTree.
template<typename T>
void AVLTree<T>::doubleLeftChild(AVLTree *& k3)
{
    rotateRightChild(k3->pleft);
    rotateLeftChild(k3);
}
/*This function is a method to test an item in the subtree.
Where X is the item that is being searched for.
While T is the node that tracks the root of the tree.*/
template<typename T>
bool AVLNode<T>::contain(const T &x, AVLNode *t) const 
{
    if(t==nullptr)
    {
        return false;
    }
    else if (x<t->element)
    {
        return T(x,t->pleft);
    }
    else if (t->element <x)
    {
        return T(x,t->pright);
    }
    else
    {
        return true;//if there was a match
    }
    
    
}
//Making the tree empty logically.
template <typename T>
void AVLTree<T>::clear()
{
    clear(root);
}

template <typename T>
bool AVLTree<T>::isEmpty() const
{
    return root == nullptr;
}

template <typename T>
int AVLTree<T>::printinOrder()
{
    if(isEmpty())
    {
        std::cout<<"Tree is Empty"<<std::endl;
    }
    else
    {
        printinOrder(root);
    }
    
}