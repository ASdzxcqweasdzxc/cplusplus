#include <iostream>
#include <stdexcept>

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
    int getLength() const { return length; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    /** setters */
    void setLength(int l){
        if (l > 0) {
            length = l;
        } else {
            throw std::invalid_argument("EXCEPTION: Box length must be positive!");
        }
    }

    void setWidth(int w){
        if (w > 0) {
            width = w;
        } else {
            throw std::invalid_argument("EXCEPTION: Box width must be positive!");
        }
    }

    void setHeight(int h){
        if (h > 0) {
            height = h;
        } else {
            throw std::invalid_argument("EXCEPTION: Box height must be positive!");
        }
    }

    /** default constructor */
    /** 'explicit' - got parameters with defaults and prevents converting types */
    Box(): Box(10){
        std::cout << "Three default Box parameters constructor" << std::endl;
    }

    /** one parameter */
    explicit Box(int x): Box(x, 10){
        std::cout << "One manual Box parameter constructor" << std::endl;
    }

    /** two parameters */
    explicit Box(int x, int y): Box(x, y, 10){
        std::cout << "Two manual Box parameters constructor" << std::endl;
    }

    /** three parameters */
    explicit Box(int x, int y, int z) {
        try {
            setLength(x);
            setWidth(y);
            setHeight(z);
            std::cout << "Three manual Box parameters constructor" << std::endl;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            std::cout << "Box default parameters created" << std::endl;

            // default parameters set here
            setLength(10);
            setWidth(10);
            setHeight(10);
        }
    }

    /** copy constructor */
    Box(const Box& ref){
        setLength(ref.getLength());
        setHeight(ref.getHeight());
        setWidth(ref.getWidth());
        std::cout << "Copy constructor for Box class" << std::endl;
    }

    /** destructor */
    ~Box() {
        std::cout << "Box destructor initialized" << std::endl;
    }

    /** area of box method */
    void area() override {
        int s = getLength()*getWidth() + 2*getLength()*getHeight() + 2*getWidth()*getHeight();
        std::cout << "Box value= " << s << std::endl;
    }

    /** second part */
    /** overload '=' */
    Box& operator= (const Box& x){
        Box res(width = x.width, height = x.height, length = x.length);
        return *this;
    }

    /** overload '++x' */
    Box& operator++ (){
        ++width; ++height; ++length;
        return *this;
    }

    /** overload 'x++' */
    Box operator++ (int){
        Box temp = *this;
        ++*this;
        return temp;
    }

    /** overload '--x' */
    Box& operator-- (){
        --width; --height; --length;
        return *this;
    }

    /** overload '--x' */
    Box operator-- (int){
        Box temp = *this;
        --*this;
        return temp;
    }

    /** introducing friend */
    friend Box operator+ (Box op1, Box op2);

};

/** '+' func overload */
Box operator+ (Box op1, Box op2){
    Box temp;
    temp.setLength(op1.getLength() + op2.getLength());
    temp.setWidth(op1.getWidth() + op2.getWidth());
    temp.setHeight(op1.getHeight() + op2.getHeight());
    return temp;
}

/** forth part */
class WBox: virtual public Box{
    int w_window, h_window;
public:
    /** getters */
    int getWWindow() const { return w_window; }
    int getHWindow() const { return h_window; }

    /** setters */
    void setWWindow(int _w_window){
        if (_w_window > 0 && _w_window < Box::getWidth()) {
            w_window = _w_window;
        } else {
            throw std::invalid_argument("EXCEPTION: window width can be only positive and less than Box.width");
        }
    }

    void setHWindow(int _h_window){
        if (_h_window > 0 && _h_window < Box::getHeight()) {
            h_window = _h_window;
        } else {
            throw std::invalid_argument("EXCEPTION: window height can be only positive and less than Box.height");
        }
    }

    /** default constructor */
    /** 'explicit' - got parameters with defaults and prevents converting types */
    explicit WBox(): WBox(5){
        std::cout << "Three default Box + two default WBox parameters constructor" << std::endl;
    }

    /** four parameters */
    explicit WBox(int _w_window): WBox(_w_window, 5){
        std::cout << "Three default Box + one manual WBox parameters constructor" << std::endl;
    }

