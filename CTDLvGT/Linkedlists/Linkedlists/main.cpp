#include"Element.h"
#include"Linkedlist.h"
#include"LinkedlistUnique.h"
#include "LinkedlistDual.h"
#include<iostream>
using namespace std;
int main() {
   /* Linkedlist* list_ = new  Linkedlist();  
    Element* e,*q;
    e = new Element(9);
    list_->insertLast(e);
    e = new Element(10);
    list_->insertLast(e);
    e = new Element(8);
    list_->insertLast(e);
    e = new Element(11);
    list_->insertLast(e);
    q = new Element(10);
    list_->travel();
    list_->deleteP(q);
    cout << "\n";
    list_->travel();*/
    LinkedlistDual* list = new LinkedlistDual();
    ElementDual *e,*q ;
    e = new ElementDual(9);
    list->insertFist(e);
    e = new ElementDual(10);
    list->insertFist(e);
    e = new ElementDual(8);
    list->insertFist(e);
    e = new ElementDual(11);
    list->insertTail(e);
    q = new ElementDual(12);
    list->insertBefore(q, e);
    list->travelNext();
    //cout << "\n";
    //list->travelPrev();
    return 0;

}