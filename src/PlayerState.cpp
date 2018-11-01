#include "PlayerState.h"
#include "player.h"
#include <iostream>
using namespace std;

PlayerState::PlayerState(int _round)
{
	round = _round;
}

PlayerState::~PlayerState()
{
}

FreezeState::FreezeState(int round):PlayerState(round)
{
}

void FreezeState::execute(Player* p)
{
	if (!p->getAct() && round-- > 0) {
		cout << "## Freeze state! "<<p->name()<< " goes one step! " << round << " rounds left!" << endl;
		p->go();
	}
}


FlyState::FlyState(int round):PlayerState(round)
{
}

void FlyState::execute(Player* p)
{
	if (!p->getAct()&& round-- > 0) {
		cout << "## Fly state! " << p->name() << " goes six steps! " << round << " rounds left!" << endl;
		int i = 6;
		while (i--&& p->go());
	}
}

HumanCommonState::HumanCommonState():PlayerState(0)
{
}

void HumanCommonState::execute(Player * p)
{
	if (!p->getAct()) {
		int i = 3;
		while (i--&&p->go());
	}
}

AutoCommonState::AutoCommonState():PlayerState(0)
{
}

void AutoCommonState::execute(Player * p)
{
	if (!p->getAct()) {
		int i = 2;
		while (i--&&p->go());
	}
}

HurtState::HurtState(int round) :PlayerState(round)
{
}

void HurtState::execute(Player * p)
{
	if (round-- > 0) {
		cout << "## Hurt state! " << p->name() << " lost 5 coins! "<<round<<" rounds left!" << endl;
		int loseMoney = p->getMoney() < 5 ? p->getMoney() : 5;
		p->setMoney(p->getMoney() - loseMoney);
	}
}

LuckState::LuckState(int round) :PlayerState(round)
{
}

void LuckState::execute(Player * p)
{
	if (round-- > 0) {
		cout << "## Luck state! " << p->name() << " got 200 coins! " << round << " rounds left!"<< endl;
		p->setMoney(p->getMoney() + 200);
	}
}

ExFlyState::ExFlyState(int round) :PlayerState(round) 
{
}

void ExFlyState::execute(Player * p)
{
	if (round-- > 0) {
		p->setExFly(true);
	}
	else if(round==-1) {
		p->setExFly(false);
	}
}

MacroState::MacroState(PlayerState * _prev, PlayerState * _new):prevState(_prev),newState(_new),PlayerState(0)
{
}

MacroState::~MacroState()
{
	delete prevState;
	delete newState;
}

void MacroState::execute(Player * p)
{
	newState->execute(p);
	prevState->execute(p);
}


