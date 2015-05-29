#include <iostream>

class Named
{
protected:
    const char * init_name;
public:
    Named(const char * name);
    //~Named();
};

Named::Named(const char * name){
    init_name = name;
    //std::cout << "constr " << init_name << std::endl;
}

class Printable: public Named
{
public:
    virtual void print() const {};
    Printable(const char * name) : Named(name){};
};

/*void Printable::print() const {
    std::cout << Named::init_name << std::endl;
}*/

class Shape: public  Named
{
protected:
    static int quantity;

public:
    static int get_count();
    Shape(const char * name) : Named(name){ ++quantity;};
    virtual ~Shape();
    virtual void get_info() = 0;
};


int Shape::quantity = 0;

Shape::~Shape() {
    --quantity;
};

int Shape::get_count() {
    return Shape::quantity;
}
