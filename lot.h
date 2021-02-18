#ifndef LOT_H
#define LOT_H

using namespace std;

class Lot {
	public:
		Lot(int space, int r_space, int m_space, int d_space);
		int GetSpace();
		int GetRSpace();
		int GetMSpace();
		int GetDSpace();
	private:
		int space;
		int r_space;
		int m_space;
		int d_space;
};
#endif
