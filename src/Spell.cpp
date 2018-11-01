#include "Spell.h"
#include "player.h"

Spell::Spell(Player * executor):exe(executor)
{
}

Spell::Spell(Player * executor, Player * target):exe(executor),tar(target)
{
}

ReturnSpell::ReturnSpell(Player * executor, Player * target):Spell(executor,target)
{
}

void ReturnSpell::execute()
{
	exe->ApplyReturnSpell(tar);
}

FreezeSpell::FreezeSpell(Player * executor, Player * target):Spell(executor,target)
{
}

void FreezeSpell::execute()
{
	exe->ApplyFreezeSpeel(tar);
}

HurtSpell::HurtSpell(Player * executor, Player * target):Spell(executor,target)
{
}

void HurtSpell::execute()
{
	exe->ApplyHurtSpell(tar);
}
