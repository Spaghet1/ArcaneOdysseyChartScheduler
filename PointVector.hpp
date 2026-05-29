#include <cmath>

class PointVector {
public:
	double x;
	double y;

	PointVector(double x, double y) : x(x), y(y);

	double length() const {
		return hypot(this->x, this->y);
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
	friend PointVector operator*(const double scalar, const PointVector& pv) const {
		return PointVector(pv.x * scalar, pv.y * scalar);
	}
};
