#include "XList.cpp"

class XListIterator{
    Node *nodeptr;
public:
    XListIterator(node* ptr):nodeptr(ptr) {}
    XListIterator &operator++(int i)
    {
        nodeptr = nodeptr->next;
        return *this;
    }
    XListIterator &operator--(int i)
    {
        nodeptr = nodeptr->prev;
        return *this;
    }
    universum &operator*()
    {
        return nodeptr->value;
    }
    bool operator==(const XListIterator& ptr)
    {
        return nodeptr==ptr.nodeptr;
    }
    bool operator!=(const XListIterator& ptr)
    {
        return nodeptr!=ptr.nodeptr;
    }
};

XListIterator begin(){
    XListIterator b(root);
    return b;
}

XListIterator end(){
    XListIterator e(last);
    return e;
}