    /** five parameters */
    explicit WBox(int _w_window, int _h_window): Box(){
        try {
            setWWindow(_w_window);
            setHWindow(_h_window);
            std::cout << "Default Box + two manual WBox parameters constructor" << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            std::cout << "Three default Box + two manual WBox parameters constructor" << std::endl;

            // set defaults
            setWWindow(5);
            setHWindow(5);
        }
    }

    /** five parameters */
    explicit WBox(int _length, int _width, int _height, int _w_window, int _h_window): Box(_length, _width, _height){
        try {
            setWWindow(_w_window);
            setHWindow(_h_window);
            std::cout << "Three manual Box + two manual WBox parameters constructor" << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            std::cout << "Default Box + default WBox parameters constructor" << std::endl;

            // WBox defaults
            setWWindow(5);
            setHWindow(5);
        }
    }

    /** copy constructor */
    WBox(const WBox& ref): Box(ref){
        setWWindow(ref.getWWindow());
        setHWindow(ref.getHWindow());
        std::cout << "WBox copy constructor initialized" << std::endl;
    }

    /** area of box method */
    void area() override {
        int s = getLength()*getWidth() + 2*getLength()*getHeight() + 2*getWidth()*getHeight() -
                getWWindow()*getHWindow();
        std::cout << "WBox value minus window= " << s << std::endl;
    }
};

/** fifth part */
class HBox: virtual public Box{
    int h_height;
public:
    /** getters */
    int getHBoxHeight() const { return h_height; }

    /** setters */
    void setHBoxHeight(int _h_height) {
        if (_h_height > 0) {
            h_height = _h_height;
        } else {
            throw std::invalid_argument("EXCEPTION: HBox height must be positive!");
        }
    }

    /** default constructor */
    /** 'explicit' - got parameters with defaults and prevents converting types */
    HBox(): HBox(5){
        std::cout << "Three default Box + one default HBox parameters constructor" << std::endl;
    };

    /** one parameter for HBox */
    explicit HBox(int _h_height): Box(){
        try {
            setHBoxHeight(_h_height);
            std::cout << "Three default Box + one manual HBox parameters constructor" << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            std::cout << "Default Box + default HBox parameters constructor" << std::endl;

            // HBox defaults
            setHBoxHeight(5);
        }
    }

    /** one parameter for HBox */
    explicit HBox(int _length, int _width, int _height, int _h_height): Box(_length, _width, _height){
        try {
            setHBoxHeight(_h_height);
            std::cout << "Three manual Box + one manual HBox parameters constructor" << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            std::cout << "Default Box + default HBox parameters constructor" << std::endl;

            // HBox default
            setHBoxHeight(5);
        }
    }

    /** copy constructor */
    HBox(const HBox& ref): Box(ref){
        setHBoxHeight(ref.getHBoxHeight());
        std::cout << "HBox copy constructor initialized" << std::endl;
    }

    /** area of box method */
    void area() override {
        int s = 2 * getLength() * getWidth() + 2 * getLength() * getHeight() + 2 * getWidth() * getHeight()
                + 2 * getLength() * getHBoxHeight() + 2 * getWidth() * getHBoxHeight();
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
        std::cout << "Default Box, WBox and HBox parameters constructor" << std::endl;
    };

    /** six parameters for WHBox */
    WHBox(int _length, int _width, int _height, int _w_window, int _h_window, int _h_height):
        Box(_length, _width, _height),
        WBox(_w_window, _h_window),
        HBox(_h_height){
        std::cout << "Manual Box, WBox and HBox parameters constructor" << std::endl;
    }

    /** area of box method */
    void area() override {
        int s = 2*getLength()*getWidth() + 2*getLength()*getHeight() + 2*getWidth()*getHeight()
                + 2*getLength()*getHBoxHeight() + 2*getWidth()*getHBoxHeight() - getWWindow()*getHWindow();
        std::cout << "Box plus HBox and minus WBox value= " << s << std::endl;
    }
};

int main() {
    Box box(-1);
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
//    std::cout << "b3: " << bc1.getWidth() << std::endl;
//    std::cout << "bc: " << bc.getWidth() << std::endl;
    WBox wb(6,7);
//    std::cout << "wb: " << wb.getWWindow() << std::endl;
    wb.area();
    HBox hBox;
    hBox.area();
    WHBox whBox;
    whBox.area();
    WHBox whBox1(11,11,-11,6,6,7);
    whBox1.area();
    return 0;
}

