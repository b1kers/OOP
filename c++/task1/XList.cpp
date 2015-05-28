#include <iostream>

//#include "XListIterator"

// Data = int
// Node n = 42;
// Node n(42); Node n{42};
using namespace std;

template <typename Data> class XList{
    class Node{
        public:
            Data d;
            Node *next, *prev;
            explicit Node(Data dat = 0){d = dat; next = 0; prev = 0;}
    };
    Node *pbeg, *pend;
    public:
        XList(){pbeg = 0; pend = 0;}
        ~XList();
        void add_to_end(Data d);
        void add_to_begin(Data d);
        void print() const;
        void clear();
        bool check() const;
        void rm_first();
        void rm_last();
        void iteritems() const;
        int count() const;
        Data get_first() const;
        Data get_last() const;

};

template <typename Data>
    XList <Data>::~XList(){
        if(pbeg != 0){
            Node *pv = pbeg;
            while (pv){
                pv = pv->next; delete pbeg;
                pbeg = pv;}
            }
    }

template <typename Data>
    void XList <Data>::add_to_end(Data d){
        Node *pv = new Node(d);
        if (this->check()) {
            cout << pv;
            //pend = pv;
            //pbeg = pv;
        }
        else {
            pv->prev = pend;
            pend->next = pv;
            pend = pv;}
    }

template <typename Data>
    void XList <Data>::rm_first(){
        if (this->check()) return;
        else {
            Node *pv = pbeg;
            pbeg = pbeg->next;
            delete pv;
    }
}

template <typename Data>
    void XList <Data>::rm_last(){
        if (this->check()) return;
        else {
            Node *pv = pend;
            pend = pend->prev;
            delete pv;
    }
}

template <typename Data>
    void XList <Data>::add_to_begin(Data d){
        Node *pv = new Node(d);
        if (this->check()) pend = pbeg = pv;
        else {
            pv->next = pbeg;
            pbeg->prev = pv;
            pbeg = pv;}
    }

template <typename Data>
    bool XList <Data>::check() const {
        if (this->pbeg == 0) return true;
        else return false;
    }

template <typename Data>
    void XList <Data>::print() const {
        Node *pv = pbeg;
        cout << endl << "list: ";
        while(pv){
            cout << pv->d << "    ";
            pv = pv->next;
        }
        cout << endl;
    }
 
template <typename Data>
     void XList <Data>::clear(){
        if (this->check()) return;
        else {
            Node *pv = pbeg;
            while(pv){
                delete pv;
                pv = pv->next;
            }
        }
    }

template <typename Data>
     int XList <Data>::count() const {
        int i = 0;
        if (this->check()) return i;
        else {
            Node *pv = pbeg;
            while(pv){
                pv = pv->next;
                ++i;
            }
            cout << i << endl;
            return i;
        }
    }

template <typename Data>
    Data XList <Data>::get_first() const {
    return pbeg->d;
}

template <typename Data>

    Data XList <Data>::get_last() const {
    return pend->d;
}
/*
template <typename Data>
    void XList <Data>::iteritems() const {
    for (XList<Data>::XListIterator it=list.begin(); it!=list.end(); it++) {
        cout << *it << " ";
    }
}*/