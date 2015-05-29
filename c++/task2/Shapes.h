#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Base.h"
#include "XList.cpp"

class Point: public Shape, public Printable
{

    friend std::ostream &operator<<(std::ostream &, const Point &);
protected:
    static int concrete_quantity;
public:

    Point(const char * name = "default", float _x = 0, float _y = 0);
    ~Point(){--concrete_quantity;};
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
    static int get_concrete_count();
private:
    float x;
    float y;
};

int Point::concrete_quantity = 0;
/*
const Point& operator = (const Point &P){
    if (&P == this) return *this;
    if (name) delete [] name;
    return *this;
}*/

Point::Point(const char *name, float _x , float _y ):Shape(name), Printable(name) {
    ++concrete_quantity;
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

int Point::get_concrete_count() {
    return Point::concrete_quantity;
}


/*--------------------------------------------------*/


class Circle: public Shape, public Printable
{
    friend std::ostream &operator<<(std::ostream &, const Circle &);

protected:
    static int concrete_quantity;
public:
    Circle(const char * name = "default", float _x = 0, float _y = 0, float r = 0);
    ~Circle(){--concrete_quantity;};
    void print() const override;
    void set_circle(float, float, float);
    virtual void get_info(){ Circle::print();};
    static int get_concrete_count();

private:
    float x;
    float y;
    float r;
};

int Circle::concrete_quantity = 0;

Circle::Circle(const char *name, float _x, float _y, float _r):Shape(name), Printable(name) {
    ++concrete_quantity;
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
int Circle::get_concrete_count() {
    return Circle::concrete_quantity;
}


/*--------------------------------------------------*/
class Polyline: public Shape, public Printable
{
    friend std::ostream &operator<<(std::ostream &, const Circle &);
protected:
    static int concrete_quantity;
public:
    static int get_concrete_count();
    Polyline(const char * name= "default");
    ~Polyline(){--concrete_quantity;};
    void print() const override;
    void add_point(Point * d);
    virtual void get_info() { Polyline::print();};
private:
    XList<Point *> * point_set;
};

int Polyline::concrete_quantity = 0;

Polyline::Polyline(const char * name):Shape(name), Printable(name){
    ++concrete_quantity;
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

int Polyline::get_concrete_count() {
    return Polyline::concrete_quantity;
}

/*----------------------------------*/

class Rect: public Shape, public Printable
{
    friend std::ostream &operator<<(std::ostream &, const Point &);

protected:
    static int concrete_quantity;
public:
    static int get_concrete_count();
    Rect(const char * name = "default", float x0 = 0, float y0 = 0, float x1 = 0, float y1 = 0 );
    ~Rect(){--concrete_quantity;};
    void print() const override;
    void set_rect(float, float, float, float);
    virtual void get_info(){ Rect::print();};
private:
    float x0;
    float y0;
    float x1;
    float y1;

};

int Rect::concrete_quantity = 0;

Rect::Rect(const char *name, float _x0 , float _y0, float _x1, float _y1  ):Shape(name), Printable(name) {
    ++concrete_quantity;
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

int Rect::get_concrete_count() {
    return Rect::concrete_quantity;
}



class Polygon: public Shape, public Printable
{
    friend std::ostream &operator<<(std::ostream &, const Point &);
protected:
    static int concrete_quantity;
public:
    static int get_concrete_count();
    Polygon(const char * name = "default", vector<std::pair<float,float>> input_points = {std::make_pair(1,0),std::make_pair(0,0),std::make_pair(1,1) });
    ~Polygon(){--concrete_quantity;};
    void print() const override;
    void set_rect(vector<std::pair<float,float>>);
    virtual void get_info(){ Polygon::print();};
private:
    std::vector<pair<float, float>> points;

};

int Polygon::concrete_quantity = 0;

Polygon::Polygon(const char *name, vector<std::pair<float,float>> input_points):Shape(name), Printable(name) {
    ++concrete_quantity;
    set_rect(input_points);
}

void Polygon::set_rect(vector<std::pair<float,float>> _points) {
    points = _points;
}

void Polygon::print() const {
    std::cout << "Polygon with Points ";
    for(std::vector<std::pair<float,float>>::size_type  i = 0; i != points.size(); i++) {
        std::cout << "(" <<points[i].first << "," << points[i].second << ")";
        std::cout << "(" <<points[i].first << "," << points[i].second << ")";
    }
    std::cout << std::endl;
}

std::ostream& operator<< (std::ostream &output, const Polygon &p)
{
    p.print();
    return output;
}

int Polygon::get_concrete_count() {
    return Polygon::concrete_quantity;
}