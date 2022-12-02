#include <iostream>

class Figure {
private:
	int sides_;
	std::string name_;
public:
	Figure() {
		this->sides_ = 0;
		this->name_ = "Фигура: ";
	}

	void Set_name(std::string name) {
		this->name_ = name;
	}
	void Set_sides(int sides) {
		this->sides_ = sides;
	}

	int GetSides() {
		return sides_;
	}
	std::string GetName() {
		return name_;
	}
	
	virtual bool check() {
		if (GetSides() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	virtual void Print() {
		std::cout << GetName() << std::endl;
		if (check()) { std::cout << "Правильная" << std::endl; }
		else { std::cout << "Неправильная" << std::endl; }
		std::cout << "Количество сторон: " << GetSides() << std::endl;
	}

protected:

};

class Triangle : public Figure {
private:
	int a_,
		b_,
		c_,
		A_,
		B_,
		C_;
public:
	Triangle(int a, int b, int c, int A, int B, int C) {
		this->a_ = a;
		this->b_ = b;
		this->c_ = c;
		this->A_ = A;
		this->B_ = B;
		this->C_ = C;
		Set_name("Треугольник: ");
		Set_sides(3);
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

	void Print() override {
		Figure::Print();
		std::cout << "Стороны: " << "a=" << Get_a() << " " << "b=" << Get_b() << " " << "c=" << Get_c() << std::endl;
		std::cout << "Углы: " << "A=" << Get_A() << " " << "B=" << Get_B() << " " << "C=" << Get_C() << std::endl;
		std::cout << std::endl;
	}
	bool check() override {
		if ((Get_A() + Get_B() + Get_C()) == 180) {
			return true;
		}
		else {
			return false;
		}
	}
};
class RightTr : public Triangle {
protected:

public:
	RightTr(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
		Set_name("Прямоугольный треугольник: ");
	}
	bool check() override {
		if (Triangle::check() && Get_C() == 90) {
			return true;
		}
		else {
			return false;
		}
	}
};
class IsoscelesTr : public Triangle {
public:
	IsoscelesTr(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A){
		Set_name("Равнобедренный треугольник: ");
	}
	bool check() override {
		if (Triangle::check() && (Get_a() == Get_c()) && (Get_A() == Get_C())) {
			return true;
		}
		else {
			return false;
		}
	}
};
class EquilateralTr : public Triangle {
public:
	EquilateralTr(int a) : Triangle(a, a, a, 60, 60, 60) {
		Set_name("Равносторонний треугольник: ");
	}
	bool check() override {
		if ((Get_A() == 60 && Get_B() == 60 && Get_C() == 60) && (Get_a() == Get_b()) && 
			(Get_a() == Get_c())) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Quadrilateral : public Figure {
private:
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
		Set_name("Четырёхугольник: ");
		Set_sides(4);
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
	
	void Print() override {
		Figure::Print();
		std::cout << "Стороны: " << "a=" << Get_a() << " " << "b=" << Get_b() << " " << "c=" << Get_c() << " " << "d=" << Get_d() << std::endl;
		std::cout << "Углы: " << "A=" << Get_A() << " " << "B=" << Get_B() << " " << "C=" << Get_C() << " " << "D=" << Get_D() << std::endl;
		std::cout << std::endl;
	}
	bool check() override {
		if ((Get_A() + Get_B() + Get_C() + Get_D() == 360) && GetSides() == 4) {
			return true;
		}
		else {
			return false;
		}
	}
};
class Parallelogram : public Quadrilateral {
public:
	Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, a, b, A, B, A, B) {
		Set_name("Параллелограмм: ");
	}
	bool check() override {
		if (Quadrilateral::check() && (Get_a() == Get_c()) && (Get_b() == Get_d()) &&
			(Get_A() == Get_C()) && (Get_B() == Get_D())) {
			return true;
		}
		else {
			return false;
		}
	}
};
class Rectangle : public Parallelogram {
public:
	Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) {
		Set_name("Прямоугольник: ");
	}
	bool check() override {
		if (Quadrilateral::check() && (Get_a() == Get_c()) && (Get_b() == Get_d()) &&
			(Get_A() == 90) && (Get_B() == 90) && (Get_C() == 90) && (Get_D() == 90)) {
			return true;
		}
		else {
			return false;
		}
	}
};
class Rhomb : public Parallelogram {
public:
	Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B) {
		Set_name("Ромб: ");
	}
	bool check() override {
		if (Quadrilateral::check() && (Get_a() == Get_b()) && (Get_b() == Get_c()) && (Get_c() == Get_d()) &&
			(Get_A() == Get_C()) && (Get_B() == Get_D())) {
			return true;
		}
		else {
			return false;
		}
	}
};
class Square : public Rectangle {
public:
	Square(int a) : Rectangle(a, a) {
		Set_name("Квадрат: ");
	}
	bool check() override {
		if ((Get_a() == Get_b()) && (Get_b() == Get_c()) && (Get_c() == Get_d()) &&
			(Get_A() == 90) && (Get_B() == 90) && (Get_C() == 90) && (Get_D() == 90)) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main(int argc, char** argv) {

	setlocale(LC_ALL, "ru");
	Figure figure;
	figure.Print();
	Triangle triangle(10,20,30,40,50,60);
	triangle.Print();
	RightTr rightTr(10, 40, 60, 40, 50);
	rightTr.Print();
	IsoscelesTr isosscelesTr(20, 30, 60, 70);
	isosscelesTr.Print();
	EquilateralTr equilateralTr(60);
	equilateralTr.Print();

	Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
	quadrilateral.Print();
	Rectangle rectangle(40, 60);
	rectangle.Print();
	Square square(50);
	square.Print();
	Parallelogram parallelogram(15, 25, 45, 65);
	parallelogram.Print();
	Rhomb rhomb(25, 95, 85);
	rhomb.Print();
	return 0;
}