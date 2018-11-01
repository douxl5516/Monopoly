#ifndef CARD_H
#define CARD_H

class Player;
class HumanPlayer;
class AutoPlayer;
class TallRichHandsomePlayer;
class WhiteRichBeautifulPlayer;
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

class Visitor {
public:
	virtual void visit(HumanPlayer* target)=0;
	virtual void visit(AutoPlayer* target)=0;
	virtual void visit(TallRichHandsomePlayer* target)=0;
	virtual void visit(WhiteRichBeautifulPlayer* target)=0;
};

class LuckCardVisitor :public Visitor {
private:
	LuckCard* card;
public:
	LuckCardVisitor(LuckCard* p);
	virtual void visit(HumanPlayer* target);
	virtual void visit(AutoPlayer* target);
	virtual void visit(TallRichHandsomePlayer* target);
	virtual void visit(WhiteRichBeautifulPlayer* target);
};
#endif // !CARD_H

