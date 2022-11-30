#include <iostream>

class Triangle {
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
		std::cout << "Стороны: " << "a=" << GetSide_a() << " " << "b=" << GetSide_b() << " " << "c=" << GetSide_c() << std::endl;
		std::cout << "Углы: " << "A=" << GetCorner_A() << " " << "B=" << GetCorner_B() << " " << "C=" << GetCorner_C() << std::endl;
		std::cout << std::endl;
	}
	void Print(Triangle* triangle) {
		triangle->Print();
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
protected:
	
public:
	RightTr() {
		this->C_ = 90;
		this->name_ = "Прямоугольный треугольник: ";
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
};

class Quadrilateral {
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
	void Print(Quadrilateral* quadrilateral) {
		quadrilateral->Print();
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
};

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "ru");

	Triangle triangle;
	triangle.Print(&triangle);
	RightTr rightTr;
	triangle.Print(&rightTr);
	IsoscelesTr isosscelesTr;
	triangle.Print(&isosscelesTr);
	EquilateralTr equilateralTr;
	triangle.Print(&equilateralTr);
	

	Quadrilateral quadrilateral;
	quadrilateral.Print(&quadrilateral);
	Rectangle rectangle;
	quadrilateral.Print(&rectangle);
	Square square;
	quadrilateral.Print(&square);
	Parallelogram parallelogram;
	quadrilateral.Print(&parallelogram);
	Rhomb rhomb;
	quadrilateral.Print(&rhomb);
	return 0;
}