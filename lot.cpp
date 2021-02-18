#include <iostream>
#include "lot.h"
using namespace std;

Lot::Lot(int space, int r_space, int m_space, int d_space) {
	this->space = space;
	this->r_space = r_space;
	this->m_space = m_space;
	this->d_space = d_space;
}

int Lot::GetSpace() {
	return space;
}

int Lot::GetRSpace() {
	return r_space;
}

int Lot::GetMSpace() {
	return m_space;
}

int Lot::GetDSpace() {
	return d_space;
}
