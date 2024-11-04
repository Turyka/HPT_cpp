#include <iostream>
#include <math.h>
#include <initializer_list>
#include <functional>
#include <thread>
#include <mutex>
#include <chrono>

// Windows-on fordításkor egy másik define miatt az M_PI define nem kerül bele a kódba, linuxon benne van
// Ez a rész megnézi, hogy definiálva van-e, és ha nem, akkor megteszi
// Lehetne egy const double változó is, de mivel alapból is define lenne, most is legyen az
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//TODO: DegToRad, RadToDeg
constexpr double DegToRad(double value) {
	return value / 180 * M_PI;
}

constexpr double RadToDeg(double value) {
	return value / M_PI * 180;
}
class FixStorage {
	int size,*array;
public:
	//TODO: konstruktor inicializáló listával, move konstruktor, move = operátor
	FixStorage(std::initializer_list<int> l)
	{
		size = l.size();
		array = new int[size];
		unsigned int i= 0;
		for (auto var : l)
		{
			array[i++] = var;

		}
	}
	FixStorage(FixStorage&& other)
	{
		size = other.size;
		array = other.array;
		other.array = nullptr;
	}
	FixStorage& operator=(FixStorage&& other)
	{
		if (this == &other)
			return *this;

		size = other.size;
		delete[] array;
		array = other.array;
		other.array = nullptr;
		return *this;
	}
	~FixStorage() {
		delete[] array;
	}

	friend std::ostream& operator <<(std::ostream &os, const FixStorage & fixs) {
		for(int i = 0; i < fixs.size; i++) {
			if (i > 0) os << ",";
			os << fixs.array[i];
		}
		return os;
	}
};

FixStorage getStore(int type) {
	if(type == 1)
		return FixStorage({0,1,2,3,4,5,6,7,8,9});
	else if(type == 2)
		return FixStorage({10,11,12,13,14,15});
	else
		return FixStorage({1,1,1,1,1});
}

float interpolate(float start, float end, float q) {
	return start * (1 - q) + end * q;
}

// TODO: interpolateFunc
int interpolateFunc(int start, int end, float q, std::function<float(float)> fv) // vagy std::function<float(float)> fv |float (*fv)(float) = gyorosabb, de sima pointer
{
	return interpolate(start, end, fv(q));
}

float f_sqr(float q) {
	return q * q;
}

long long int fibo(int i) {
	if(i == 0)
		return 0;
	else if (i == 1)
		return 1;
	else return fibo(i - 1) + fibo(i - 2);
}

int main() {

std::cout << DegToRad(90.0) << std::endl; // 1.5708
std::cout << RadToDeg(0.9) << std::endl; // 51.5662

FixStorage store1({5,4,3,6,8,7});
std::cout << store1 << std::endl; // 5,4,3,6,8,7

	FixStorage s1 = getStore(1);
	std::cout << s1 << std::endl; // 0,1,2,3,4,5,6,7,8,9
	s1 = getStore(2);
	std::cout << s1 << std::endl; // 10,11,12,13,14,15
	s1 = getStore(0);
	std::cout << s1 << std::endl; // 1,1,1,1,1

	float f;
	int i;
	std::cout << std::endl << "BASE" << std::endl;
	for( i = 0, f = 0.0; i <= 10; i++, f += 0.1) {
		std::cout << interpolate(5,10,f) << std::endl;
	}
////	5
////	5.5
////	6
////	6.5
////	7
////	7.5
////	8
////	8.5
////	9
////	9.5
////	10

	std::cout << std::endl << "f_sqr" << std::endl;
	for(i = 0, f = 0.0; i <= 10; i++, f += 0.1) {
		std::cout << interpolateFunc(0, 100, f, &f_sqr) << std::endl;
	}

////	0
////	1
////	4
////	9
////	16
////	25
////	36
////	49
////	64
////	81
////	100

std::cout << std::endl << "multilambda" << std::endl;

	for(i = 0, f = 0.0; i <= 20; i++, f += 0.05) {
		//TODO: lamdba függvények: lsqr négyzetre emel, lsqrt gyököt von
		//auto lsqr = [](float value) { return value * value; };
		//auto lsqrt = [](float value) { return sqrtf(value); };
		std::cout << interpolateFunc(0, 1, f, [](float value) { return value * value; });
		std::cout << ", " << interpolateFunc(0, 1, f, [](float value) { return sqrtf(value); }) << std::endl;
	}
////	0, 0
////	0.0025, 0.223607
////	0.01, 0.316228
////	0.0225, 0.387298
////	0.04, 0.447214
////	0.0625, 0.5
////	0.09, 0.547723
////	0.1225, 0.591608
////	0.16, 0.632456
////	0.2025, 0.67082
////	0.25, 0.707107
////	0.3025, 0.74162
////	0.36, 0.774597
////	0.4225, 0.806226
////	0.49, 0.83666
////	0.5625, 0.866025
////	0.64, 0.894427
////	0.7225, 0.921955
////	0.81, 0.948683
////	0.9025, 0.97468
////	1, 1

//	int number;
//	std::cout << "Give me a number!   ";
//	std::cin >> number;
//	std::mutex _mutex;
//	long long int res = 0;
	//TODO: ket új szál, az egyik futtatja a fibo függvényt, a másik másodpercenként kijelzi, hogy még fut
//	std::cout << res << std::endl;

	return 0;
}
