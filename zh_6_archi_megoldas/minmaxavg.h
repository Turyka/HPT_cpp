#pragma once
#include "minmax.h"

//final, hogy ne lehessen belőle örököltetni
class MinMaxAvg final : public MinMax {
	double atlag;
public:
	double getAtlag() const { return atlag; }
	MinMaxAvg(const initializer_list<int> &l);

	//nem lehet másoló konstruktort és = operátort meghívni => nem lehet lemásolni
	MinMaxAvg(const MinMaxAvg &a) = delete;
	MinMaxAvg& operator=(const MinMaxAvg &a) = delete;
};
