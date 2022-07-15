#include "helpwindow.h"

helpWindow::helpWindow(QWidget *parent) : QDialog(parent)
{
     setWindowTitle("Help");
     setFixedSize(400,300);

     layout = new QGridLayout();
     //layout->setMargin(1);
     //layout->setGeometry(QRect(10, 10 , 380, 150));
     setLayout(layout);
     //layout->setColumnStretch(0,1);//   setColumnMinimumWidth(0,400);
     hText = new QTextBrowser(this);
     //hText->resize(380,270);
     hText->setPlainText("----------------------------Figure editor---------------");
     hText->append(      " ");
     hText->append(      "Click mouse:");
     hText->append(      "Left button - add figure");
     hText->append(      "Right button - delete figure");
     hText->append(      "Pressed left button - move figure");
     hText->append(      "Double click left button and move - rotate figure");
     hText->append(      "Spin wheel  - zoom/decrease figure");
     hText->append(      " ");
     hText->append(      "Press key:");
     hText->append(      " +/- - zoom/decrease work space");

     layout->addWidget(hText,0,0,Qt::AlignHCenter);
     okButt = new QPushButton(this);
     okButt->setText("Close");
     layout->addWidget(okButt,1,0,Qt::AlignHCenter);
     //connect(okButt,SIGNAL(clicked()), this, SLOT(close()));
     connect(okButt,&QPushButton::clicked, this, &QDialog::close);
}
