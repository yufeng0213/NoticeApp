#ifndef TASKCONTENT_H
#define TASKCONTENT_H

#include <QDialog>

namespace Ui {
class TaskContent;
}

class TaskContent : public QDialog
{
    Q_OBJECT

public:
    explicit TaskContent(QWidget *parent = nullptr);
    ~TaskContent();

private:
    Ui::TaskContent *ui;
};

#endif // TASKCONTENT_H
