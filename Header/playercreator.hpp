#include "ui_playercreator.h"
#include <QWidget>
#include <QMessageBox>
#include <list>

class PlayerCreator : public QDialog
{
	Q_OBJECT
	signals:
		void Invalid() const;
	public slots:
		void SetName1(bool toggled);
		void SetName2(bool toggled);
		void SetName3(bool toggled);
        bool CheckValid();
		unsigned Player_num(void) const;
		void NameProf(std::string* name, unsigned* prof) const;
	public:
		PlayerCreator(QWidget * parent = NULL);
		~PlayerCreator() {}
	private:
		Ui::playercreator pc;
};
