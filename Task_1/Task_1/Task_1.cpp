#include<iostream>

class Figure {
public:		
	Figure() {
		this->numSides_ = 0;
		this->name_ = "Фигура: ";
	}

	int GetSides() {
		return numSides_;
	}
	std::string GetName() {
		return name_;
	}

	void Print() {
		std::cout << GetName() << " " << GetSides() << std::endl;
	}

protected:
	int numSides_;
	std::string name_;
};
class Triangle : public Figure {
public:
	Triangle() {
		this->numSides_ = 3;
		this->name_ = "Треугольник: ";
	}
};
class Quadrangle : public Figure {
public:
	Quadrangle() {
		this->numSides_ = 4;
		this->name_ = "Четырёхугольник: ";
	}
};

int main(int argc, char** argv) {

	setlocale(LC_ALL, "ru");

	std::cout << "Количество сторон: " << std::endl;

	Figure figure;
	Triangle triangle;
	Quadrangle quadrangle;

	figure.Print();
	triangle.Print();
	quadrangle.Print();

	return 0;
}