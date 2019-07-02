/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Data Visualization module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "surfacegraph.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtGui/QPainter>
#include <QtGui/QScreen>


#include <QtSerialPort/QSerialPort>

#include <QTextStream>
#include <QCoreApplication>
#include <QFile>
#include <QStringList>
#include <QtDebug>
#include <QObject>
#include <QString>
#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>
#include <QTimer>

#include <QSerialPortInfo>
#include <QComboBox>
#include <QWindow>
////#include <QApplication>



//int integertest[16][24];

QT_USE_NAMESPACE





int main(int argc, char **argv)
{



// //////////////////////////////////////////////////////////////////////////////////////////
//              START OF SETUP
// //////////////////////////////////////////////////////////////////////////////////////////

        QTextStream standardOutput(stdout);
//        QByteArray data, data2;


//        serial.setPortName("COM4");
//        serial.setBaudRate(QSerialPort::Baud9600); /*, QSerialPort::Output*/
//        serial.setDataBits(QSerialPort::Data8);
//        serial.setParity(QSerialPort::NoParity);
//        serial.setStopBits(QSerialPort::TwoStop);
//        serial.setFlowControl(QSerialPort::NoFlowControl);
//        serial.open(QIODevice::ReadWrite);




//        if(!serial.isOpen()){
//            standardOutput << "this port is not currently open\r\n" << endl;
//        }
//        if(serial.isOpen()){
//            standardOutput << "this port is now opennnnnnnnnnnnnnnnnn\r\n" << endl;
//        }


//        //Setup Command
//        serial.write("!sm\r\n");
//        standardOutput << "!SM\r\n" << endl;
//        serial.waitForReadyRead();


//    data = serial.readLine();
//while(data.isNull() == TRUE){
//    data = serial.readLine();
//}
////if(data[0] == 'N'){
////     standardOutput << "N is present" << endl;
////}
// standardOutput << data << endl;


//        //Set Columns Number
//        serial.write("!nc24\r\n");
//        standardOutput << "!NC24\r\n" << endl;
//        serial.waitForReadyRead();
////        data = serial.readLine();
////        if(data != "\n")
////            standardOutput << data << endl;
////        serial.waitForReadyRead();

////        while(data != "Number of col 24"){
////        data = serial.readLine();
////        }
////         standardOutput << data <<


//          //   data = serial.readLine();
//             data = serial.readLine();

//         while(data[0] != 'N'){
//           // while(data.isNull() == TRUE ){ // || data[0] == '\n'){
//             serial.waitForReadyRead();
//             data = serial.readLine();
//             // standardOutput << "check" << endl;
//         }
//          standardOutput << data << endl;
//          standardOutput << "above" << endl;



//      //Set Rows Number
//         serial.write("!nr16\r\n");
//         standardOutput << "!NR24\r\n" << endl;
//         serial.waitForReadyRead();
////         data = serial.readLine();
////         standardOutput << data << endl;
////         serial.waitForReadyRead();

////         while(data != "Number of row 16"){
////         data = serial.readLine();
////         }
////           standardOutput << data << endl;
//             data = serial.readLine();
//              while(data[0] != 'N'){
//           //while(data.isNull() == TRUE){
//                  serial.waitForReadyRead();
//               data = serial.readLine();
//           }
//            standardOutput << data << endl;


//          //Set Delay
//          serial.write("!sd10\r\n");
//          standardOutput << "!SD10\r\n" << endl;
//          serial.waitForReadyRead();
////          data = serial.readLine();
////          serial.waitForReadyRead();

////          while(data != "Sampling Delay 10"){
////              data = serial.readLine();
////          }
////          standardOutput << data << endl;
//             data = serial.readLine();
//             while(data[0] != 'S'){
//             serial.waitForReadyRead();
//        //  while(data.isNull() == TRUE){
//              data = serial.readLine();
//          }
//           standardOutput << data << endl;




//           //Start Sampling
//        serial.write("!ss\r\n");
//        standardOutput << "!ss\r\n" << endl;
//        serial.waitForReadyRead();
////        data = serial.readLine();
////        serial.waitForReadyRead();

////        while(data != "Sampling Matrix"){
////            data = serial.readLine();
////        }
////        standardOutput << data << endl;
//        data = serial.readLine();
//          while(data[0] != 'S'){
//    //    while(data.isNull() == TRUE){
//              serial.waitForReadyRead();
//            data = serial.readLine();
//        }
//         standardOutput << data << endl;


// //////////////////////////////////////////////////////////////////////////////////////////
//              END OF SETUP
// //////////////////////////////////////////////////////////////////////////////////////////

        QApplication app(argc, argv);



//        QTimer*timer = new QTimer(this);
//        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(fillSqrtSinProxy()));
//        timer->start(100);

    // ! [0]
//    QApplication app(argc, argv);
    Q3DSurface *graph = new Q3DSurface();
    QWidget *container = QWidget::createWindowContainer(graph);
    // ! [0]

    if (!graph->hasContext()) {
        QMessageBox msgBox;
        msgBox.setText("Couldn't initialize the OpenGL context.");
        msgBox.exec();
        return -1;
    }

    QSize screenSize = graph->screen()->size();
    container->setMinimumSize(QSize(screenSize.width() / 2, screenSize.height() / 1.6));
    container->setMaximumSize(screenSize);
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    container->setFocusPolicy(Qt::StrongFocus);

    //! [1]
    QWidget *widget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);
    vLayout->setAlignment(Qt::AlignTop);
    //! [1]


    widget->setWindowTitle(QStringLiteral("Surface example"));

    QGroupBox *modelGroupBox = new QGroupBox(QStringLiteral("Model"));

    QRadioButton *sqrtSinModelRB = new QRadioButton(widget);
    sqrtSinModelRB->setText(QStringLiteral("Raw Data"));
    sqrtSinModelRB->setChecked(false);

    QRadioButton *heightMapModelRB = new QRadioButton(widget);
    heightMapModelRB->setText(QStringLiteral("Touch Data"));
    heightMapModelRB->setChecked(false);

    QVBoxLayout *modelVBox = new QVBoxLayout;
    modelVBox->addWidget(sqrtSinModelRB);
    modelVBox->addWidget(heightMapModelRB);
    modelGroupBox->setLayout(modelVBox);

    QGroupBox *selectionGroupBox = new QGroupBox(QStringLiteral("Selection Mode"));

    QRadioButton *modeNoneRB = new QRadioButton(widget);
    modeNoneRB->setText(QStringLiteral("No selection"));
    modeNoneRB->setChecked(false);

    QRadioButton *modeItemRB = new QRadioButton(widget);
    modeItemRB->setText(QStringLiteral("Item"));
    modeItemRB->setChecked(false);

    QRadioButton *modeSliceRowRB = new QRadioButton(widget);
    modeSliceRowRB->setText(QStringLiteral("Row Slice"));
    modeSliceRowRB->setChecked(false);

    QRadioButton *modeSliceColumnRB = new QRadioButton(widget);
    modeSliceColumnRB->setText(QStringLiteral("Column Slice"));
    modeSliceColumnRB->setChecked(false);

    QVBoxLayout *selectionVBox = new QVBoxLayout;
    selectionVBox->addWidget(modeNoneRB);
    selectionVBox->addWidget(modeItemRB);
    selectionVBox->addWidget(modeSliceRowRB);
    selectionVBox->addWidget(modeSliceColumnRB);
    selectionGroupBox->setLayout(selectionVBox);

    QSlider *axisMinSliderX = new QSlider(Qt::Horizontal, widget);
    axisMinSliderX->setMinimum(0);
    axisMinSliderX->setTickInterval(1);
    axisMinSliderX->setEnabled(true);
    QSlider *axisMaxSliderX = new QSlider(Qt::Horizontal, widget);
    axisMaxSliderX->setMinimum(1);
    axisMaxSliderX->setTickInterval(1);
    axisMaxSliderX->setEnabled(true);
    QSlider *axisMinSliderZ = new QSlider(Qt::Horizontal, widget);
    axisMinSliderZ->setMinimum(0);
    axisMinSliderZ->setTickInterval(1);
    axisMinSliderZ->setEnabled(true);
    QSlider *axisMaxSliderZ = new QSlider(Qt::Horizontal, widget);
    axisMaxSliderZ->setMinimum(1);
    axisMaxSliderZ->setTickInterval(1);
    axisMaxSliderZ->setEnabled(true);


    QSlider *axisMinSliderY = new QSlider(Qt::Horizontal, widget);
    axisMinSliderY->setMinimum(0);
    axisMinSliderY->setTickInterval(1);
    axisMinSliderY->setEnabled(true);
    QSlider *axisMaxSliderY = new QSlider(Qt::Horizontal, widget);
    axisMaxSliderY->setMinimum(1);
    axisMaxSliderY->setTickInterval(1);
    axisMaxSliderY->setEnabled(true);






