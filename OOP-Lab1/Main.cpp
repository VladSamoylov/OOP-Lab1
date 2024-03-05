#include "iostream"
#include "tuple"

using namespace std;

class Vector3D {

private:
	int x, y, z;

	void CheckData(int&, int&, int&);	
public:
	Vector3D() { x = 0; y = 0; z = 0; }
	Vector3D(int a, int b, int c) { x = a; y = b; z = c; }
	void SetVector();
	tuple<int, int, int> GetVector();
	int GetX();
	int GetY();
	int GetZ();
	Vector3D Subtraction(Vector3D&);
	void Addition(Vector3D&, Vector3D&);
	void LenghtVector();
	~Vector3D() { cout << "Clear by destructor" << endl; }
};

/**
 * @brief �����, ���� �������� �������� �������� ��������� �������
 * @param x ���������� �
 * @param y ���������� �
 * @param z ���������� z
*/
void Vector3D::CheckData(int& x, int& y, int& z) {

	cin.ignore(666, '\n');
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(666, '\n');
			cerr << "You enter wrong data! Please enter correct data: \n";
			cout << "Enter vector coordinate - ";
			cout << "x y z: ";
			cin >> x >> y >> z;
			cin.ignore(666, '\n');
		}
		else break;
	}
}

/**
 * @brief �����-������ ����� ��������� �������
*/
void Vector3D::SetVector() {

	cout << "x y z: ";
	cin >> this->x >> this->y >> this->z;
	CheckData(this->x, this->y, this->z);
}

/**
 * @brief �����-������ ��������� ��������� �������
 * @return ���������� ������� (������), ���� ������� ������
*/
tuple<int, int, int> Vector3D::GetVector() {

	return make_tuple(this->x, this->y, this->z);
}

/**
 * @brief �����-������ ��� ��������� ���������� � �������, ��� ��� ����������� �����
 * @return ��������� �, ����������� �������
*/
int Vector3D::GetX() {

	return this->x;
}

/**
 * @brief �����-������ ��� ��������� ���������� Y �������, ��� ��� ����������� �����
 * @return ��������� Y, ����������� �������
*/
int Vector3D::GetY() {

	return this->y;
}

/**
 * @brief �����-������ ��� ��������� ���������� Z �������, ��� ��� ����������� �����
 * @return ��������� Z, ����������� �������
*/
int Vector3D::GetZ() {

	return this->z;
}

/**
 * @brief �����, ���� ������ ��������� ���� �������
 * @param obj1 ������ ������
 * @param obj2 ������ ������
*/
void Vector3D::Addition(Vector3D& obj1, Vector3D& obj2) {
	
	this->x = obj1.x + obj2.x;
	this->y = obj1.y + obj2.y;
	this->z = obj1.z + obj2.z;
}

/**
 * @brief �����, ���� ������ �������� ��������� ������� obj1 �� ��������� �������, ��� ����� ����������� �����
 * @param obj1 ������, ���� ������� ������
 * @return ����� ��'��� Vector3D, ���� ������ � ��� ��������� ��������
*/
Vector3D Vector3D::Subtraction(Vector3D& obj1) {
	Vector3D tmp;

	tmp.x = x - obj1.x;
	tmp.y = y - obj1.y;
	tmp.z = z - obj1.z;

	return tmp;
}

/**
 * @brief �����, ���� �������� �������� �������, ��� ����� ����������� �����
*/
void Vector3D::LenghtVector() {
	double lenght = 0;

	lenght = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
	cout << "Lenght of vector - " << lenght << endl;
}

int main() {
	int retry = 1;
	bool work = true;
	tuple<int, int, int> values;
	Vector3D a(2, 3, 4), b, c;

	while (work) {
		switch (retry) {
		case 1:
			cout << "Enter vector B coordinate - "; b.SetVector();
			values = a.GetVector();
			cout << "Vector A - x = " << get<0>(values) << " y = " << get<1>(values) << " z = " << get<2>(values) << endl;
			c.Addition(a, b);
			cout << "Vector C (A + B) - x = " << c.GetX() << " y = " << c.GetY() << " z = " << c.GetZ() << endl;
			c = b.Subtraction(a);
			cout << "Vector C (B - A) - x = " << c.GetX() << " y = " << c.GetY() << " z = " << c.GetZ() << endl;
			cout << "Enter vector A coordinate - "; a.SetVector();
			a.LenghtVector();
			break;
		case 0:
			work = false;
			break;
		default:
			work = false;
			break;
		}
		if (work) {
			cout << "\n------Retry? 1 - Yes / 0 - No------\n";
			cin >> retry;
		}
	}
	return 0;
}