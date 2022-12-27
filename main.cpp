#include <iostream>
#include <stdexcept>
#define def_length 10
#define def_width 10
#define def_height 10
#define def_w_width 5
#define def_w_height 5
#define def_hbox_height 5


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
    Box(): Box(def_length){
        std::cout << "Three default Box parameters constructor" << std::endl;
    }

    /** one parameter */
    explicit Box(int x): Box(x, def_width){
        std::cout << "One manual Box parameter constructor" << std::endl;
    }

    /** two parameters */
    explicit Box(int x, int y): Box(x, y, def_height){
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
            setLength(def_length);
            setWidth(def_width);
            setHeight(def_height);
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
    explicit WBox(): WBox(def_w_width){
        std::cout << "Three default Box + two default WBox parameters constructor" << std::endl;
    }

    /** four parameters */
    explicit WBox(int _w_window): WBox(_w_window, def_w_height){
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
            setWWindow(def_w_width);
            setHWindow(def_w_height);
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
            setWWindow(def_w_width);
            setHWindow(def_w_height);
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
    HBox(): HBox(def_hbox_height){
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
            setHBoxHeight(def_hbox_height);
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
            setHBoxHeight(def_hbox_height);
        }
    }

    /** copy constructor */
    HBox(const HBox& ref): Box(ref){
        setHBoxHeight(ref.getHBoxHeight());
        std::cout << "HBox copy constructor initialized" << std::endl;
    }

    /** area of box method */
    void area() override {
        int s = 2*getLength()*getWidth() + 2*getLength()*getHeight() + 2*getWidth()*getHeight()
                + 2*getLength()*getHBoxHeight() + 2*getWidth()*getHBoxHeight();
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


/** ------------------------------------------------------------- */
/** class stack */
#define SIZE 10
template<typename T>
class Stack{
    T *arr;
    int top;
    int capacity;
public:
    Stack(int size = SIZE) {
        arr = new T[size];
        capacity = size;
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }

    void push(T f) {
        if (isFull()) {
            std::cout << "Stack is full\nTerminating program" << std::endl;
            exit(EXIT_FAILURE);
        }
        std::cout << "Adding " << top+1 << std::endl;
        arr[++top] = f;
    }

    T pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            exit(EXIT_FAILURE);
        }
        std::cout << "Removing " << top << std::endl;
        return arr[top--];
    }
    T peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        else {
            exit(EXIT_FAILURE);
        }
    }

    int size() const {
        return top + 1;
    }
    bool isEmpty() const {
        return top == -1;
    }
    bool isFull() const {
        return top == capacity - 1;
    }
};
/** ------------------------------------------------------------- */

int main() {
    /** testing Box */
    Box box(11);
    box.area();
    Box box2(11,12);
    box2.area();
    Box box3(10,10,10);
    box3.area();
    Box box4(11,12,13);
    box4.area();
    Box bplusAfter = box3++;
    bplusAfter.area();
    Box bcPlus = box3+box4;
    bcPlus.area();
    /** testing WBox */
    WBox wb(6,7);
    wb.area();
    /** testing HBox */
    HBox hBox;
    hBox.area();
    /** testing WHBox */
    WHBox whBox;
    whBox.area();
    WHBox whBox1(11,11,-11,6,6,7);
    whBox1.area();

    /** stack check*******************/
    /** double check */
    std::cout << "***** double check ****************************************************" << std::endl;
    Stack<double> box_stack_dbl;
    std::cout << "Empty check: " << box_stack_dbl.isEmpty() << std::endl;
//    std::cout << "Popped: " << box_stack_dbl.pop() << std::endl;
    box_stack_dbl.push(2.22);
    std::cout << "Full check: " << box_stack_dbl.isFull() << std::endl;
    std::cout << "Empty check: " << box_stack_dbl.isEmpty() << std::endl;
    std::cout << "Popped: " << box_stack_dbl.pop() << std::endl;
    /** int check */
    std::cout << "***** int check ****************************************************" << std::endl;
    Stack<int> box_stack_int;
    box_stack_int.push(2);
    box_stack_int.push(20);
    box_stack_int.push(202);
    /** string check */
    std::cout << "***** Box check ****************************************************" << std::endl;
    Stack<Box> vd(2);
    std::cout << "vd size: " << vd.size() << std::endl;
    vd.push(box);
    vd.peek();
    Box tbox = vd.pop();
    std::cout << "tbox area: ";
    tbox.area();

    return 0;
}