//    QSlider *SensitivitySlider = new QSlider(Qt::Horizontal, widget);
//    SensitivitySlider->setMinimum(0);
//    SensitivitySlider->setTickInterval(1);
//    SensitivitySlider->setEnabled(true);




    QComboBox *themeList = new QComboBox(widget);
    themeList->addItem(QStringLiteral("Qt"));
    themeList->addItem(QStringLiteral("Primary Colors"));
    themeList->addItem(QStringLiteral("Digia"));
    themeList->addItem(QStringLiteral("Stone Moss"));
    themeList->addItem(QStringLiteral("Army Blue"));
    themeList->addItem(QStringLiteral("Retro"));
    themeList->addItem(QStringLiteral("Ebony"));
    themeList->addItem(QStringLiteral("Isabelle"));




        QGroupBox *Sensitivity = new QGroupBox(QStringLiteral("Sensitivity"));

//        QRadioButton *onetimes = new QRadioButton(widget);
//        onetimes->setText(QStringLiteral("1"));
//        onetimes->setChecked(true);
//      // Sensitivity->setLayout(onetimes)

//        QRadioButton *tentimes = new QRadioButton(widget);
//        tentimes->setText(QStringLiteral("10"));
//        tentimes->setChecked(false);

//        QRadioButton *less = new QRadioButton(widget);
//        less->setText(QStringLiteral("0.1"));
//        less->setChecked(false);

