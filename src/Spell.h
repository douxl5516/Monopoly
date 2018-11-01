#ifndef SPELL_H
#define SPELL_H

class Player;
class Spell
{
protected:
	Player* exe;
	Player* tar;
public:
	Spell(Player* executor);
	Spell(Player* executor, Player* target);
	~Spell() {}
	virtual void execute()=0;
};

class ReturnSpell :public Spell{
public:
	ReturnSpell(Player* executor, Player* target);
	virtual void execute();
};

class FreezeSpell :public Spell {
public:
	FreezeSpell(Player* executor, Player* target);
	virtual void execute();
};

class HurtSpell :public Spell {
public:
	HurtSpell(Player* executor, Player* target);
	virtual void execute();
};
#endif // !SPELL_H

