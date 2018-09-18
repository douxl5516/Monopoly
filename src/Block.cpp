#include <iostream>
#include "Block.h"
using namespace std;

void BlockA::show()
{
	cout << "A";
}

Block * BlockA::clone()
{
	return new BlockA(*this);
}

void BlockB::show()
{
	cout << "B";
}

Block * BlockB::clone()
{
	return new BlockB(*this);
}

void BlockC::show()
{
	cout << "C";
}

Block * BlockC::clone()
{
	return new BlockC(*this);
}

void BlockD::show()
{
	cout << "D";
}

Block * BlockD::clone()
{
	return new BlockD(*this);
}

void BlockE::show()
{
	cout << "E";
}

Block * BlockE::clone()
{
	return new BlockE(*this);
}

void BlockF::show()
{
	cout << "F";
}

Block * BlockF::clone()
{
	return new BlockF(*this);
}

void BlockBlank::show()
{
	cout << " ";
}

Block * BlockBlank::clone()
{
	return new BlockBlank(*this);
}

void Block::push(Block * content)
{
	contents.push_back(content);
}

void Block::show()
{
	for (auto item : contents) {
		item->show();
	}
}

Block * Block::clone()
{
	return new Block(*this);
}

void BlockBoundary::show()
{
	cout << endl;
}

Block * BlockBoundary::clone()
{
	return new BlockBoundary(*this);
}