//        QVBoxLayout *sensitivityVBox = new QVBoxLayout;
//        sensitivityVBox->addWidget(onetimes);
//        sensitivityVBox->addWidget(tentimes);
//        sensitivityVBox->addWidget(less);
//        selectionGroupBox->setLayout(sensitivityVBox);


    QGroupBox *com = new QGroupBox(QStringLiteral("Port"));

    QComboBox *box = new QComboBox;
       Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
           box->addItem(port.portName());
       }
       //box->move(100 - box->width() / 2,100 - box->height() / 2);
       box->show();




       QPushButton *start = new QPushButton(widget);
      // start->setIcon(QIcon(pm));
       start->setText("Start");
//       Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
//           start->addItem(port.portName());
//       }

       start->setIconSize(QSize(24, 24));




       QPushButton *stop = new QPushButton(widget);
      // start->setIcon(QIcon(pm));
       stop->setText("Stop");


       stop->setIconSize(QSize(24, 24));


 //standardOutput << box->currentText() << endl;



    QGroupBox *colorGroupBox = new QGroupBox(QStringLiteral("Custom gradient"));

    QLinearGradient grBtoY(0, 0, 1, 100);
    grBtoY.setColorAt(1.0, Qt::black);
    grBtoY.setColorAt(0.67, Qt::blue);
    grBtoY.setColorAt(0.33, Qt::red);
    grBtoY.setColorAt(0.0, Qt::yellow);
    QPixmap pm(24, 100);
    QPainter pmp(&pm);
    pmp.setBrush(QBrush(grBtoY));
    pmp.setPen(Qt::NoPen);
    pmp.drawRect(0, 0, 24, 100);
    QPushButton *gradientBtoYPB = new QPushButton(widget);
    gradientBtoYPB->setIcon(QIcon(pm));
    gradientBtoYPB->setIconSize(QSize(24, 100));

    QLinearGradient grGtoR(0, 0, 1, 100);
    grGtoR.setColorAt(1.0, Qt::darkGreen);
    grGtoR.setColorAt(0.5, Qt::yellow);
    grGtoR.setColorAt(0.2, Qt::red);
    grGtoR.setColorAt(0.0, Qt::darkRed);
    pmp.setBrush(QBrush(grGtoR));
    pmp.drawRect(0, 0, 24, 100);
    QPushButton *gradientGtoRPB = new QPushButton(widget);
    gradientGtoRPB->setIcon(QIcon(pm));
    gradientGtoRPB->setIconSize(QSize(24, 100));

    QHBoxLayout *colorHBox = new QHBoxLayout;
    colorHBox->addWidget(gradientBtoYPB);
    colorHBox->addWidget(gradientGtoRPB);
    colorGroupBox->setLayout(colorHBox);

    vLayout->addWidget(modelGroupBox);
    vLayout->addWidget(selectionGroupBox);
    vLayout->addWidget(new QLabel(QStringLiteral("Column range")));
    vLayout->addWidget(axisMinSliderX);
    vLayout->addWidget(axisMaxSliderX);
    vLayout->addWidget(new QLabel(QStringLiteral("Row range")));
    vLayout->addWidget(axisMinSliderZ);
    vLayout->addWidget(axisMaxSliderZ);
    vLayout->addWidget(new QLabel(QStringLiteral("Theme")));
    vLayout->addWidget(themeList);
    vLayout->addWidget(colorGroupBox);
    vLayout->addWidget(Sensitivity);
   // vLayout->addWidget(SensitivitySlider);

    vLayout->addWidget(axisMinSliderY);
    vLayout->addWidget(axisMaxSliderY);

   // vLayout->addWidget(onetimes);
 //   vLayout->addWidget(tentimes);
  //  vLayout->addWidget(less);
    vLayout->addWidget(com);
    vLayout->addWidget(box);
    vLayout->addWidget(start);
    vLayout->addWidget(stop);


    widget->show();



    SurfaceGraph *modifier = new SurfaceGraph(graph);

    QObject::connect(heightMapModelRB, &QRadioButton::toggled,
                     modifier, &SurfaceGraph::enableHeightMapModel);
    QObject::connect(sqrtSinModelRB, &QRadioButton::toggled,
                     modifier, &SurfaceGraph::enableSqrtSinModel);


