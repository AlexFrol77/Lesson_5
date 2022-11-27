#include <iostream>

class Triangle {
private:

public:
	Triangle(int a, int b, int c, int A, int B, int C) {
		this->a_ = a;
		this->b_ = b;
		this->c_ = c;
		this->A_ = A;
		this->B_ = B;
		this->C_ = C;
		this->name_ = "Треугольник: ";
	}
	Triangle(int a, int b, int c, int A, int B) {
		this->a_ = a;
		this->b_ = b;
		this->c_ = c;
		this->A_ = A;
		this->B_ = B;
		this->C_ = 90;
		this->name_ = "Прямоугольный треугольник: ";
	}
	Triangle(int a, int b, int A, int B) {
		this->a_ = a;
		this->b_ = b;
		this->c_ = a;
		this->A_ = A;
		this->B_ = B;
		this->C_ = A;
		this->name_ = "Равнобедренный треугольник: ";
	}
	Triangle(int a) {
		this->a_ = a;
		this->b_ = a;
		this->c_ = a;
		this->A_ = 60;
		this->B_ = 60;
		this->C_ = 60;
		this->name_ = "Равносторонний треугольник: ";
	}
	int GetSide_a() {
		return a_;
	}
	int GetSide_b() {
		return b_;
	}
	int GetSide_c() {
		return c_;
	}
	int GetCorner_A() {
		return A_;
	}
	int GetCorner_B() {
		return B_;
	}
	int GetCorner_C() {
		return C_;
	}
	std::string GetName() {
		return name_;
	}
	void Print() {
		std::cout << GetName() << std::endl;
		std::cout << "Стороны: " <<  "a=" << GetSide_a() << " " << "b=" << GetSide_b() << " " << "c=" << GetSide_c() << std::endl;
		std::cout << "Углы: " << "A=" << GetCorner_A() << " " << "B=" << GetCorner_B() << " " << "C=" << GetCorner_C() << std::endl;
		std::cout << std::endl;
	}

protected:
	std::string name_;
	int a_,
		b_,
		c_,
		A_,
		B_,
		C_;
};
class RightTr : public Triangle {
public:
	RightTr(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B) { }
};
class IsoscelesTr : public Triangle {
public:
	IsoscelesTr(int a, int b, int A, int B) : Triangle(a, b, A, B) { }
};
class EquilateralTr : public Triangle {
public:
	EquilateralTr(int a) : Triangle(a) { }
};
class Quadrilateral {
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
		this->name_ = "Ромб: ";
	}
	int Get_a() {
		return a_;
	}
	int Get_b() {
		return b_;
	}
	int Get_c() {
		return c_;
	}
	int Get_d() {
		return d_;
	}
	int Get_A() {
		return A_;
	}
	int Get_B() {
		return B_;
	}
	int Get_C() {
		return C_;
	}
	int Get_D() {
		return D_;
	}
	std::string Get_name() {
		return name_;
	}
	void Print() {
		std::cout << Get_name() << std::endl;
		std::cout << "Стороны: " << "a=" << Get_a() << " " << "b=" << Get_b() << " " << "c=" << Get_c() << " " << "d=" << Get_d() << std::endl;
		std::cout << "Углы: " << "A=" << Get_A() << " " << "B=" << Get_B() << " " << "C=" << Get_C() << " " << "D=" << Get_D() << std::endl;
		std::cout << std::endl;
	}
protected:
	std::string name_;
	int a_,
		b_,
		c_,
		d_,
		A_,
		B_,
		C_,
		D_;
};
class Rectangle : public Quadrilateral {
public:
	Rectangle(int a, int b) : Quadrilateral(a, b) { }
};
class Square : public Quadrilateral {
public:
	Square(int a) : Quadrilateral(a) { }
};
class Parallelogram : public Quadrilateral {
public:
	Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, A, B) { }
};
class Rhomb : public Quadrilateral {
public:
	Rhomb(int a, int A, int B) : Quadrilateral (a, A, B) { }
};
int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "ru");

	Triangle triangle(10, 20, 30, 50, 60, 70);
	triangle.Print();
	RightTr rightTr(10, 20, 30, 50, 60);
	rightTr.Print();
	IsoscelesTr isosscelesTr(10, 20, 50, 60);
	isosscelesTr.Print();
	EquilateralTr equilateralTr(30);
	equilateralTr.Print();
	

	Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
	quadrilateral.Print();
	Rectangle rectangle(10,20);
	rectangle.Print();
	Square square(20);
	square.Print();
	Parallelogram parallelogram(20, 30, 30, 40);
	parallelogram.Print();
	Rhomb rhomb(30, 30, 40);
	rhomb.Print();
	return 0;
}