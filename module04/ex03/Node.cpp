#include "Node.hpp"
#include <iostream>



Node::Node() {
    std::cout << "Node constructor called\n";
}

Node::~Node() {
    std::cout << "Node destructor called\n";
}

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
    std::cout << "ADDING MATERIA: " << newNode->materia->getType() << " TO LINKED\n";
    if (!*head) {
        *head = newNode;
//        std::cout << "FIRST NODE\n";
        return;
    }
    last = *head;
    while (last) {
        std::cout << "ITERATOR\n";
        last = last->next;
    }
//    std::cout << "TEST" << last;
    last = newNode;
//    std::cout << "TEST" << last;
    Node::print(head);
}

void Node::freeList(struct Node *head) {
    struct Node *tmp;

//    std::cout << "==========START=============\n";
//    std::cout << "HEAD: " <<  head->next->materia->getType();
    while (head) {
//        std::cout << "TEST\n";
        tmp = head;
        delete tmp->materia;
        head = head->next;
    }
//    std::cout << "==========================\n";
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