//    QObject::connect(less, &QRadioButton::toggled,
//                     modifier, &SurfaceGraph::smaller);
//    QObject::connect(onetimes, &QRadioButton::toggled,
//                     modifier, &SurfaceGraph::same);
//    QObject::connect(tentimes, &QRadioButton::toggled,
//                     modifier, &SurfaceGraph::bigger);


//    QObject::connect(box, &QComboBox::currentData,
//                     modifier, &SurfaceGraph::test);
    QObject::connect(box, SIGNAL(currentTextChanged(QString)),
                     modifier, SLOT(test(QString)));





    QObject::connect(start, &QPushButton::pressed,                    //currentTextChanged(QString)),
                     modifier, &SurfaceGraph::begin);


    QObject::connect(stop, &QPushButton::pressed,                    //currentTextChanged(QString)),
                     modifier, &SurfaceGraph::stop);




    QObject::connect(modeNoneRB, &QRadioButton::toggled,
                     modifier, &SurfaceGraph::toggleModeNone);
    QObject::connect(modeItemRB,  &QRadioButton::toggled,
                     modifier, &SurfaceGraph::toggleModeItem);
    QObject::connect(modeSliceRowRB,  &QRadioButton::toggled,
                     modifier, &SurfaceGraph::toggleModeSliceRow);
    QObject::connect(modeSliceColumnRB,  &QRadioButton::toggled,
                     modifier, &SurfaceGraph::toggleModeSliceColumn);
    QObject::connect(axisMinSliderX, &QSlider::valueChanged,
                     modifier, &SurfaceGraph::adjustXMin);
    QObject::connect(axisMaxSliderX, &QSlider::valueChanged,
                     modifier, &SurfaceGraph::adjustXMax);
    QObject::connect(axisMinSliderZ, &QSlider::valueChanged,
                     modifier, &SurfaceGraph::adjustZMin);
    QObject::connect(axisMaxSliderZ, &QSlider::valueChanged,
                     modifier, &SurfaceGraph::adjustZMax);


    QObject::connect(axisMinSliderY, &QSlider::valueChanged,
                     modifier, &SurfaceGraph::adjustYMin);
    QObject::connect(axisMaxSliderY, &QSlider::valueChanged,
                     modifier, &SurfaceGraph::adjustYMax);

    QObject::connect(themeList, SIGNAL(currentIndexChanged(int)),
                     modifier, SLOT(changeTheme(int)));
    QObject::connect(gradientBtoYPB, &QPushButton::pressed,
                     modifier, &SurfaceGraph::setBlackToYellowGradient);
    QObject::connect(gradientGtoRPB, &QPushButton::pressed,
                     modifier, &SurfaceGraph::setGreenToRedGradient);

//    QObject::connect(SensitivitySlider, &QSlider::valueChanged,
//                     modifier, &SurfaceGraph::adjustSensitivity);



    modifier->setAxisMinSliderY(axisMinSliderY);
    modifier->setAxisMaxSliderY(axisMaxSliderY);

    modifier->setAxisMinSliderX(axisMinSliderX);
    modifier->setAxisMaxSliderX(axisMaxSliderX);
    modifier->setAxisMinSliderZ(axisMinSliderZ);
    modifier->setAxisMaxSliderZ(axisMaxSliderZ);
    //modifier->setSense(SensitivitySlider);

    sqrtSinModelRB->setChecked(true);
    modeItemRB->setChecked(true);
    themeList->setCurrentIndex(2);

//    box->setCurrentIndex(0);




    //modifier->fillSqrtSinProxy();




   //    QTimer*timer = new QTimer();
    //   QObject::connect(timer, /*&QTimer::timeout*/SIGNAL(timeout()), modifier, SLOT(fillSqrtSinProxy()));
   //    timer->start();



//   modifier->Timer();








  standardOutput << "loop 1" << endl;



    //}///////////////////////////////
   return app.exec();




}



//class MyThread:: public QThread
//{

//    Q_OBJECT
//{
//    QThread* thread = new QThread(parent);
//    connect(thread, SIGNAL(started()), this, SLOT(doWork()));
//    this->moveToThread(thread);
//    thread->start;
//}

