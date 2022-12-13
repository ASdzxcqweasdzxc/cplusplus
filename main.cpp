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
    Box(){
        setLength(10);
        setHeight(10);
        setWidth(10);
        std::cout << "Three default Box parameters constructor\n";
    };

    /** one parameter */
    explicit Box(int x){
        setLength(x);
        setHeight(10);
        setWidth(10);
        std::cout << "One manual Box parameters constructor\n";
    };

    /** two parameters */
    explicit Box(int x, int y){
        setLength(x);
        setHeight(y);
        setWidth(10);
        std::cout << "Two manual Box parameters constructor\n";
    };

    /** three parameters */
    explicit Box(int x, int y, int z){
        setLength(x);
        setWidth(y);
        setHeight(z);
        std::cout << "Three manual Box parameters constructor\n";
    }

    /** copy constructor */
    Box(const Box& ref){
        setLength(ref.GetLength());
        setHeight(ref.GetHeight());
        setWidth(ref.GetWidth());
        std::cout << "Copy constructor for Box class\n";
    }

    /** destructor */
    ~Box() {
        std::cout << "Box destructor initialized" << std::endl;
    }

    /** area of box method */
    void area() override {
        int s = GetLength()*GetWidth() + 2*GetLength()*GetHeight() + 2*GetWidth()*GetHeight();
        std::cout << "Box value= " << s << std::endl;
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
class WBox: virtual public Box{
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
        std::cout << "Three default Box + two default WBox parameters constructor\n";
    };

    /** four parameters */
    explicit WBox(int _w_window): Box(){
        setWWindow(_w_window);
        setHWindow(5);
        std::cout << "Three default Box + one manual WBox parameters constructor\n";
    }

    /** five parameters */
    explicit WBox(int _w_window, int _h_window): Box(){
        setWWindow(_w_window);
        setHWindow(_h_window);
        std::cout << "Three default Box + two manual WBox parameters constructor\n";
    }

    /** five parameters */
    explicit WBox(int _length, int _width, int _height, int _w_window, int _h_window): Box(_length, _width, _height){
        setWWindow(_w_window);
        setHWindow(_h_window);
        std::cout << "Three manual Box + two manual WBox parameters constructor\n";
    }

    /** copy constructor */
    WBox(const WBox& ref): Box(ref){
        setWWindow(ref.GetWWindow());
        setHWindow(ref.GetHWindow());
        std::cout << "Copy constructor for WBox class\n";
    }

    /** area of box method */
    void area() override {
        int s = GetLength()*GetWidth() + 2*GetLength()*GetHeight() + 2*GetWidth()*GetHeight()  - GetWWindow()*GetHWindow();
        std::cout << "WBox value minus window= " << s << std::endl;
    }
};

/** fifth part */
class HBox: virtual public Box{
    int h_height;
public:
    /** getters */
    int GetHBoxHeight() const { return h_height; }

    /** setters */
    void setHBoxHeight(int _h_height){
        h_height = _h_height;
    }

    /** default constructor */
    /** 'explicit' - got parameters with defaults and prevents converting types */
    HBox(): Box(){
        setHBoxHeight(5);
        std::cout << "Three default Box + one default HBox parameters constructor\n";
    };

    /** one parameter for HBox */
    explicit HBox(int _h_height): Box(){
        setHBoxHeight(_h_height);
        std::cout << "Three default Box + one manual HBox parameters constructor\n";
    }

    /** one parameter for HBox */
    explicit HBox(int _length, int _width, int _height, int _h_height): Box(_length, _width, _height){
        setHBoxHeight(_h_height);
        std::cout << "Three manual Box + one manual HBox parameters constructor\n";
    }

    /** copy constructor */
    HBox(const HBox& ref): Box(ref){
        setHBoxHeight(ref.GetHBoxHeight());
        std::cout << "Copy constructor for HBox class\n";
    }

    /** area of box method */
    void area() override {
        int s = 2*GetLength()*GetWidth() + 2*GetLength()*GetHeight() + 2*GetWidth()*GetHeight()
                + 2*GetLength()*GetHBoxHeight() + 2*GetWidth()*GetHBoxHeight();
        std::cout << "Box plus HBox value= " << s << std::endl;
    }

    /** destructor */
    ~HBox(){
        std::cout << "HBox destructor initialized" << std::endl;
    }
};

/** sixth part */
class WHBox: public WBox, public HBox{
public:
    /** default constructor */
    /** 'explicit' - got parameters with defaults and prevents converting types */
    WHBox(): Box(), WBox(), HBox(){
        std::cout << "Two default WBox + one default HBox parameters constructor\n";
    };

    /** five parameters for WHBox */
    WHBox(int _length, int _width, int _height, int _w_window, int _h_window, int _h_height):
        Box(_length, _width, _height),
        WBox(_w_window, _h_window),
        HBox(_h_height){
        std::cout << "Three manual Box + one manual HBox parameters constructor\n";
    }

    /** area of box method */
    void area() override {
        int s = 2*GetLength()*GetWidth() + 2*GetLength()*GetHeight() + 2*GetWidth()*GetHeight()
                + 2*GetLength()*GetHBoxHeight() + 2*GetWidth()*GetHBoxHeight() - GetWWindow()*GetHWindow();
        std::cout << "Box plus HBox and minus WBox value= " << s << std::endl;
    }
};

int main() {
    Box box;
    box.area();
    Box box1(11);
    box1.area();
    Box box2(11,12);
    box2.area();
    Box box3(10,10,10);
    box3.area();
    Box box4(10,10,10);
    box4.area();
    Box bc = box3++;
    bc.area();
    Box bc1 = box3+box4;
    bc1.area();
//    std::cout << "b3: " << bc1.GetWidth() << std::endl;
//    std::cout << "bc: " << bc.GetWidth() << std::endl;
    WBox wb(6,7);
//    std::cout << "wb: " << wb.GetWWindow() << std::endl;
    wb.area();
    HBox hBox;
    hBox.area();
    WHBox whBox;
    whBox.area();
    WHBox whBox1(11,11,11,6,6,7);
    whBox1.area();
    return 0;
}

