#include <iostream>

enum EColor {
    RED,
    GREEN,
    BLUE,
    YELLOW
};

std::string EColorToString(EColor color) {
    switch (color)
    {
    case EColor::RED:
        return "RED";
        break;
    case EColor::GREEN:
        return "GREEN";
        break;
    case EColor::BLUE:
        return "BLUE";
        break;
    case EColor::YELLOW:
        return "YELLOW";
        break;
    
    default:
        return "Cant find color";
        break;
    }
}

class Color {
public:
    EColor getColor() {
        return color;
    }
    void setColor(EColor clr) {
        color = clr;
    }
private:
    EColor color = EColor::GREEN;
};

class Shape {
public:
    Shape() {
        color = new Color;
    }
    ~Shape() {
        delete color;
    }

    virtual void draw() = 0;

protected:
    Color *color;
};

class Circle: public Shape {
public:
    Circle(EColor clr) : Shape(){
        color->setColor(clr);
    }

    void draw() override {
        std::cout << "Draw a Circle, color is - " << EColorToString(color->getColor()) << std::endl;
    }
};

class Triangle: public Shape {
public:
    Triangle(EColor clr) : Shape() {
        color->setColor(clr);
    }
    void draw() override {
        std::cout << "Draw a Triangle, color is - " << EColorToString(color->getColor()) << std::endl;
    }
};

int main () {

    Shape *obj1 = new Circle(EColor::GREEN);
    Shape *obj2 = new Triangle(EColor::RED);

    obj1->draw();
    obj2->draw();

    return 0;
}