#include <iostream>
#include "Shapes.h"


class Creator{
public:
  virtual Shape* factoryMethod() = 0;
};

class ConcreteCreatorPoints: public Creator{
public:
  Shape* factoryMethod() {
      float x = std::rand() % 100;
      float y = std::rand() % 100;
      //Point * a = new Point("generated", x, y);
      return new Point("generated", x, y);
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
};


class ConcreteCreatorPolyline: public Creator{
public:
  Shape* factoryMethod() {return new Polyline("generated");}
};


class ConcreteCreatorRect: public Creator{
public:
  Shape* factoryMethod() {
      float x = std::rand() % 100;
      float y = std::rand() % 100;
      float x1 = std::rand() % 100;
      float y1 = std::rand() % 100;
      return new Rect("generated", x, y, x1, y1);}
};