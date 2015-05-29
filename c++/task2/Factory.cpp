#include <iostream>
#include "Shapes.h"


class Creator{
public:
  virtual Shape* factoryMethod() = 0;
    virtual int print_info() = 0;

};

class ConcreteCreatorPoints: public Creator{
public:
  Shape* factoryMethod() {
      float x = std::rand() % 100;
      float y = std::rand() % 100;
      return new Point("generated", x, y);
  }
    int print_info(){
        std::cout << "Points: "<< Point::get_concrete_count() << std::endl;
    }
};

class ConcreteCreatorCircle: public Creator{
public:
  Shape* factoryMethod() {
      float x = std::rand() % 100;
      float y = std::rand() % 100;
      float r = std::rand() % 100;
      return new Circle("generated", x, y, r);
    }
    int print_info(){
        std::cout << "Circles: " <<  Circle::get_concrete_count() << std::endl;
    }
};


class ConcreteCreatorPolyline: public Creator{
public:
  Shape* factoryMethod() {return new Polyline("generated");}
    int print_info(){
        std::cout << "Polylines:" << Polyline::get_concrete_count() << std::endl;
    }
};



class ConcreteCreatorPolygon: public Creator{
public:
  Shape* factoryMethod() {return new Polygon("generated");}
    int print_info(){
        std::cout << "Polygons:" << Polygon::get_concrete_count() << std::endl;
    }
};

class ConcreteCreatorRect: public Creator{
public:
  Shape* factoryMethod() {
      float x = std::rand() % 100;
      float y = std::rand() % 100;
      float x1 = std::rand() % 100;
      float y1 = std::rand() % 100;
      return new Rect("generated", x, y, x1, y1);}
    int print_info(){
        std::cout << "Rects:" << Rect::get_concrete_count() << std::endl;
    }
};