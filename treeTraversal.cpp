//Elian Renteria
// treeTraversal.cpp
#include<iostream>
#include<stack>
using namespace std;

template <typename T>
struct BinaryNode
{
  T data;
  BinaryNode* left;
  BinaryNode* right;

  BinaryNode(const T & d = T()): data(d), left(nullptr), right(nullptr) {}
};
//print the elements of binary tree in preorder
template <typename T>
void preorder(BinaryNode<T>* t)
{
  if(t != NULL)
  {
    cout << t->data << " -> ";
    preorder(t->left);
    preorder(t->right);
  }

}
//print the elements of binary tree in inorder
template <typename T>
void inorder(BinaryNode<T>* t)
{
  if(t != NULL)
  {
    inorder(t->left);
    cout << t->data << " -> ";
    inorder(t->right);
  }

}
//print the elements of binary tree in postorder
template <typename T>
void postorder(BinaryNode<T>* t)
{
  if(t != NULL)
  {
    postorder(t->left);
    postorder(t->right);
    cout << t->data << " -> ";
  }

}
//extra credit nonrecursive inorder implementation 
template <typename T>
void inorder_nonrecur(BinaryNode<T>* t)
{
  stack<BinaryNode<T>*> inorder_stack;
  inorder_stack.empty();
  BinaryNode<T>* curr = t;

  while(curr != NULL || !inorder_stack.empty())
  {
    if(curr != NULL)
    {
      inorder_stack.push(curr);
      curr = curr->left;
    }
    else
    {
      curr = inorder_stack.top();
      inorder_stack.pop();
      cout << curr->data << " -> ";
      curr = curr->right;
    }
  }
}
//extra credit nonrecursive preorder implementation 
template <typename T>
void preorder_nonrecur(BinaryNode<T>* t)
{
  stack<BinaryNode<T>*> preorder_stack;
  preorder_stack.empty();
  preorder_stack.push(t);

  while(!preorder_stack.empty())
  {
    BinaryNode<T> *curr = preorder_stack.top();
    cout << curr->data << " -> ";
    preorder_stack.pop();
    if(curr->right != NULL)
      preorder_stack.push(curr->right);
    if(curr->left != NULL)
      preorder_stack.push(curr->left);
  }

}