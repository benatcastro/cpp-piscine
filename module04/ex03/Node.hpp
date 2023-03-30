#ifndef NODE_HPP
#define NODE_HPP

#include "AMateria.hpp"
 struct Node {
    Node();
    ~Node();

    static Node         *createNode(AMateria *content);
    static void         addNode(struct Node **head, struct Node *newNode);
    static void         freeList(struct Node *head);
    static void         print(struct Node **head);

    int                 idx;
    AMateria            *materia;
    struct Node         *next;
};

#endif
