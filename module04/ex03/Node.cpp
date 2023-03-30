#include "Node.hpp"
#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"

Node::Node() {}

Node::~Node() {}

Node *Node::createNode(AMateria *content) {
    struct Node *newNode = new Node;
    static int idx;

    newNode->materia = content;
    newNode->next = NULL;
    newNode->idx = idx;
    idx++;
    return (newNode);
}

void Node::addNode(struct Node **head, struct Node *newNode) {
    struct Node *last;
//    std::cout << "ADDING MATERIA: " << newNode->materia->getType() << " TO LINKED\n";
    if (!*head) {
        *head = newNode;
        return;
    }
    last = *head;
    while (last->next) {
//        std::cout << "ITERATOR\n";
        last = last->next;
    }
    last->next = newNode;
//    Node::print(head);
}

void Node::freeList(struct Node *head) {
    struct Node *tmp;

    while (head) {
        tmp = head;
        delete tmp->materia;
        head = head->next;
        delete tmp;
    }
}

void Node::print(struct Node **head) {
    struct Node *tmp;

    tmp = *head;
    std::cout << "==========START=============" << std::endl;
    while (tmp) {
        std::cout << "Node id: " << tmp->idx << std::endl;
        std::cout << "Materia: " << tmp->materia->getType() << std::endl;
        std::cout << "Adress: " << tmp << std::endl;
        std::cout << "=======================" << std::endl;
        tmp = tmp->next;
    }
}

void Node::copy(struct Node *node, struct Node *pNew)
{
    Node *tmp = node;
    while (tmp) {
        if (tmp->materia->getType() == "ice")
            Node::addNode(&pNew, Node::createNode(new Ice));
        if (tmp->materia->getType() == "cure")
            Node::addNode(&pNew, Node::createNode(new Cure));
        tmp = tmp->next;
    }
}
