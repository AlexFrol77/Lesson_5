#include <iostream>

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
	void Print(Figure* figure) {
		figure->Print();
	}
protected:
	int numSides_;
	std::string name_;
};

class Triangle : public Figure {
private:

public:
	Triangle() {
		this->a_ = 10;
		this->b_ = 20;
		this->c_ = 30;
		this->A_ = 50;
		this->B_ = 60;
		this->C_ = 70;
		this->name_ = "Треугольник: ";
		this->numSides_ = 3;
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
	int GetSides() {
		return numSides_;
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

protected:
	
	int a_,
		b_,
		c_,
		A_,
		B_,
		C_;
};
class RightTr : public Triangle {
protected:

public:
	RightTr() {
		this->C_ = 90;
		this->name_ = "Прямоугольный треугольник: ";
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
	IsoscelesTr() {
		this->a_ = 10;
		this->c_ = a_;
		this->A_ = 50;
		this->C_ = A_;
		this->name_ = "Равнобедренный треугольник: ";
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
	EquilateralTr() {
		this->a_ = 30;
		this->b_ = a_;
		this->c_ = a_;
		this->A_ = 60;
		this->B_ = A_;
		this->C_ = A_;
		this->name_ = "Равносторонний треугольник: ";
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
public:
	Quadrilateral() {
		this->a_ = 10;
		this->b_ = 20;
		this->c_ = 30;
		this->d_ = 40;
		this->A_ = 50;
		this->B_ = 60;
		this->C_ = 70;
		this->D_ = 80;
		this->name_ = "Четырёхугольник: ";
		this->numSides_ = 4;
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
class Parallelogram : public Quadrilateral {
public:
	Parallelogram() {
		this->a_ = 20;
		this->b_ = 30;
		this->c_ = a_;
		this->d_ = b_;
		this->A_ = 30;
		this->B_ = 40;
		this->C_ = A_;
		this->D_ = B_;
		this->name_ = "Параллелограмм: ";
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
	Rectangle() {
		this->A_ = 90;
		this->B_ = A_;
		this->C_ = A_;
		this->D_ = A_;
		this->name_ = "Прямоугольник: ";
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
	Rhomb() {
		this->a_ = 30;
		this->b_ = a_;
		this->c_ = a_;
		this->d_ = a_;
		this->name_ = "Ромб: ";
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
	Square() {
		this->a_ = 20;
		this->b_ = a_;
		this->c_ = a_;
		this->d_ = a_;
		this->name_ = "Квадрат: ";
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
	figure.Print(&figure);
	Triangle triangle;
	figure.Print(&triangle);
	RightTr rightTr;
	figure.Print(&rightTr);
	IsoscelesTr isosscelesTr;
	figure.Print(&isosscelesTr);
	EquilateralTr equilateralTr;
	figure.Print(&equilateralTr);


	Quadrilateral quadrilateral;
	figure.Print(&quadrilateral);
	Rectangle rectangle;
	figure.Print(&rectangle);
	Square square;
	figure.Print(&square);
	Parallelogram parallelogram;
	figure.Print(&parallelogram);
	Rhomb rhomb;
	figure.Print(&rhomb);
	return 0;
}