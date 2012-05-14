/********************************************************************************
** Form generated from reading UI file 'frame.ui'
**
** Created: Sun May 6 14:23:43 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAME_H
#define UI_FRAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerCreator
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *name1;
    QComboBox *cb1;
    QCheckBox *chk1;
    QLineEdit *name2;
    QComboBox *cb2;
    QCheckBox *chk2;
    QLineEdit *name3;
    QComboBox *cb3;
    QCheckBox *chk3;

    void setupUi(QFrame *PlayerCreator)
    {
        if (PlayerCreator->objectName().isEmpty())
            PlayerCreator->setObjectName(QString::fromUtf8("PlayerCreator"));
        PlayerCreator->setWindowModality(Qt::WindowModal);
        PlayerCreator->resize(362, 194);
        QIcon icon;
        icon.addFile(QString::fromUtf8("burnt-paper-vivid-light.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        PlayerCreator->setWindowIcon(icon);
        PlayerCreator->setStyleSheet(QString::fromUtf8("background-image url(:/burnt-paper-vivid-light.jpg); background-repeat: repeat	"));
        PlayerCreator->setFrameShape(QFrame::StyledPanel);
        PlayerCreator->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(PlayerCreator);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 312, 122));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        name1 = new QLineEdit(layoutWidget);
        name1->setObjectName(QString::fromUtf8("name1"));

        gridLayout->addWidget(name1, 1, 0, 1, 1);

        cb1 = new QComboBox(layoutWidget);
        cb1->setObjectName(QString::fromUtf8("cb1"));

        gridLayout->addWidget(cb1, 1, 1, 1, 1);

        chk1 = new QCheckBox(layoutWidget);
        chk1->setObjectName(QString::fromUtf8("chk1"));

        gridLayout->addWidget(chk1, 1, 2, 1, 1);

        name2 = new QLineEdit(layoutWidget);
        name2->setObjectName(QString::fromUtf8("name2"));

        gridLayout->addWidget(name2, 2, 0, 1, 1);

        cb2 = new QComboBox(layoutWidget);
        cb2->setObjectName(QString::fromUtf8("cb2"));

        gridLayout->addWidget(cb2, 2, 1, 1, 1);

        chk2 = new QCheckBox(layoutWidget);
        chk2->setObjectName(QString::fromUtf8("chk2"));

        gridLayout->addWidget(chk2, 2, 2, 1, 1);

        name3 = new QLineEdit(layoutWidget);
        name3->setObjectName(QString::fromUtf8("name3"));

        gridLayout->addWidget(name3, 3, 0, 1, 1);

        cb3 = new QComboBox(layoutWidget);
        cb3->setObjectName(QString::fromUtf8("cb3"));

        gridLayout->addWidget(cb3, 3, 1, 1, 1);

        chk3 = new QCheckBox(layoutWidget);
        chk3->setObjectName(QString::fromUtf8("chk3"));

        gridLayout->addWidget(chk3, 3, 2, 1, 1);


        retranslateUi(PlayerCreator);

        QMetaObject::connectSlotsByName(PlayerCreator);
    } // setupUi

    void retranslateUi(QFrame *PlayerCreator)
    {
        PlayerCreator->setWindowTitle(QApplication::translate("PlayerCreator", "\351\200\211\346\213\251\347\216\251\345\256\266", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PlayerCreator", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PlayerCreator", "\350\201\214\344\270\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PlayerCreator", "\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        cb1->clear();
        cb1->insertItems(0, QStringList()
         << QApplication::translate("PlayerCreator", "\346\263\225\345\270\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PlayerCreator", "\346\210\230\345\243\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PlayerCreator", "\347\233\227\350\264\274", 0, QApplication::UnicodeUTF8)
        );
        chk1->setText(QApplication::translate("PlayerCreator", "\344\270\215\345\217\257\347\224\250", 0, QApplication::UnicodeUTF8));
        cb2->clear();
        cb2->insertItems(0, QStringList()
         << QApplication::translate("PlayerCreator", "\346\263\225\345\270\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PlayerCreator", "\346\210\230\345\243\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PlayerCreator", "\347\233\227\350\264\274", 0, QApplication::UnicodeUTF8)
        );
        chk2->setText(QApplication::translate("PlayerCreator", "\344\270\215\345\217\257\347\224\250", 0, QApplication::UnicodeUTF8));
        cb3->clear();
        cb3->insertItems(0, QStringList()
         << QApplication::translate("PlayerCreator", "\346\263\225\345\270\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PlayerCreator", "\346\210\230\345\243\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PlayerCreator", "\347\233\227\350\264\274", 0, QApplication::UnicodeUTF8)
        );
        chk3->setText(QApplication::translate("PlayerCreator", "\344\270\215\345\217\257\347\224\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PlayerCreator: public Ui_PlayerCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAME_H
