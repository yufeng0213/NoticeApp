#include "taskcontent.h"
#include "ui_taskcontent.h"

TaskContent::TaskContent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskContent)
{
    ui->setupUi(this);
}

TaskContent::~TaskContent()
{
    delete ui;
}
