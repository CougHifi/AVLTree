#pragma once
#include<iostream>

/* The sources that I looked at to make this tree:
Using the book's example method that I found through the authors online website.
http://users.cis.fiu.edu/~weiss/dsaa_c++4/code/AvlTree.h
*/
//Either inherit the AVLNode class to AVL Tree or inherit AVLTree to the node.
template<class T> class AVLNode
{
    public:
    AVLNode element;
    AVLNode();
    ~AVLNode();
    void getAVLNode();
    T getData();//returns the data stored in the node
    AVLNode(const T &ele, AVLNode *lt,AVLNode *rt, int h=0) : element{ele}, pleft{lt},pright{rt},AVLHeight{h}{}
    AVLNode(T &&ele,  AVLNode*lt. AVLNode*rt, int h=0):element{std::move(ele)}, pleft{lt},pright{rt},AVLHeight{h}{}
    //First insert that does something similar.
    //void insert(const T &x, AVLNode *&t);
    /*
    Inserting into a subtree. 
    X:is the item to insert.
    t:is the node that is the root of the subtree.
    */
   
    void insert(T &&x, AVLNode *&t);
    void remove(const T &x, AVLNode*&t);
    void balance(AVLNode *&t);
    AVLNode *findmin(AVLNode *t) const;
    AVLNode *findMax(AVLNode *t) const;
    bool contain(const T &x, AVLNode *t) const;
    private:
    AVLNode *root;
    AVLNode *pright;
    AVLNode *pleft;
    int AVLHeight;
    static const int Allowed_Imbalance = 1;
};

template<typename T> 
AVLNode<T>::AVLNode()
{

}
template<typename T>
AVLNode<T>::~AVLNode()
{

}
template<typename T>
void AVLNode<T>::getAVLNode()
{
    this->pleft;
    this->pright;
}
/*
template<typename T>
void AVLNode<T>::insert(T && x, AVLNode *&t)
{
    if (t == nullptr)
    {
        t=new AVLNode{std::move(x), nullptr, nullptr};
        else if(x<t->element)
        {
            insert(std::move(x), t->pleft); 
        }
        else if(t->element<x)
        {
            insert(std::move(x), t->pright)
        }
        balance(t);
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
    
    
}*/