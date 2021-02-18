#ifndef LOTS_H
#define LOTS_H

#include <vector>
#include <string>
#include "lot.h"
using namespace std;

class Lots {
	public:
		vector<string> Input();
		void Output();
		void Cleanup();
	private:
		typedef vector<Lot*> lotType;
		lotType lotList;
};
#endif
