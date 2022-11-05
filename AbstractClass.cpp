#include <iostream>
using namespace std;

//Шупик Карина

//202ТН

/*1. Визначте абстрактний клас трикутників і дві його реалізації: за трьома вершинами і за трьома сторонами.
2. Доповніть клас трикутників конструктором за основами його трьох
медіан. Реалізуйте метод обчислення довільної медіани трикутника.
3. За довільною стороною трикутника знайдіть паралельну їй середню
лінію.
4. Визначте ієрархію трикутник-прямокутний трикутник. Реалізуйте
функції обчислення довжин радіусів вписаного і описаного кіл.*/

class Triangle {
protected:
	float firstSide, secondSide, thirdSide;	//	Сторони трикутника
	float firstSideX, firstSideY, secondSideX, secondSideY, thirdSideX, thirdSideY;	//	Координати вершин трикутника
public:

	Triangle() {	//	Конструктор за замовченням
		firstSide = 0;
		secondSide = 0;
		thirdSide = 0;
		firstSideX = 0;
		firstSideY = 0;
		secondSideX = 0;
		secondSideY = 0;
		thirdSideX = 0;
		thirdSideY = 0;
	}

	virtual void showData() = 0;
	virtual void calcData() = 0;	//	Розрахунки в трикутниках
};

class TriangleTop : public Triangle {
public:

	TriangleTop() {	//	Конструктор за замовчуванням
		firstSideX = 0;
		firstSideY = 0;
		secondSideX = 0;
		secondSideY = 0;
		thirdSideX = 0;
		thirdSideY = 0;
	}

	void showData() {
		cout << "Enter coordinates of triangle`s apex: " << endl;//вводимо координати вершин трикутника
		cout << "A.x: ";
		cin >> firstSideX;
		cout << "A.y: ";
		cin >> firstSideY;
		cout << "B.x: ";
		cin >> secondSideX;
		cout << "B.y: ";
		cin >> secondSideY;
		cout << "C.x: ";
		cin >> thirdSideX;
		cout << "C.y: ";
		cin >> thirdSideY;
	}

	void calcData() {
		firstSide = sqrt(pow((secondSideX - firstSideX), 2) + pow((secondSideY - firstSideY), 2));//AB - знаходимо довжини 3 сторін трикутника за вказаними координатами
		secondSide = sqrt(pow((thirdSideX - secondSideX), 2) + pow((thirdSideY - secondSideY), 2));//BC
		thirdSide = sqrt(pow((thirdSideX - firstSideX), 2) + pow((thirdSideY - firstSideY), 2));//AC

		if (firstSide <= 0) {
			cout << "AB side " << firstSide << "doesn`t exist!" << endl;//якщо сторона дорівнює або менша 0, то вона не існує
		}
		else if (secondSide <= 0) {
			cout << "BC side " << secondSide << "doesn`t exist!" << endl;
		}
		else if (thirdSide <= 0) {
            cout << "AC side " << thirdSide << "doesn`t exist!" << endl;
		}
		else if (firstSide < secondSide + thirdSide && thirdSide < firstSide + secondSide && secondSide < firstSide + thirdSide) {//перевіряємо умову існування трикутника
			
			cout << "AB side: " << firstSide << " cm" << endl;
			cout << "BC side: " << secondSide << " cm" << endl;
			cout << "AC side: " << thirdSide << " cm" << endl;

			cout << "Middle line of triangle equal to KR (paralel to third side): " << thirdSide / 2 << " cm" << endl;//середня лінія трикутника
			cout << "Median AD (first apex to second side): " << sqrt(2 * (pow(thirdSide, 2) + pow(firstSide, 2)) - pow(secondSide, 2)) / 2 << " cm" << endl;//медіана трикутника AD (проведена з вершини А до сторони ВС)
		}
		else {
			cout << "Triangle doesn`t exist!" << endl;
		}
	}
};

class TriangleSides : public Triangle {
public:

