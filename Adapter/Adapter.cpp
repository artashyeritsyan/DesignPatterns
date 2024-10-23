#include <iostream>

class LegacyRectangle {
public:
    int getArea() {
        return width * height;
    }

    void setWidth(int width) {
        this->width = width;
    }

    void setHeight(int height) {
        this->height = height;
    }

private:
    int width;
    int height;
};

class ModernRectangle {
public:
    virtual int calculateArea() = 0;
};

class RectangleAdapter : public ModernRectangle {
public:
    RectangleAdapter(int width, int height) {
        legacyRect.setWidth(width);
        legacyRect.setHeight(height);
    }

    int calculateArea() override {
        return legacyRect.getArea();
    }

private:
    LegacyRectangle legacyRect;
};

int main() {
    LegacyRectangle legacyRect;
    legacyRect.setWidth(5);
    legacyRect.setHeight(10);

    std::cout << "Legacy Rectangle Area: " << legacyRect.getArea() << std::endl;

    ModernRectangle* modernRect = new RectangleAdapter(3, 7);

    std::cout << "Modern Rectangle Area: " << modernRect->calculateArea() << std::endl;

    delete modernRect;

    return 0;
}