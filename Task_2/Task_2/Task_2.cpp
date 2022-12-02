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
	
	void Set_name(std::string name) {
		name_ = name;
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
	int Get_A() {
		return A_;
	}
	int Get_B() {
		return B_;
	}
	int Get_C() {
		return C_;
	}
	std::string GetName() {
		return name_;
	}

	void Print() {
		std::cout << GetName() << std::endl;
		std::cout << "Стороны: " << "a=" << Get_a() << " " << "b=" << Get_b() << " " << "c=" << Get_c() << std::endl;
		std::cout << "Углы: " << "A=" << Get_A() << " " << "B=" << Get_B() << " " << "C=" << Get_C() << std::endl;
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
	RightTr(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
		Set_name("Прямоугольный треугольник: ");
	}
};
class IsoscelesTr : public Triangle {
public:
	IsoscelesTr(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
		Set_name("Равнобедренный треугольник: ");
	}
};
class EquilateralTr : public Triangle {
public:
	EquilateralTr(int a) : Triangle(a, a, a, 60, 60, 60) {
		Set_name("Равносторонний треугольник: ");
	}
};

class Quadrilateral {
private:
	std::string name_;
	int a_,
		b_,
		c_,
		d_,
		A_,
		B_,
		C_,
		D_;
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
	void Set_name(std::string name) {
		name_ = name;
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
};
class Parallelogram : public Quadrilateral {
public:
	Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, a, b, A, B, A, B) {
		Set_name("Параллелограмм: ");
	}
};
class Rectangle : public Parallelogram {
public:
	Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) {
		Set_name("Прямоугольник: ");
	}
};
class Rhomb : public Parallelogram {
public:
	Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B) {
		Set_name("Ромб: ");
	}
};
class Square : public Rectangle {
public:
	Square(int a) : Rectangle(a, a) {
		Set_name("Квадрат: ");
	}
};

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "ru");

	Triangle triangle(10, 20, 30, 40, 50, 60);
	triangle.Print();
	RightTr rightTr(10, 20, 30, 50, 70);
	rightTr.Print();
	IsoscelesTr isosscelesTr(10, 20, 50, 70);
	isosscelesTr.Print();
	EquilateralTr equilateralTr(34);
	equilateralTr.Print();
	
	Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
	quadrilateral.Print();
	Rectangle rectangle(35, 45);
	rectangle.Print();
	Square square(97);
	square.Print();
	Parallelogram parallelogram(100, 200, 50, 60);
	parallelogram.Print();
	Rhomb rhomb(102, 95, 93);
	rhomb.Print();
	
	return 0;

}