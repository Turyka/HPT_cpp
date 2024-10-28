#include "minmax.h"

MinMax::MinMax(const initializer_list<int> &l) {
	//az első elem
	minimum = maximum = *(l.begin());
	//foreach ciklus, minden listaelemre
	//i nem iterátor, hanem a list egy eleme
	for (auto i : l) {
		if (minimum > i)
			minimum = i;
		if (maximum < i)
			maximum = i;
	}
}