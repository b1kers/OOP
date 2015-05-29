#include <iostream>
//#include "Base.h"
//#include "Shapes.h"
#include "Factory.cpp"
using namespace std;

int main() {
    static const size_t count = 5;
    ConcreteCreatorPoints CreatorPoint;
    ConcreteCreatorCircle CreatorCircle;
    ConcreteCreatorRect CreatorRect;
    ConcreteCreatorPolyline CreatorPolyline;
    ConcreteCreatorPolygon CreatorPolygon;
    Creator * creators[count] = {&CreatorPoint, &CreatorCircle, &CreatorRect, &CreatorPolyline, &CreatorPolygon };
    XList<Shape *> * list_fo_figures = new XList<Shape *>;
    //1
    for(size_t i = 0; i<20; i++) {
        Shape *product = creators[rand()%count]->factoryMethod();
        list_fo_figures->add_to_begin(product);
    }
    //2
    cout << Shape::get_count()<< endl;
    //3
    for(size_t i = 0; i<count; i++) {
        creators[i]->print_info();
    }
    //4
    list_fo_figures->print();
    //list_fo_figures->print();
    //5
    list_fo_figures->clear();
    cout << Shape::get_count() << endl;
    return 0;
}