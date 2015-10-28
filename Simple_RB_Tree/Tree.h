//
//  Tree.h
//  Simple_RB_Tree
//
//  Created by David Clare on 10/28/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef Simple_RB_Tree_Tree_h
#define Simple_RB_Tree_Tree_h

#include <iostream>

using namespace std;

template<class T>
class Tree
{
public:
    Tree();
    Tree(Tree const & lft, T val, Tree const & rgt)
};

struct Node
{
    Node(shared_ptr<const Node> const & lft, T val,
    shared_ptr<const Node> const & rgt)
    : _lft(lft), _val(val), _rgt(rgt)
    {}
    
    shared_ptr<const Node> _lft;
    T _val;
    shared_ptr<const Node> _rgt;3
};


#endif