	TriangleSides() {	//Конструктор за замовчуванням
		firstSide = 0;
		secondSide = 0;
		thirdSide = 0;
	}

	void showData() {
		cout << "Enter triangle`s sides: " << endl;//вводимо сторони трикутника
		cout << "AB side: ";
		cin >> firstSide;
		cout << "BC side: ";
		cin >> secondSide;
		cout << "AC side: ";
		cin >> thirdSide;
		cout << endl;
	}

	void calcData() {
		if (firstSide < secondSide + thirdSide && secondSide < thirdSide + firstSide && thirdSide < firstSide + secondSide) {//перевіряємо умову існування трикутника
			cout << "Middle line of triangle equal to KR (paralel to third side): " << thirdSide / 2 << " cm" << endl;//середня лінія трикутника
			cout << "Median BK (second apex to third side): " << sqrt(2 * (pow(secondSide, 2) + pow(firstSide, 2)) - pow(thirdSide, 2))/2 << " cm" << endl;//медіана трикутника BK (проведена з вершини B до сторони AС)
		}
		else {
			cout << "Triangle doesn`t exist!" << endl;
		}
	}
};

class RightAngledTriangle : public Triangle {//Прямокутний трикутник
	float R, r;	//Довжини вписаного та описаного радіусів прямокутного трикутника
public:

	RightAngledTriangle() {	//	Конструктор за замовченням
		firstSide = 0;
		secondSide = 0;
		thirdSide = 0;
		R = 0;
		r = 0;
	}

	void showData() {
		cout << "Enter triangle`s katets: " << endl;
		cout << "AB side: ";
		cin >> firstSide;
		cout << "BC side: ";
		cin >> secondSide;
		cout << "AC side: ";
		cin >> thirdSide;
		cout << endl;
	}

	void calcData() {
		if (firstSide < secondSide + thirdSide && secondSide < thirdSide + firstSide && thirdSide < firstSide + secondSide) {//перевіряємо умову існування трикутника
			if (secondSide == sqrt(pow(firstSide, 2) + pow(thirdSide, 2))) {//знаходимо серед введених сторін тр. гіпотенузу шляхом перевірки всіх трьох сторін за теоремою Піфагора
				cout << "Hypotenuse of second side BC equal to: " << secondSide << " cm" << endl;
				R = secondSide / 2;
				r = (firstSide + thirdSide - secondSide) / 2;
				cout << "Radius of outside circle R equal to: " << R << " cm" << endl;//радіус описаного кола
				cout << "Radius of inside circle r equal to: " << r << " сm" << endl;//радіус вписаного кола
			}
			else if (firstSide == sqrt(pow(thirdSide, 2) + pow(secondSide, 2))) {
				cout << "Hypotenuse of first side AB equal to: " << firstSide << " cm" << endl;
				R = firstSide / 2;
				r = (thirdSide + secondSide - firstSide) / 2;
				cout << "Radius of outside circle R equal to: " << R << " cm" << endl;
				cout << "Radius of inside circle r equal to: " << r << " сm" << endl;
			}
			else if (thirdSide == sqrt(pow(firstSide, 2) + pow(secondSide, 2))) {
				cout << "Hypotenuse of third side AC equal to: " << thirdSide << " cm" << endl;
				R = thirdSide / 2;
				r = (firstSide + secondSide - thirdSide) / 2;
				cout << "Radius of outside circle R equal to: " << R << " cm" << endl;
				cout << "Radius of inside circle r equal to: " << r << " сm" << endl;
			}
			else
				cout << "Triangle isn`t right-angled!" << endl;
		}
		else
			cout << "Triangle doesn`t exist!" << endl;
	}
};

int main()
{
	Triangle* apex = new TriangleTop();
	apex->showData();
	apex->calcData();

	Triangle* sides = new TriangleSides();
	sides->showData();
	sides->calcData();

	Triangle* rightTrian = new RightAngledTriangle();
	rightTrian->showData();
	rightTrian->calcData();

	return 0;
}
