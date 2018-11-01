#include "Card.h"
#include "player.h"

Card::Card(Player * executor):exe(executor)
{
}

Card::Card(Player * executor, Player * target):exe(executor),tar(target)
{
}

Card::~Card()
{
}

RobCard::RobCard(Player * executor, Player *target):Card(executor,target)
{
}

void RobCard::execute()
{
	exe->ApplyRobCard(tar);
}

MeanCard::MeanCard(Player * executor):Card(executor)
{
}

void MeanCard::execute()
{
	exe->ApplyMeanCard();
}

FlyCard::FlyCard(Player * executor, Player * target):Card(executor,target)
{
}

void FlyCard::execute()
{
	exe->ApplyFlyCard(tar);
}

LuckCard::LuckCard(Player * executor, Player * target):Card(executor,target)
{
}

void LuckCard::execute()
{
	exe->ApplyLuckCard(tar);
}

ExFlyCard::ExFlyCard(Player * executor, Player * target) :Card(executor, target)
{
}

void ExFlyCard::execute()
{
	exe->ApplyExFlyCard(tar);
}

SuperCard::SuperCard(Player * executor, Player * target) :Card(executor, target)
{
}

void SuperCard::execute()
{
	exe->ApplySuperCard(tar);
}
