#include <iostream>
#include <cmath>

class PointVector {
public:
	double x;
	double y;

	PointVector(double x, double y) : x(x), y(y);

	double length() const {
		return std::hypot(this->x, this->y);
	}
	
	PointVector operator+(const PointVector& other) const {
		return PointVector(this->x + other.x, this->y + other.y);
	}
	PointVector operator-(const PointVector& other) const {
		return PointVector(this->x - other.x, this->y - other.y);
	}
	PointVector operator*(const double scalar) const {
		return PointVector(this->x * scalar, this->y * scalar);
	}
};

PointVector operator*(const double scalar, const PointVector& pv) {
	return PointVector(pv.x * scalar, pv.y * scalar);
}

std::ostream& operator<<(std::ostream& os, const PointVector& pv) {
	os << '(' << pv.x << ',' << pv.y << ')';
	return os;
}
