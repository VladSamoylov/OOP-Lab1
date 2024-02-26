#include "iostream"

using namespace std;

class Vector3D {

private:
	int x, y, z;

public:
	Vector3D() { x = 0; y = 0; z = 0; }
	Vector3D(int a, int b, int c) { x = a; y = b; z = c; }
	void Set();
	void Get();
	Vector3D Subtraction(Vector3D);
	void Addition(Vector3D&, Vector3D&);
	void LenghtVector();
};

void Vector3D::Set() {

	cout << "Enter vector coordinate: \n";
	cout << "x y z\n";
	cin >> this->x >> this->y >> this->z;
}

void Vector3D::Get() {

	cout << "Vector coordinate: x = " << this->x << " y = " << this->y << " z = " << this->z << endl;
}

void Vector3D::Addition(Vector3D& obj1, Vector3D& obj2) {
	
	this->x = obj1.x + obj2.x;
	this->y = obj1.y + obj2.y;
	this->z = obj1.z + obj2.z;
}

Vector3D Vector3D::Subtraction(Vector3D obj1) {
	Vector3D tmp;

	tmp.x = x - obj1.x;
	tmp.y = y - obj1.y;
	tmp.z = z - obj1.z;

	return tmp;
}

void Vector3D::LenghtVector() {
	float lenght = 0;

	lenght = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
	cout << "Lenght of vector - " << lenght << endl;
}


int main() {
	Vector3D a(2, 3, 4), b, c;

	b.Set();
	c.Addition(a, b);
	c.Get();
	b = b.Subtraction(a);
	b.Get();
	a.Set();
	a.LenghtVector();
}