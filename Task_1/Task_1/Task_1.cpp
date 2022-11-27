#include<iostream>

class Figure {
public:	
	Figure() {
		this->numSides_ = 0;
		this->name_ = "Фигура: ";
	}
	Figure(int sides, std::string name) {
		this->numSides_ = sides;
		this->name_ = name;
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
	Triangle (int sides, std::string name) : Figure(sides, name) { }
};
class Quadrangle : public Figure {
public:
	Quadrangle(int sides, std::string name) : Figure(sides, name) { }
};

int main(int argc, char** argv) {

	setlocale(LC_ALL, "ru");

	std::cout << "Количество сторон: " << std::endl;
	Figure figure;
	figure.Print();
	Triangle triangle(3, "Треугольник: ");
	triangle.Print();
	Quadrangle quadrangle(4, "Четырёхугольник: ");
	quadrangle.Print();

	return 0;
}