#include <thread>
#include <iostream>
#include <ctime>
#include <list>
#include <map>

// konvert függvény készítése
// paramétere a lista és egy int->int függvény
// a lista minden elemén végrehajtja a függvényt és beírja a helyére (például i = fv(i))
void konvert(std::list<int> &eredmenyek, std::function<int(int)> fv) {
	for(auto &i : eredmenyek)
		i = fv(i);
}

int Modusz(const std::list<int> &eredmenyek) {
	std::map<int, int> darab;
	for(auto i : eredmenyek) {
		darab[i]++;
	}
	auto max = darab.begin();
	for(auto it = darab.begin(); it != darab.end(); it++) {
		if(max->second < it->second)
			max = it;
	}
	return max->first;
}

int main() {
	srand(time(0));
	std::list<int> eredmenyek;
	for(unsigned int i = 0; i < 1000; i++)
		eredmenyek.push_back(rand() % 100);
	double modusz;
	// a Modusz függvény elindítása egy szálon
	// az eredmény a modusz változóba kerüljön
	std::thread t1([&modusz, &eredmenyek]() { modusz = Modusz(eredmenyek); });
	t1.join();

	std::cout << modusz;

	// a konvert függvény meghívása lambda függvény segítségével
	// a lambda függvény a páros számokat ossza le 2-vel a páratlanokat szorozza meg 2-vel
	konvert(eredmenyek, [](int i) { return i % 2 == 0 ? i / 2 : i * 2; });
}