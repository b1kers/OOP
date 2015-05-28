#include <iostream>
#include <assert.h>
#include "XList.cpp"

using namespace std;
class XListTests
{
public: static void test_add_to_begin(){
        XList<const char *> * a = new XList<const char *>;
        a->add_to_begin("a");
        a->add_to_begin("b");
        assert(a->get_first() == "b");
        delete a;
    }
    static void test_add_to_end(){
        XList<const char *> * a = new XList<const char *>;
        a->add_to_end("a");
        a->add_to_end("b");
        assert(a->get_last() == "b");
        delete a;
    }
};


int main(){
    XListTests::test_add_to_begin();
    XListTests::test_add_to_end();
    XList<const char *> * a = new XList<const char *>;
    a->add_to_end("a");
    a->add_to_end("b");
    a->add_to_end("b");
    //a->iteritems();
    return 0;
}
