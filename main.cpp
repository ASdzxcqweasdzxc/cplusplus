#include <iostream>

/** third part */
class Body {
public:
    virtual void area() = 0;
};


/**
 * first part
 */
class Box: public Body{
    int length, width, height;
public:
    /** getters */
    int GetLength() const { return length; }
    int GetWidth() const { return width; }
    int GetHeight() const { return height; }

    /** setters */
    void setLength(int l){
        length = l;
    }

    void setWidth(int w){
        width = w;
    }

    void setHeight(int h){
        height = h;
    }

    /** default constructor */
    /** 'explicit' - got parameters with defaults and prevents converting types */
    explicit Box(){
        setLength(10);
        setHeight(10);
        setWidth(10);
        std::cout << "Default constructor\n";
    };

    /** one parameter */
    explicit Box(int x){
        setLength(x);
        setHeight(10);
        setWidth(10);
        std::cout << "One parameter constructor\n";
    };

    /** two parameters */
    explicit Box(int x, int y){
        setLength(x);
        setHeight(y);
        setWidth(10);
        std::cout << "Two parameters constructor\n";
    };

    /** three parameters */
    explicit Box(int x, int y, int z){
        setLength(x);
        setWidth(y);
        setHeight(z);
        std::cout << "Three parameters constructor\n";
    }

    /** copy constructor */
    Box(const Box& ref){
        setLength(ref.GetLength());
        setHeight(ref.GetHeight());
        setWidth(ref.GetWidth());
    }

    /** destructor */
    ~Box() {std::cout << "Destructor initialized\n";}

    /** area of box method */
    void area() override {
        int s = GetLength()*GetWidth() + 2*GetLength()*GetHeight() + 2*GetWidth()*GetHeight();
        std::cout << "value of box= " << s << std::endl;
    }

    /** second part */
    /** overload '=' */
    Box& operator=(const Box& x){
        Box res(width = x.width, height = x.height, length = x.length);
        return *this;
    }

    /** overload '++x' */
    Box& operator++(){
        ++width; ++height; ++length;
        return *this;
    }

    /** overload 'x++' */
    Box operator++(int){
        Box temp = *this;
        ++*this;
        return temp;
    }

    /** overload '--x' */
    Box& operator--(){
        --width; --height; --length;
        return *this;
    }

    /** overload '--x' */
    Box operator--(int){
        Box temp = *this;
        --*this;
        return temp;
    }

    /** introducing friend */
    friend Box operator+(Box op1, Box op2);

};

/** '+' func overload */
Box operator+(Box op1, Box op2){
    Box temp;
    temp.setLength(op1.GetLength() + op2.GetLength());
    temp.setWidth(op1.GetWidth() + op2.GetWidth());
    temp.setHeight(op1.GetHeight() + op2.GetHeight());
    return temp;
};

/** forth part */
class WBox: public Box{
    int w_window, h_window;
public:
    /** getters */
    int GetWWindow() const { return w_window; }
    int GetHWindow() const { return h_window; }

    /** setters */
    void setWWindow(int _w_window){
        w_window = _w_window;
    }

    void setHWindow(int _h_window){
        h_window = _h_window;
    }

    /** default constructor */
    /** 'explicit' - got parameters with defaults and prevents converting types */
    explicit WBox(): Box(){
        setWWindow(5);
        setHWindow(5);
        std::cout << "Three Default parameters constructor\n";
    };

//    /** one parameter */
//    explicit WBox(int a): Box(){
//        setLength(a);
//        setWidth(1);
//        setHeight(1);
//        setWWindow(5);
//        setHWindow(5);
//        std::cout << "One parameter constructor\n";
//    }
//
//    /** two parameters */
//    explicit WBox(int a, int b): Box(){
//        setLength(a);
//        setWidth(b);
//        setHeight(1);
//        setWWindow(5);
//        setHWindow(5);
//        std::cout << "Two parameters constructor\n";
//    }

    /** four parameters */
    explicit WBox(int _w_window): Box(){
        setWWindow(_w_window);
        setHWindow(5);
        std::cout << "Four parameters constructor\n";
    }

    /** five parameters */
    explicit WBox(int _w_window, int _h_window): Box(){
        setWWindow(_w_window);
        setHWindow(_h_window);
        std::cout << "Five parameters constructor\n";
    }

    /** copy constructor */
    WBox(const WBox& ref){
        setLength(ref.GetLength());
        setWidth(ref.GetWidth());
        setHeight(ref.GetHeight());
        setWWindow(ref.GetWWindow());
        setHWindow(ref.GetHWindow());
    }

    /** area of box method */
    void area() override {
        int s = GetLength()*GetWidth() + 2*GetLength()*GetHeight() + 2*GetWidth()*GetHeight()  - GetWWindow()*GetHWindow();
        std::cout << "value of box minus window= " << s << std::endl;
    }

};

int main() {
    Box b0;
    Box b1(11);
    Box b2(11,12);
    Box b3(10,10,10);
    Box b4(10,10,10);
    b3.area();
    Box bc = b3++;
    Box bc1 = b3+b4;
    b3.area();
    bc1.area();
    std::cout << "b3: " << bc1.GetWidth() << std::endl;
    std::cout << "bc: " << bc.GetWidth() << std::endl;
    bc.area();
    WBox wb(6,7);
    std::cout << "wb: " << wb.GetWWindow() << std::endl;
    wb.area();
    return 0;
}

