#include "MapImp.h"
#include "Block.h"
#include <iostream>
#include <algorithm>
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

void MapImp::show() const
{
	vector<Block*> temps(blocks);
	sort(temps.begin(), temps.end(), [](Block * b1, Block * b2) {
		if (b1->getRow() == b2->getRow()) {
			return b1->getCol() < b2->getCol();
		}
		else {
			return b1->getRow() < b2->getRow();
		}
	});

	int row = 0;
	int col = 0;
	for (Block* block : temps) {
		int r = block->getRow();
		int c = block->getCol();
		for (int i = row; i < r; ++i) {
			cout << endl;
			col = 0;
		}
		for (int i = col; i < c; ++i) {
			cout << "  ";
		}
		cout << block->name() << " ";
		row = r;
		col = c + 1;
	}
	cout << endl;
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
