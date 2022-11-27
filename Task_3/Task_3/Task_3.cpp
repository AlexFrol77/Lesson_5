#include<iostream>

class Figure {
public:
	Figure() {
		this->sides_ = 0;
		this->name_ = "Фигура: ";
	}
	virtual bool check() {
		if (sides_ == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	virtual void Print() {
		std::cout << name_ << std::endl;
		if (check()) {
			std::cout << "Правильная" << std::endl;
		}
		else {
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << sides_ << std::endl;
	}
private:

protected:
	int sides_;
	std::string name_;
};
class Triangle : public Figure {
public:
	Triangle(int a, int b, int c, int A, int B, int C) {
		this->a_ = a;
		this->b_ = b;
		this->c_ = c;
		this->A_ = A;
		this->B_ = B;
		this->C_ = C;
		this->sides_ = 3;
		this->name_ = "Треугольник: ";
	}
	Triangle(int a, int b, int c, int A, int B) {
		this->a_ = a;
		this->b_ = b;
		this->c_ = c;
		this->A_ = A;
		this->B_ = B;
		this->C_ = 90;
		this->sides_ = 3;
		this->name_ = "Прямоугольный треугольник: ";
	}
	Triangle(int a, int b, int A, int B) {
		this->a_ = a;
		this->b_ = b;
		this->c_ = a;
		this->A_ = A;
		this->B_ = B;
		this->C_ = A;
		this->sides_ = 3;
		this->name_ = "Равнобедренный треугольник: ";
	}
	Triangle(int a) {
		this->a_ = a;
		this->b_ = a;
		this->c_ = a;
		this->A_ = 60;
		this->B_ = 60;
		this->C_ = 60;
		this->sides_ = 3;
		this->name_ = "Равносторонний треугольник: ";
	}
	bool check() override {
		if ((A_ + B_ + C_) == 180) {
			return true;
		}
		else {
			return false;

		}
	}
	void Print() override {
		Figure::Print();
		std::cout << "Стороны: " << " a = " << a_ << " b = " << b_ << " c = " << c_ << std::endl;
		std::cout << "Углы: " << " A = " << A_ << " B = " << B_ << " C = " << C_ << std::endl;
		std::cout << std::endl;
	}
protected:
	int a_,
		b_,
		c_,
		A_,
		B_,
		C_;
};
class RectangularTr : public Triangle {                    // Прямоугольный треугольник
public:
	RectangularTr(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B) {}
};
class IsoscelesTr : public Triangle {					   // Равнобедренный
public:
	IsoscelesTr(int a, int b, int A, int B) : Triangle(a, b, A, B) {}
};
class EquilateralTr : public Triangle {                    // Равносторонний треугольник
public:
	EquilateralTr(int a) : Triangle(a) {}
};

class Quadrilateral : public Figure {											// Четырёхугольник
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) {
		this->a_ = a;
		this->b_ = b;
		this->c_ = c;
		this->d_ = d;
		this->A_ = A;
		this->B_ = B;
		this->C_ = C;
		this->D_ = D;
		this->sides_ = 4;
		this->name_ = "Четырёхугольник: ";
	}
	Quadrilateral(int a, int b) {
		this->a_ = a;
		this->b_ = b;
		this->c_ = a;
		this->d_ = b;
		this->A_ = 90;
		this->B_ = 90;
		this->C_ = 90;
		this->D_ = 90;
		this->sides_ = 4;
		this->name_ = "Прямоугольник: ";
	}
	Quadrilateral(int a) {
		this->a_ = a;
		this->b_ = a;
		this->c_ = a;
		this->d_ = a;
		this->A_ = 90;
		this->B_ = 90;
		this->C_ = 90;
		this->D_ = 90;
		this->sides_ = 4;
		this->name_ = "Квадрат: ";
	}
	Quadrilateral(int a, int b, int A, int B) {
		this->a_ = a;
		this->b_ = b;
		this->c_ = a;
		this->d_ = b;
		this->A_ = A;
		this->B_ = B;
		this->C_ = A;
		this->D_ = B;
		this->sides_ = 4;
		this->name_ = "Параллелограмм: ";
	}
	Quadrilateral(int a, int A, int B) {
		this->a_ = a;
		this->b_ = a;
		this->c_ = a;
		this->d_ = a;
		this->A_ = A;
		this->B_ = B;
		this->C_ = A;
		this->D_ = B;
		this->sides_ = 4;
		this->name_ = "Ромб: ";
	}
	bool check() override {
		if ((A_ + B_ + C_ + D_) == 360) {
			return true;
		}
		else {
			return false;
		}
	}
	void Print() override {
		Figure::Print();
		std::cout << "Стороны: " << " a = " << a_ << " b = " << b_ << " c = " << c_ << " d = " << d_ << std::endl;
		std::cout << "Углы: " << " A = " << A_ << " B = " << B_ << " C = " << C_ << " D = " << D_ << std::endl;
		std::cout << std::endl;
	}
protected:
	int a_,
		b_,
		c_,
		d_,
		A_,
		B_,
		C_,
		D_;
};
class Rectangle : public Quadrilateral {									// Прямоугольник
public:
	Rectangle(int a, int b) : Quadrilateral(a, b) { }
};
class Square : public Quadrilateral {										// Квадрат
public:
	Square(int a) : Quadrilateral(a) { }
};
class Parallelogram : public Quadrilateral {								// Параллелограмм
public:
	Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, A, B) { }
};
class Rhomb : public Quadrilateral {										// Ромб
public:
	Rhomb(int a, int A, int B) : Quadrilateral(a, A, B) { }
};

int main(int argc, char** argv) {

	setlocale(LC_ALL, "ru");

	Figure figure;
	figure.Print();

	Triangle triangle(10, 20, 30, 40, 50, 60);						// Треугольник
	triangle.Print();
	RectangularTr rectangularTr(10, 20, 30, 50, 40);				// Прямоугольный треугольник
	rectangularTr.Print();
	IsoscelesTr isoscelesTr(10, 20, 50, 60);						// Равнобедренный треугольник
	isoscelesTr.Print();
	EquilateralTr equilateralTr(30);								// Равносторонний треугольник
	equilateralTr.Print();

	Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);    // Четырёхугольник
	quadrilateral.Print();
	Rectangle rectangle(10, 20);									// Прямоугольник
	rectangle.Print();
	Square square(20);												// Квадрат
	square.Print();
	Parallelogram parallelogram(20, 30, 30, 40);					// Параллелограмм
	parallelogram.Print();
	Rhomb rhomb(30, 30, 40);										// Ромб
	rhomb.Print();
	return 0;
}