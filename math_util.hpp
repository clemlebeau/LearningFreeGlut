#include <math.h>
#include <cstddef>
#include <float.h>

struct Vector3d {
	double x;
	double y;
	double z;

	bool operator==(const Vector3d& vector) {
		return (x == vector.x && y == vector.y  && z == vector.z);
	}

	operator bool() {
		return !(x == DBL_MAX && y == DBL_MAX && z == DBL_MAX);
	}

	bool operator!() {
		return (x == DBL_MAX && y == DBL_MAX && z == DBL_MAX);
	}

	Vector3d operator+(const Vector3d &OTHERVECTOR) {
		return Vector3d(x + OTHERVECTOR.x, y + OTHERVECTOR.y, z + OTHERVECTOR.z);
	}
	
	Vector3d operator-(const Vector3d &OTHERVECTOR) {
		return Vector3d(x - OTHERVECTOR.x, y - OTHERVECTOR.y, z - OTHERVECTOR.z);
	}

	Vector3d operator*(const double &scalar) {
		return Vector3d(x * scalar, y * scalar, z * scalar);
	}
	
	Vector3d normalize() {
		if (x || y || z) return Vector3d(x, y, z) * (1.0 / getModule());
		return *this;
	}

    // Cross product
	Vector3d operator*(Vector3d othervector) {
		return Vector3d((y * othervector.z) - (z * othervector.y), (z * othervector.x) - (x * othervector.z), (x * othervector.y) - (y * othervector.x));
	}

    // Dot product
	double operator%(Vector3d otherVector){
		return ((x * otherVector.x) + (y * otherVector.y) + (z * otherVector.z));
	}

	double getModule() {
		return sqrt((x * x) + (y * y) + (z * z));
	}

	double getModuleSquared() {
		return x * x + y * y + z * z;
	}

	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3d(const Vector3d& vector) {
		this->x = vector.x;
		this->y = vector.y;
		this->z = vector.z;
	}
};

struct Vector2d {
	double x;
	double y;

	bool operator==(const Vector2d& vector) {
		return (x == vector.x && y == vector.y);
	}

	operator bool() {
		return !(x == DBL_MAX && y == DBL_MAX);
	}

	bool operator!() {
		return (x == DBL_MAX && y == DBL_MAX);
	}

	Vector2d operator+(const Vector2d &OTHERVECTOR) {
		return Vector2d(x + OTHERVECTOR.x, y + OTHERVECTOR.y);
	}
	
	Vector2d operator-(const Vector2d &OTHERVECTOR) {
		return Vector2d(x - OTHERVECTOR.x, y - OTHERVECTOR.y);
	}

	Vector2d operator*(const double &scalar) {
		return Vector2d(x * scalar, y * scalar);
	}
	
	Vector2d normalize() {
		if (x || y) return Vector2d(x, y) * (1.0 / getModule());
		return *this;
	}

    // Dot product
	double operator%(Vector2d otherVector){
		return ((x * otherVector.x) + (y * otherVector.y));
	}

	double getModule() {
		return sqrt((x * x) + (y * y));
	}

	double getModuleSquared() {
		return x * x + y * y;
	}

	Vector2d(double x = 0.0, double y = 0.0) {
		this->x = x;
		this->y = y;
	}

	Vector2d(const Vector2d& vector) {
		this->x = vector.x;
		this->y = vector.y;
	}
};