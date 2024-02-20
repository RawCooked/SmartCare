#include "rdv_top.h"
#include "ui_rdv_top.h"

RDV_top::RDV_top(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RDV_top)
{
    ui->setupUi(this);
}

RDV_top::~RDV_top()
{
    delete ui;
}
