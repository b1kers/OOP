#include <iostream>
//#include "Base.h"
//#include "Shapes.h"
#include "Factory.cpp"
using namespace std;



int main() {
    static const size_t count = 2;
    cout << to_string(3.4);
    ConcreteCreatorPoints CreatorPoint;
    ConcreteCreatorCircle CreatorCircle;
    ConcreteCreatorRect CreatorRect;
    Creator*creators[count] = {&CreatorPoint, &CreatorCircle};
    for(size_t i = 0; i<count; i++) {
        Shape *product = creators[i]->factoryMethod();
        product->get_info();
        delete product;
    }
    /*
    static const size_t count = 2;
    ConcreteCreatorPoints CreatorA;
    ConcreteCreatorPolyline CreatorB;
    // An array of creators
    Creator*creators[count] = {&CreatorA, &CreatorB};
    // Iterate over creators and create products
    for(size_t i = 0; i<count; i++) {
        Shape *product = creators[i]->factoryMethod();
        cout << product->getName() << endl;
        delete product;
    }
  return 0;*/
}