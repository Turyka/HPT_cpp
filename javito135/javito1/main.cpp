#include "teglalap.h"

int main() {
	Teglalap t1, t2(1.4, 3.5), t3(2.3);

	std::cout << "Teglalap 1 : " << t1 << std::endl;
	std::cout << "Teglalap 2 : " << t2 << std::endl;
	std::cout << "Teglalap 3 : " << t3 << std::endl;

	std::cout << "Teglalap 2 * 3 : " << t2 * 3 << std::endl;
	std::cout << "Teglalap 3 * a.5 : " << t3 * 0.5 << std::endl;




	return 0;
}