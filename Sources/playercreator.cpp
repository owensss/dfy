#include "../Header/playercreator.hpp"
#include <QObject>

using std::string;

PlayerCreator::PlayerCreator (QWidget * parent) : QDialog(parent)
{
    setStyleSheet(QString::fromUtf8("background-image :  url(:/old_crackly_parchment_texture_by_Teeth_Man.png)"));
	pc.setupUi(this);
	/*
	QObject::connect(pc.chk1, SIGNAL(stateChanged(int)), pc.name1, SLOT(setEnabled(int)));
	QObject::connect(pc.chk2, SIGNAL(stateChanged(int)), pc.name2, SLOT(setEnabled(int)));
	QObject::connect(pc.chk3, SIGNAL(stateChanged(int)), pc.name3, SLOT(setEnabled(int)));
	*/
	QObject::connect(pc.chk1, SIGNAL(toggled(bool)), this, SLOT(SetName1(bool)));
	QObject::connect(pc.chk2, SIGNAL(toggled(bool)), this, SLOT(SetName2(bool)));
	QObject::connect(pc.chk3, SIGNAL(toggled(bool)), this, SLOT(SetName3(bool)));
	//QObject::connect(this, SIGNAL(accepted()), this, SLOT(CheckValid()));
	//QObject::connect(this, SIGNAL(Invalid()), this, SLOT(exec()));
}

void PlayerCreator::SetName1(bool toggled)
{
	if (toggled) pc.chk1->setText(QApplication::translate("playercreator", "\345\220\257\347\224\250", 0, QApplication::UnicodeUTF8));
	else pc.chk1->setText(QApplication::translate("playercreator", "\344\270\215\345\217\257\347\224\250", 0, QApplication::UnicodeUTF8));
}

void PlayerCreator::SetName2(bool toggled)
{
	if (toggled) pc.chk2->setText(QApplication::translate("playercreator", "\345\220\257\347\224\250", 0, QApplication::UnicodeUTF8));
	else pc.chk2->setText(QApplication::translate("playercreator", "\344\270\215\345\217\257\347\224\250", 0, QApplication::UnicodeUTF8));
}

void PlayerCreator::SetName3(bool toggled)
{
	if (toggled) pc.chk3->setText(QApplication::translate("playercreator", "\345\220\257\347\224\250", 0, QApplication::UnicodeUTF8));
	else pc.chk3->setText(QApplication::translate("playercreator", "\344\270\215\345\217\257\347\224\250", 0, QApplication::UnicodeUTF8));
}

bool PlayerCreator::CheckValid(void)
{
	if (Player_num() == 0)
	{
        setWindowTitle("player number can't be zero");
        return false;
	}
	else
    if ((pc.name1->isEnabled()&&pc.name1->text() == "")
    ||	(pc.name2->isEnabled()&&pc.name2->text() == "")
    ||	(pc.name3->isEnabled()&&pc.name3->text() == ""))
	{
        setWindowTitle("name can't be null");
		return false;
	}
	return true;
}

unsigned PlayerCreator::Player_num(void) const
{
    return pc.name1->isEnabled()+pc.name2->isEnabled()+pc.name3->isEnabled();
}

void PlayerCreator::NameProf(string* name, unsigned* prof) const
{
	int i = 0;
    if (pc.name1->isEnabled())
	{
		name[i] = pc.name1->text().toStdString();
		prof[i] = pc.cb1->currentIndex();
		++i;
	}
    if (pc.name2->isEnabled())
	{
		name[i] = pc.name2->text().toStdString();
		prof[i] = pc.cb2->currentIndex();
		++i;
	}
    if (pc.name3->isEnabled())
	{
		name[i] = pc.name3->text().toStdString();
		prof[i] = pc.cb3->currentIndex();
		++i;
	}
}
