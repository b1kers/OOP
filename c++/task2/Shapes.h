#include <iostream>
#include <string>
#include <sstream>
#include "Base.h"
#include "XList.cpp"

class Point: public Shape, public Printable
{
    friend std::ostream &operator<<(std::ostream &, const Point &);
public:
    Point(const char * name = "default", float _x = 0, float _y = 0);
    void print() const override;
    void set_point(float, float);
    /*const Point& operator = (const Point &P){
        if (&P == this) return *this;
        if (Point::Shape::init_name) delete [] Point::Shape::init_name;
        return *this;
    }   ;
    bool operator == (const Point &P) {
        if (P.get_x() == get_x() && P.get_y() == get_y()) return true;
        return false;
    }*/
    float get_x() const { return x; };
    float get_y() const { return y; };
    virtual void get_info(){ Point::print();};
private:
    float x;
    float y;
};
/*
const Point& operator = (const Point &P){
    if (&P == this) return *this;
    if (name) delete [] name;
    return *this;
}*/

Point::Point(const char *name, float _x , float _y ):Shape(name), Printable(name) {
    set_point(_x, _y);
}

void Point::set_point(float _x, float _y) {
    x = _x;
    y = _y;
}



void Point::print() const {
    std::cout << "Point " << Point::Shape::init_name << " at [" << x << "," << y << "]" << std::endl;
}

std::ostream &operator<< (std::ostream &output, const Point &p)
{
    p.print();
    return output;
}

/*--------------------------------------------------*/


class Circle: public Shape, public Printable
{
    friend std::ostream &operator<<(std::ostream &, const Circle &);

public:
    Circle(const char * name = "default", float _x = 0, float _y = 0, float r = 0);
    void print() const override;
    void set_circle(float, float, float);
    virtual void get_info(){ Circle::print();};
private:
    float x;
    float y;
    float r;
};

Circle::Circle(const char *name, float _x, float _y, float _r):Shape(name), Printable(name) {
    set_circle(_x, _y, _r);
}

void Circle::set_circle(float _x, float _y, float _r) {
    x = _x;
    y = _y;
    r = _r;
}

void Circle::print() const {
    std::cout << "Circle " << Circle::Shape::init_name << " with center at [" << x << "," << y << "], radius " << r << std::endl;
}

std::ostream &operator<< (std::ostream &output, const Circle &p) {
    p.print();
    return output;
}


/*--------------------------------------------------*/
class Polyline: public Shape, public Printable
{
    friend std::ostream &operator<<(std::ostream &, const Circle &);

public:
    Polyline(const char * name= "default");
    void print() const override;
    void add_point(Point * d);
    virtual void get_info() { Polyline::print();};
private:
    XList<Point *> * point_set;
};

Polyline::Polyline(const char * name):Shape(name), Printable(name){
    XList<Point *> * point_set = new XList<Point *>;
};


void Polyline::add_point(Point * a){
    point_set->add_to_end(a);
}

void Polyline::print() const {
    point_set->print();
}

std::ostream &operator<< (std::ostream &output, const Polyline &p) {
    p.print();
    return output;
}
/*----------------------------------*/

class Rect: public Shape, public Printable
{
    friend std::ostream &operator<<(std::ostream &, const Point &);
public:
    Rect(const char * name = "default", float x0 = 0, float y0 = 0, float x1 = 0, float y1 = 0 );
    void print() const override;
    void set_rect(float, float, float, float);
    virtual void get_info(){ Rect::print();};
private:
    float x0;
    float y0;
    float x1;
    float y1;

};

Rect::Rect(const char *name, float _x0 , float _y0, float _x1, float _y1  ):Shape(name), Printable(name) {
    set_rect(_x0 ,_y0,  _x1, _y1);
}

void Rect::set_rect(float _x, float _y, float __x, float __y ) {
    x0 = _x;
    y0 = _y;
    x1 = __x;
    y1 = __y;

}



void Rect::print() const {
    std::cout << "Rect" << Rect::Shape::init_name << " at [ (" << x0 << "," << y0 << "),(" << x1 << "," << y1 << ") ]" << std::endl;
}

std::ostream &operator<< (std::ostream &output, const Rect &p)
{
    p.print();
    return output;
}

/*--------------


class Polygon: public Shape, public Printable
{
    friend std::ostream &operator<<(std::ostream &, const Point &);
public:
    Polygon(const char * name = "default", float x0 = 0, float y0 = 0, float x1 = 0, float y1 = 0, float x2 = 0, float y2 = 0, ... );
    void print() const override;
    void set_rect(float, float, float, float);
    virtual void get_info(){ Polygon::print();};
private:
    std::list<tuple<float, float>> points;

};

Polygon::Polygon(const char *name, float _x0 , float _y0, float _x1, float _y1, float x2, float y2, ...):Shape(name), Printable(name) {
    set_rect(_x0 ,_y0,  _x1, _y1);
}

void Polygon::set_rect(float _x, float _y, float __x, float __y ) {
    x0 = _x;
    y0 = _y;
    x1 = __x;
    y1 = __y;

}



void Polygon::print() const {
    std::cout << "Polygon" << Polygon::Shape::init_name << " at [ (" << x0 << "," << y0 << "),(" << x1 << "," << y1 << ") ]" << std::endl;
}

std::ostream &operator<< (std::ostream &output, const Polygon &p)
{
    p.print();
    return output;
}
*/