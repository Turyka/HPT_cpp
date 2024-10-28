#include "minmaxavg.h"

//a MinMax konstruktorát is meg kell hívni              |
//														V
MinMaxAvg::MinMaxAvg(const initializer_list<int> &l) : MinMax(l) {
	atlag = 0.0;
	for (auto i : l) {
		atlag += i;
	}
	atlag /= l.size();
}
