//
//  Adjacent.h
//  AdjacencyMatrix
//
//  Created by David Clare on 11/6/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef AdjacencyMatrix_Adjacent_h
#define AdjacencyMatrix_Adjacent_h

class adjMatrix
{
public:
    adjMatrix(){
        height =0;
        width =0;
        value =0;
    };
    ~adjMatrix(){};
    void set_vertices(int a);
    void set_value(int a);
    int get_vertices();
    int get_value();
private:
    int vertices;
    int value;
    int edges;
    int connected;
    bool visited;
};


void adjMatrix::set_vertices(int a)
{
    vertices=a;
}

void adjMatrix::set_value(int a)
{
    value=a;
}





#endif
