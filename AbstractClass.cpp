#include <iostream>
using namespace std;

//����� ������

//202��

/*1. �������� ����������� ���� ���������� � �� ���� ���������: �� ������ ��������� � �� ������ ���������.
2. �������� ���� ���������� ������������� �� �������� ���� �����
�����. ��������� ����� ���������� ������� ������ ����������.
3. �� �������� �������� ���������� ������� ���������� �� �������
���.
4. �������� �������� ���������-����������� ���������. ���������
������� ���������� ������ ������ ��������� � ��������� ��.*/

class Triangle {
protected:
	float firstSide, secondSide, thirdSide;	//	������� ����������
	float firstSideX, firstSideY, secondSideX, secondSideY, thirdSideX, thirdSideY;	//	���������� ������ ����������
public:

	Triangle() {	//	����������� �� �����������
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
	virtual void calcData() = 0;	//	���������� � �����������
};

class TriangleTop : public Triangle {
public:

	TriangleTop() {	//	����������� �� �������������
		firstSideX = 0;
		firstSideY = 0;
		secondSideX = 0;
		secondSideY = 0;
		thirdSideX = 0;
		thirdSideY = 0;
	}

	void showData() {
		cout << "Enter coordinates of triangle`s apex: " << endl;//������� ���������� ������ ����������
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
		firstSide = sqrt(pow((secondSideX - firstSideX), 2) + pow((secondSideY - firstSideY), 2));//AB - ��������� ������� 3 ����� ���������� �� ��������� ������������
		secondSide = sqrt(pow((thirdSideX - secondSideX), 2) + pow((thirdSideY - secondSideY), 2));//BC
		thirdSide = sqrt(pow((thirdSideX - firstSideX), 2) + pow((thirdSideY - firstSideY), 2));//AC

		if (firstSide <= 0) {
			cout << "AB side " << firstSide << "doesn`t exist!" << endl;//���� ������� ������� ��� ����� 0, �� ���� �� ����
		}
		else if (secondSide <= 0) {
			cout << "BC side " << secondSide << "doesn`t exist!" << endl;
		}
		else if (thirdSide <= 0) {
            cout << "AC side " << thirdSide << "doesn`t exist!" << endl;
		}
		else if (firstSide < secondSide + thirdSide && thirdSide < firstSide + secondSide && secondSide < firstSide + thirdSide) {//���������� ����� ��������� ����������
			
			cout << "AB side: " << firstSide << " cm" << endl;
			cout << "BC side: " << secondSide << " cm" << endl;
			cout << "AC side: " << thirdSide << " cm" << endl;

			cout << "Middle line of triangle equal to KR (paralel to third side): " << thirdSide / 2 << " cm" << endl;//������� ��� ����������
			cout << "Median AD (first apex to second side): " << sqrt(2 * (pow(thirdSide, 2) + pow(firstSide, 2)) - pow(secondSide, 2)) / 2 << " cm" << endl;//������ ���������� AD (��������� � ������� � �� ������� ��)
		}
		else {
			cout << "Triangle doesn`t exist!" << endl;
		}
	}
};

class TriangleSides : public Triangle {
public:

	TriangleSides() {	//����������� �� �������������
		firstSide = 0;
		secondSide = 0;
		thirdSide = 0;
	}

	void showData() {
		cout << "Enter triangle`s sides: " << endl;//������� ������� ����������
		cout << "AB side: ";
		cin >> firstSide;
		cout << "BC side: ";
		cin >> secondSide;
		cout << "AC side: ";
		cin >> thirdSide;
		cout << endl;
	}

	void calcData() {
		if (firstSide < secondSide + thirdSide && secondSide < thirdSide + firstSide && thirdSide < firstSide + secondSide) {//���������� ����� ��������� ����������
			cout << "Middle line of triangle equal to KR (paralel to third side): " << thirdSide / 2 << " cm" << endl;//������� ��� ����������
			cout << "Median BK (second apex to third side): " << sqrt(2 * (pow(secondSide, 2) + pow(firstSide, 2)) - pow(thirdSide, 2))/2 << " cm" << endl;//������ ���������� BK (��������� � ������� B �� ������� A�)
		}
		else {
			cout << "Triangle doesn`t exist!" << endl;
		}
	}
};

class RightAngledTriangle : public Triangle {//����������� ���������
	float R, r;	//������� ��������� �� ��������� ������ ������������ ����������
public:

	RightAngledTriangle() {	//	����������� �� �����������
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
		if (firstSide < secondSide + thirdSide && secondSide < thirdSide + firstSide && thirdSide < firstSide + secondSide) {//���������� ����� ��������� ����������
			if (secondSide == sqrt(pow(firstSide, 2) + pow(thirdSide, 2))) {//��������� ����� �������� ����� ��. ��������� ������ �������� ��� ����� ����� �� �������� ϳ������
				cout << "Hypotenuse of second side BC equal to: " << secondSide << " cm" << endl;
				R = secondSide / 2;
				r = (firstSide + thirdSide - secondSide) / 2;
				cout << "Radius of outside circle R equal to: " << R << " cm" << endl;//����� ��������� ����
				cout << "Radius of inside circle r equal to: " << r << " �m" << endl;//����� ��������� ����
			}
			else if (firstSide == sqrt(pow(thirdSide, 2) + pow(secondSide, 2))) {
				cout << "Hypotenuse of first side AB equal to: " << firstSide << " cm" << endl;
				R = firstSide / 2;
				r = (thirdSide + secondSide - firstSide) / 2;
				cout << "Radius of outside circle R equal to: " << R << " cm" << endl;
				cout << "Radius of inside circle r equal to: " << r << " �m" << endl;
			}
			else if (thirdSide == sqrt(pow(firstSide, 2) + pow(secondSide, 2))) {
				cout << "Hypotenuse of third side AC equal to: " << thirdSide << " cm" << endl;
				R = thirdSide / 2;
				r = (firstSide + secondSide - thirdSide) / 2;
				cout << "Radius of outside circle R equal to: " << R << " cm" << endl;
				cout << "Radius of inside circle r equal to: " << r << " �m" << endl;
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
