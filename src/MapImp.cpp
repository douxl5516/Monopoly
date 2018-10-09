#include "MapImp.h"
#include "Block.h"
#include <iostream>
using namespace std;

MapImp::MapImp()
{
}

MapImp::~MapImp()
{
	for (auto p : blocks) {
		delete[] p;
	}
	blocks.clear();
}

void MapImp::addBlock(Block *block)
{
	blocks.push_back(block);
}

Block * MapImp::getBlock(int index)
{
	return blocks.at(index);
}

void IndexMapImp::show() const
{
	int maxRow = 0;
	int maxCol = 0;
	for (auto block : blocks) {
		maxRow = block->getRow() > maxRow ? block->getRow() : maxRow;
		maxCol = block->getCol() > maxCol ? block->getCol() : maxCol;
	}
	maxRow++;
	maxCol++;
	char** img = new char*[maxRow];
	for (int i = 0; i < maxRow; i++) {
		img[i] = new char[maxCol];
	}
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			img[i][j] = 32;
		}
	}
	for (auto block : blocks) {
		img[block->getRow()][block->getCol()] = block->name()[0];
	}
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			cout << img[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < maxRow; i++) {
		delete[] img[i];
	}
	delete[] img;
}
