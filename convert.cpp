#include "convert.h"
#include <iostream>

convert::convert()
{
setWindowTitle("Zahlensystem-Konverter");

QLabel *label_bin = new QLabel(this);
QLabel *label_oct = new QLabel(this);
QLabel *label_dec = new QLabel(this);
QLabel *label_hex = new QLabel(this);

label_bin->setText(QString::fromUtf8("Binär:"));
label_oct->setText("Oktal:");
label_dec->setText("Dezimal:");
label_hex->setText("Hexadezimal:");

edit_bin = new QLineEdit(this);
edit_oct = new QLineEdit(this);
edit_dec = new QLineEdit(this);
edit_hex = new QLineEdit(this);

QVBoxLayout *leftbox = new QVBoxLayout;
QVBoxLayout *rightbox = new QVBoxLayout;
QHBoxLayout *box = new QHBoxLayout(this);

leftbox->addWidget(label_bin);
leftbox->addWidget(edit_bin);
leftbox->addWidget(label_dec);
leftbox->addWidget(edit_dec);

rightbox->addWidget(label_oct);
rightbox->addWidget(edit_oct);
rightbox->addWidget(label_hex);
rightbox->addWidget(edit_hex);

box->addLayout(leftbox);
box->addLayout(rightbox);

connect(edit_bin,SIGNAL(textChanged(const QString &)),this,SLOT(slot_bin()));
connect(edit_oct,SIGNAL(textChanged(const QString &)),this,SLOT(slot_oct()));
connect(edit_dec,SIGNAL(textChanged(const QString &)),this,SLOT(slot_dec()));
connect(edit_hex,SIGNAL(textChanged(const QString &)),this,SLOT(slot_hex()));

resize(265,100);

lock=0;
}

void convert::slot_bin(void)
{
if(lock) return;
bool ok;
int conv = edit_bin->text().toInt(&ok, 2);
lock=1;
if(ok)
  {
  edit_dec->setText(QString::number(conv));
  edit_oct->setText(QString::number(conv,8));
  edit_hex->setText(QString::number(conv,16));
  }
lock=0;
}

void convert::slot_oct(void)
{
if(lock) return;
bool ok;
int conv = edit_oct->text().toInt(&ok, 8);
lock=1;
if(ok)
  {
  edit_dec->setText(QString::number(conv));
  edit_bin->setText(QString::number(conv,2));
  edit_hex->setText(QString::number(conv,16));
  }
lock=0;
}

void convert::slot_dec(void)
{
if(lock) return;
bool ok;
int conv = edit_dec->text().toInt(&ok,10);
lock=1;
if(ok)
  {
  edit_bin->setText(QString::number(conv,2));
  edit_oct->setText(QString::number(conv,8));
  edit_hex->setText(QString::number(conv,16));
  }
lock=0;
}

void convert::slot_hex(void)
{
if(lock) return;
bool ok;
int conv = edit_hex->text().toInt(&ok, 16);
lock=1;
if(ok)
  {
  edit_bin->setText(QString::number(conv,2));
  edit_oct->setText(QString::number(conv,8));
  edit_dec->setText(QString::number(conv,10));
  }
lock=0;
}
