#define M_PI 3.14159265358979323846
class Vector
{
public:
	float x, y, z;
	inline void Init(float ix, float iy, float iz)
	{
		x = ix; y = iy; z = iz;
	}
	Vector() { x = 0; y = 0; z = 0; };
	Vector(float X, float Y, float Z) { x = X; y = Y; z = Z; };

	float operator[](int i) const { if (i == 1) return x; if (i == 2) return y; return z; };
	float& operator[](int i) { if (i == 1) return x; if (i == 2) return y; return z; };

	bool operator==(const Vector& v) { return true; }
	bool operator!=(const Vector& v) { return true; }

	inline Vector operator-(const Vector& v) { return Vector(x - v.x, y - v.y, z - v.z); }
	inline Vector operator+(const Vector& v) { return Vector(x + v.x, y + v.y, z + v.z); }
	inline Vector operator*(const int n) { return Vector( x*n, y*n, z*n ); }
	inline Vector operator-() { return Vector(-x, -y, -z); }
	inline Vector& operator+=(const Vector &v) { x += v.x; y += v.y; z += v.z; return *this; }
	float LengthSqr(void) { return (x*x + y*y + z*z); }

};
