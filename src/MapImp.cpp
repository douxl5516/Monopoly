///======================================================================
///  Project:   Richer02
/// FileName:	mapimp.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "mapimp.h"
#include "block.h"
#include "player.h"

MapImp::MapImp()
{
    //ctor
}

MapImp::~MapImp()
{
    //dtor
    for(Block* block : blocks) {
        delete block;
    }
}

void MapImp::addBlock(Block* block)
{
    blocks.push_back(block);
}
Block* MapImp::getBlock(int index) const
{
    return blocks[index];
}
int MapImp::getIndex(pair<int, int> pos)
{
	for (int i = 0; i < blocks.size(); i++) {
		if(blocks[i]->getRow()==pos.first&&blocks[i]->getCol()==pos.second)
			return i;
	}
	return -1;
}
void MapImp::show() const
{
    //OutDevice & dev = OutDevice::getConsole();

    vector<Block*> temps(blocks);
    sort(temps.begin(), temps.end(), [](Block * b1, Block * b2) {
        if(b1->getRow() == b2->getRow()) {
            return b1->getCol() < b2->getCol();
        } else {
            return b1->getRow() < b2->getRow();
        }
    });

    int row = 0;
    int col = 0;
    for(Block* block : temps) {
        int r = block->getRow();
        int c = block->getCol();
        for(int i = row; i < r; ++i) {
            cout << endl;
            col = 0;
        }
        for(int i = col; i < c; ++i) {
            cout << "  ";
        }
        cout << block->name() << " ";
        row = r;
        col = c + 1;
    }
    cout << endl;
}

void MapImp::show(Players * p) const
{
	map<pair<int, int>,int> pos = p->getPos();
#ifdef DEBUG_TRACE
	cout << "players' positions in mapImp:" << endl;
	for (auto item : pos) {
		cout << item.first.first << " " << item.first.second << " " << item.second << endl;
}
#endif // DEBUG_TRACE

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
		int inBlock=0;
		int r = block->getRow();
		int c = block->getCol();

		for (auto p : pos) {
			if (p.first.first == r && p.first.second == c) {
				inBlock = p.second;
			}
		}

		for (int i = row; i < r; ++i) {
			cout << endl;
			col = 0;
		}
		for (int i = col; i < c; ++i) {
			cout << "   ";
		}
		if (inBlock == 0)
			cout << " " << block->name() << " ";
		else if (inBlock == PlayerID::AUTO_PLAYER)
			cout << "(" << block->name() << ")";
		else if(inBlock==PlayerID::HUMAN_PLAYER)
			cout << "[" << block->name() << "]";
		row = r;
		col = c + 1;
	}
	cout << endl;
}

