#ifndef CARD_H
#define CARD_H

class Player;
class Card
{
protected:
	Player* exe;
	Player* tar;
public:
	Card(Player* executor);
	Card(Player* executor,Player* target);
	virtual ~Card(); 
	virtual void execute() {}
};

class RobCard :public Card {
public:
	RobCard(Player* executor,Player *target);
	virtual void execute();
};

class MeanCard :public Card {
public:
	MeanCard(Player* executor);
	virtual void execute();
};

class FlyCard :public Card {
public:
	FlyCard(Player* executor, Player *target);
	virtual void execute();
};

class LuckCard :public Card {
public:
	LuckCard(Player* executor, Player *target);
	virtual void execute();
};

class ExFlyCard :public Card {
public:
	ExFlyCard(Player* executor, Player *target);
	virtual void execute();
};

class SuperCard :public Card {
public:
	SuperCard(Player* executor, Player *target);
	virtual void execute();
};
#endif // !CARD_H

