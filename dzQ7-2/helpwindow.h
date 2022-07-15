#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QTextBrowser>
#include <QPushButton>
#include <QGridLayout>

class helpWindow : public QDialog
{
    Q_OBJECT
public:
    explicit helpWindow(QWidget *parent = nullptr);

public slots:

private:
    QGridLayout* layout;
    QTextBrowser* hText;
    QPushButton* okButt;

signals:
    void on_okButt_clicked();

};

#endif //  // HELPWINDOW_H
