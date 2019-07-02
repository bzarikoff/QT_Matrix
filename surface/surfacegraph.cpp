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

#include <QtDataVisualization/QValue3DAxis>
#include <QtDataVisualization/Q3DTheme>
#include <QtGui/QImage>
#include <QtCore/qmath.h>
#include <QtSerialPort/QSerialPort>
#include <QTimer>
#include <QtWidgets/QApplication>
#include <stdlib.h>
#include <sstream>

#include <QSerialPort>
#include <QSerialPortInfo>

int integertest[16][24];
QSerialPort serial;

const int sampleCountX = 24;//50;
const int sampleCountZ = 16;//50;
const int heightMapGridStepX = 1;
const int heightMapGridStepZ = 1;
const float sampleMin = 0.0f;//-24.0f;//-8.0f;
const float sampleMax = 24.0f;//8.0f;

float sensitivity = 1;

SurfaceGraph::SurfaceGraph(Q3DSurface *surface)
    : m_graph(surface)
{
    m_graph->setAxisX(new QValue3DAxis);
    m_graph->setAxisY(new QValue3DAxis);
    m_graph->setAxisZ(new QValue3DAxis);

    //! [0]
    m_sqrtSinProxy = new QSurfaceDataProxy();
    m_sqrtSinSeries = new QSurface3DSeries(m_sqrtSinProxy);
    //! [0]
    //!
    //!
//            QTimer*timer = new QTimer(this);
//            QObject::connect(timer, SIGNAL(timeout()), this, SLOT(fillSqrtSinProxy()));
//            timer->start(100);
   // fillSqrtSinProxy();
   // test(box);
   // timerId = startTimer(100);
   // setGreenToRedGradient();

    //! [2]
    QImage heightMapImage(":/maps/mountain");
    m_heightMapProxy = new QHeightMapSurfaceDataProxy(heightMapImage);
    m_heightMapSeries = new QSurface3DSeries(m_heightMapProxy);
    m_heightMapSeries->setItemLabelFormat(QStringLiteral("(@xLabel, @zLabel): @yLabel"));
    m_heightMapProxy->setValueRanges(34.0f, 40.0f, 18.0f, 24.0f);
    //! [2]
    m_heightMapWidth = heightMapImage.width();
    m_heightMapHeight = heightMapImage.height();

  //   fillSqrtSinProxy();

//    QTimer*timer = new QTimer(this);
//    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(fillSqrtSinProxy()));
//    timer->start(100);



}

SurfaceGraph::~SurfaceGraph()
{
    delete m_graph;
}

void SurfaceGraph::timerEvent(QTimerEvent *event)
{
    //qDebug() << "Update  1";
    if(&SurfaceGraph::enableSqrtSinModel){
       fillSqrtSinProxy();
    }
}

void SurfaceGraph::smaller(bool enable)
{
    if (enable) {

        sensitivity = 0.1;


    }



}
void SurfaceGraph::same(bool enable)
{
    if (enable) {

        sensitivity = 1;



    }



}
void SurfaceGraph::bigger(bool enable)
{
    if (enable) {

        sensitivity = 10;


    }



}
void SurfaceGraph::begin()
{
    QTextStream standardOutput(stdout);
    standardOutput << "test" << endl;

    QString portname;
    QString port1;
    int count = 0;


  //  QSerialPortInfo objectconst;

    //portname = objectconst.portName();

    Q_FOREACH(QSerialPortInfo objectconst, QSerialPortInfo::availablePorts()) {

        if(count == 0){
       port1 = objectconst.portName();
       standardOutput << portname << endl;
       count = 1;
        }
        else{
            standardOutput << "no" << endl;
             standardOutput << portname << endl;
        }

    }


//    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
//        box->addItem(port.portName());
//    }



//    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
//        box->addItem(port.portName());
//    }

    test(port1);
}



void SurfaceGraph::test(QString box)
{

       QTextStream standardOutput(stdout);
       standardOutput << box << endl;

       int flag;
       int enable;






     //  QTextStream standardOutput(stdout);
       QByteArray data, data2;


       serial.setPortName(box);//COM4
       serial.setBaudRate(QSerialPort::Baud9600); /*, QSerialPort::Output*/
       serial.setDataBits(QSerialPort::Data8);
       serial.setParity(QSerialPort::NoParity);
       serial.setStopBits(QSerialPort::TwoStop);
       serial.setFlowControl(QSerialPort::NoFlowControl);
       serial.open(QIODevice::ReadWrite);




       if(!serial.isOpen()){
           standardOutput << "this port is not currently open\r\n" << endl;
           flag = 0;
           enable = 0;

       }
       if(serial.isOpen()){
           standardOutput << "this port is now opennnnnnnnnnnnnnnnnn\r\n" << endl;
           flag = 1;
           enable = 1;
       }

        if(enable == 1){


       //Setup Command
       serial.write("!sm\r\n");
       standardOutput << "!SM\r\n" << endl;
       serial.waitForReadyRead();


   data = serial.readLine();
while(data.isNull() == TRUE){
   data = serial.readLine();
}
//if(data[0] == 'N'){
//     standardOutput << "N is present" << endl;
//}
standardOutput << data << endl;


       //Set Columns Number
       serial.write("!nc24\r\n");
       standardOutput << "!NC24\r\n" << endl;
       serial.waitForReadyRead();
//        data = serial.readLine();
//        if(data != "\n")
//            standardOutput << data << endl;
//        serial.waitForReadyRead();

//        while(data != "Number of col 24"){
//        data = serial.readLine();
//        }
//         standardOutput << data <<


         //   data = serial.readLine();
            data = serial.readLine();

        while(data[0] != 'N'){
          // while(data.isNull() == TRUE ){ // || data[0] == '\n'){
            serial.waitForReadyRead();
            data = serial.readLine();
            // standardOutput << "check" << endl;
        }
         standardOutput << data << endl;
         standardOutput << "above" << endl;



     //Set Rows Number
        serial.write("!nr16\r\n");
        standardOutput << "!NR24\r\n" << endl;
        serial.waitForReadyRead();
//         data = serial.readLine();
//         standardOutput << data << endl;
//         serial.waitForReadyRead();

//         while(data != "Number of row 16"){
//         data = serial.readLine();
//         }
//           standardOutput << data << endl;
            data = serial.readLine();
             while(data[0] != 'N'){
          //while(data.isNull() == TRUE){
                 serial.waitForReadyRead();
              data = serial.readLine();
          }
           standardOutput << data << endl;


         //Set Delay
         serial.write("!sd10\r\n");
         standardOutput << "!SD10\r\n" << endl;
         serial.waitForReadyRead();
//          data = serial.readLine();
//          serial.waitForReadyRead();

//          while(data != "Sampling Delay 10"){
//              data = serial.readLine();
//          }
//          standardOutput << data << endl;
            data = serial.readLine();
            while(data[0] != 'S'){
            serial.waitForReadyRead();
       //  while(data.isNull() == TRUE){
             data = serial.readLine();
         }
          standardOutput << data << endl;




          //Start Sampling
       serial.write("!ss\r\n");
       standardOutput << "!ss\r\n" << endl;
       serial.waitForReadyRead();
//        data = serial.readLine();
//        serial.waitForReadyRead();

//        while(data != "Sampling Matrix"){
//            data = serial.readLine();
//        }
//        standardOutput << data << endl;
       data = serial.readLine();
         while(data[0] != 'S'){
   //    while(data.isNull() == TRUE){
             serial.waitForReadyRead();
           data = serial.readLine();
       }
        standardOutput << data << endl;


        if(flag == 1){
            timerId = startTimer(100);

        }


}

}

/*//void SurfaceGraph::Timer()
{
        QTimer*timer = new QTimer(this);
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(fillSqrtSinProxy()));
        timer->start(100);
}  */    //added this to header and main to attempt to call fillsqrt every 100 ms


void SurfaceGraph::fillSqrtSinProxy()
{
    float stepX = (sampleMax - sampleMin) / float(sampleCountX - 1);
    float stepZ = (sampleMax - sampleMin) / float(sampleCountZ - 1);
    QSurfaceDataArray *dataArray = new QSurfaceDataArray;
    dataArray->reserve(sampleCountZ);

    int j = 0;
    int i = 0;
    int k = 0;
    int p = 0;
    int count;




    QTextStream standardOutput(stdout);
    QByteArray data;
    const char * point;
    char data2[200];




    serial.write("!rm\r\n");
  //  standardOutput << "!RM\r\n" << endl;


//    serial.waitForReadyRead();
//    data = serial.readLine();
//    while(data.isNull()){
//    data = serial.readLine();
//    count++;
//    if(count==10){
//        count = 0;
//        serial.write("!rm\r\n");
//            }
//    }
 //serial.waitForReadyRead();
//***********************************************************************************************//
//Begin Reading Matrix
//***********************************************************************************************//
  //standardOutput << "matrix" << endl;
  while(j<16){

   //  standardOutput << "before1" << endl;
     serial.waitForReadyRead(10);
     //while(data.isNull() == TRUE){
   //  standardOutput << "before2" << endl;
      data = serial.readLine();
   //   standardOutput << "after" << endl;
      //serial.readLine(data2, 200);
   //  }

//***********************************************************************************************//
//Only Process data and increment column pointer if data is valid
//***********************************************************************************************//

              if(data[0] == '0' || data[0] == '1' || data[0] == '2' || data[0] == '3' || data[0] == '4' || data[0] == '5' || data[0] == '6' || data[0] == '7' || data[0] == '8' || data[0] == '9'){
              //if(data.isNull() == FALSE){        //data != "\n"){
                   //   standardOutput << data << endl;
                      //standardOutput << data2 << endl;
                      point = data.constData();//pointer to a row of data
                      p = 0;//set pointer index to 0 in order to iterate through columns of row
                      k = 0;//for iterating through columns of integer array
               //   standardOutput << "here" << endl;
                      QSurfaceDataRow *newRow = new QSurfaceDataRow(sampleCountX);
                      float z = j;
                      int index = 0;
                 //    standardOutput << point << endl;

//***********************************************************************************************//
//point is a const char pointer to a row of matrix data - increment through and
//convert to a form to be graphed
//***********************************************************************************************//

                      while(point[p]){

//                              if(point[p+2] == NULL){
//                                  standardOutput << k << endl;
//                                  standardOutput << j << endl;
//                              }
                         //  standardOutput << point[p] << endl;


                                  if(point[p] == ','){
                                      p++;
                                  }// if element is a comma move on

                                  else if(point[p] == NULL){
                                      break;
                                  } // if is NULL do nothing - should never get here as while checks for this


                                  else{ //if there is a point to graph




                                      //Force is four digits
                                         if(point[p+3] != ',' && point[p+3] != NULL && point[p+2] != ',' && point[p] != ',' && point[p+1] != ',' && point[p+2] != NULL && point[p+1] != NULL){
                                            if(k<24){
                                            //integertest[j][k] = (point[p]*10 + point[p+1]) - '0';
                                          std::stringstream strValue;
                                          std::stringstream strValuehundred;
                                          std::stringstream strValuethousand;
                                          int hundred;
                                          int thousand;
                                          strValue << point[p];
                                          strValue >> integertest[j][k];
                                          strValuehundred << point[p+1];
                                          strValuehundred >> hundred;
                                          strValuethousand << point[p+2];
                                          strValuethousand >> thousand;
                                          integertest[j][k] = integertest[j][k]*1000 + hundred*100+ thousand*10 + (point[p+2] - '0');
                                        //   standardOutput << integertest[j][k] << endl;
                                          float x = k;
                                          if(integertest[j][k] == 1){ //clipping filter - 1 is not a useful value
                                              integertest[j][k] = 0;
                                          }
                                          float y = integertest[j][k] * sensitivity;
                                   //       standardOutput << integertest[j][k] << endl;
      //                                        if(j==0 && k == 0){
      //                                            y = 50;
      //                                        }
      //                                        if(j==15 && k == 23){
      //                                            y = 52;
      //                                        }
                                          (*newRow)[index++].setPosition(QVector3D(x, y, z));
                                           k++;
                                            }
                                    //   k++;
                                       p=p+4;
                                        }//if element is greater than 999 will occupy four indexes of char array - must store both these elements in
                                         //one index of the integer array







                                      //Force is three digits
                                         else if(point[p+2] != ',' && point[p] != ',' && point[p+1] != ',' && point[p+2] != NULL && point[p+1] != NULL){
                                            if(k<24){
                                            //integertest[j][k] = (point[p]*10 + point[p+1]) - '0';
                                          std::stringstream strValue;
                                          std::stringstream strValuehundred;
                                          int hundred;
                                          strValue << point[p];
                                          strValue >> integertest[j][k];
                                          strValuehundred << point[p+1];
                                          strValuehundred >> hundred;
                                          integertest[j][k] = integertest[j][k]*100 + hundred*10+(point[p+2] - '0');
                                        //   standardOutput << integertest[j][k] << endl;
                                          float x = k;
                                          if(integertest[j][k] == 1){
                                              integertest[j][k] = 0;
                                          }
                                          float y = integertest[j][k] * sensitivity;
                                         standardOutput << integertest[j][k] << endl;
                                         standardOutput << "space" << endl;
                                         standardOutput << hundred << endl;
      //                                        if(j==0 && k == 0){
      //                                            y = 50;
      //                                        }
      //                                        if(j==15 && k == 23){
      //                                            y = 52;
      //                                        }
                                          (*newRow)[index++].setPosition(QVector3D(x, y, z));
                                           k++;
                                            }
                                    //   k++;
                                       p=p+3;
                                        }//if element is greater than 99 will occupy three indexes of char array - must store both these elements in
                                         //one index of the integer array











                                //Force is two digits
                                   else if(point[p+1] != ',' && point[p] != ',' && point[p+1] != NULL){
                                      if(k<24){
                                      //integertest[j][k] = (point[p]*10 + point[p+1]) - '0';
                                    std::stringstream strValue;
                                    strValue << point[p];
                                    strValue >> integertest[j][k];
                                    integertest[j][k] = integertest[j][k]*10 + (point[p+1] - '0');
                                  //   standardOutput << integertest[j][k] << endl;
                                    float x = k;
                                    if(integertest[j][k] == 1){
                                        integertest[j][k] = 0;
                                    }
                                    float y = integertest[j][k] * sensitivity;
                             //       standardOutput << integertest[j][k] << endl;
//                                        if(j==0 && k == 0){
//                                            y = 50;
//                                        }
//                                        if(j==15 && k == 23){
//                                            y = 52;
//                                        }
                                    (*newRow)[index++].setPosition(QVector3D(x, y, z));
                                     k++;
                                      }
                              //   k++;
                                 p=p+2;
                                  }//if element is greater than 9 will occupy two indexes of char array - must store both these elements in
                                   //one index of the integer array


                                  else{

                                        //Force is one digits
                                                if(k<24){
                                              integertest[j][k] =  point[p] - '0';
                    //                          std::stringstream strValue;
                        //                          strValue << point[p];
                        //                          strValue >> integertest[j][k];
                        //                          integertest[j][k] = integertest[j][k]*10;
                                                  //standardOutput << integertest[j][k] << endl;
                                                  float x = k;
                                                  if(integertest[j][k] == 1){
                                                      integertest[j][k] = 0;
                                                  }
                                                  float y =  integertest[j][k] * sensitivity;
                                         //         standardOutput << integertest[j][k] << endl;

//                                                  if(k==23 || k ==0){
//                                                      y = 24;
//                                                  }
//                                                  if(j==0 || j==15){
//                                                      y = 32;
//                                                  }
                                                  (*newRow)[index++].setPosition(QVector3D(x, y, z));
                                                   k++;
                                                  // p++;
                                          }
                                     //  k++;
                                       p++;
                                        }





                                       }




                                   }
                              //}


                      j++;// data was valid so get to next row of matrix
                      *dataArray << newRow;
                  //     standardOutput << "row" << endl;
              }


  }























//  //  QSurfaceDataArray *dataArray = new QSurfaceDataArray;
//  //  dataArray->reserve(sampleCountZ);
//    for (int i = 0 ; i < 16/*sampleCountZ*/ ; i++) {
//        QSurfaceDataRow *newRow = new QSurfaceDataRow(sampleCountX);
//        // Keep values within range bounds, since just adding step can cause minor drift due
//        // to the rounding errors.
//        float z = i;//qMin(sampleMax, (i * stepZ + sampleMin));
//        int index = 0;
//        for (int j = 0; j < 24/*sampleCountX*/; j++) {
//            float x = j;//qMin(sampleMax, (j * stepX + sampleMin));
//         //   float R = qSqrt(z * z + x * x) + 0.01f;
//            float y =  integertest[(int)z][(int)x];// (qSin(R) / R + 0.24f) * 1.61f;//integertest[(int)z][(int)x];  put matrix data
//            (*newRow)[index++].setPosition(QVector3D(x, y, z));
//        }
//        *dataArray << newRow;
//    }
 // standardOutput << "graph" << endl;
    m_sqrtSinProxy->resetArray(dataArray);
}
//! [1]

void SurfaceGraph::enableSqrtSinModel(bool enable)
{
    if (enable) {
        //! [3]
        m_sqrtSinSeries->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
        m_sqrtSinSeries->setFlatShadingEnabled(true);

        m_graph->axisX()->setLabelFormat("%.2f");
        m_graph->axisZ()->setLabelFormat("%.2f");
        m_graph->axisX()->setRange(sampleMin, sampleMax);
        m_graph->axisY()->setRange(0.0f, 50.0f);//2.0f
        m_graph->axisZ()->setRange(sampleMin, sampleMax);
        m_graph->axisX()->setLabelAutoRotation(30);
        m_graph->axisY()->setLabelAutoRotation(90);
        m_graph->axisZ()->setLabelAutoRotation(30);

        m_graph->removeSeries(m_heightMapSeries);
        m_graph->addSeries(m_sqrtSinSeries);
        //! [3]

        //! [8]
        // Reset range sliders for Sqrt&Sin
        m_rangeMinX = sampleMin;
        m_rangeMinZ = sampleMin;
        m_stepX = (23.0f) / float(sampleCountX - 1);
        m_stepZ = (15.0f) / float(sampleCountZ - 1); //sampleMax - sampleMin
        m_axisMinSliderX->setMaximum(sampleCountX - 2);
        m_axisMinSliderX->setValue(0);
        m_axisMaxSliderX->setMaximum(sampleCountX - 1);
        m_axisMaxSliderX->setValue(sampleCountX - 1);
        m_axisMinSliderZ->setMaximum(sampleCountZ - 2);
        m_axisMinSliderZ->setValue(0);
        m_axisMaxSliderZ->setMaximum(sampleCountZ - 1);
        m_axisMaxSliderZ->setValue(sampleCountZ - 1);
        //! [8]

//        QTimer*timer = new QTimer(this);
//        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(fillSqrtSinProxy()));
//        timer->start(100);



        //fillSqrtSinProxy();


    }
}

void SurfaceGraph::enableHeightMapModel(bool enable)
{
    if (enable) {
        //! [4]
        m_heightMapSeries->setDrawMode(QSurface3DSeries::DrawSurface);
        m_heightMapSeries->setFlatShadingEnabled(false);

        m_graph->axisX()->setLabelFormat("%.1f N");
        m_graph->axisZ()->setLabelFormat("%.1f E");
        m_graph->axisX()->setRange(34.0f, 40.0f);
        m_graph->axisY()->setAutoAdjustRange(true);
        m_graph->axisZ()->setRange(18.0f, 24.0f);

        m_graph->axisX()->setTitle(QStringLiteral("Latitude"));
        m_graph->axisY()->setTitle(QStringLiteral("Height"));
        m_graph->axisZ()->setTitle(QStringLiteral("Longitude"));

        m_graph->removeSeries(m_sqrtSinSeries);
        m_graph->addSeries(m_heightMapSeries);
        //! [4]

        // Reset range sliders for height map
        int mapGridCountX = m_heightMapWidth / heightMapGridStepX;
        int mapGridCountZ = m_heightMapHeight / heightMapGridStepZ;
        m_rangeMinX = 34.0f;
        m_rangeMinZ = 18.0f;
        m_stepX = 6.0f / float(mapGridCountX - 1);
        m_stepZ = 6.0f / float(mapGridCountZ - 1);
        m_axisMinSliderX->setMaximum(mapGridCountX - 2);
        m_axisMinSliderX->setValue(0);
        m_axisMaxSliderX->setMaximum(mapGridCountX - 1);
        m_axisMaxSliderX->setValue(mapGridCountX - 1);
        m_axisMinSliderZ->setMaximum(mapGridCountZ - 2);
        m_axisMinSliderZ->setValue(0);
        m_axisMaxSliderZ->setMaximum(mapGridCountZ - 1);
        m_axisMaxSliderZ->setValue(mapGridCountZ - 1);
    }
}

void SurfaceGraph::adjustXMin(int min)
{
    float minX = m_stepX * float(min) + m_rangeMinX;

    int max = m_axisMaxSliderX->value();
    if (min >= max) {
        max = min + 1;
        m_axisMaxSliderX->setValue(max);
    }
    float maxX = m_stepX * max + m_rangeMinX;

    setAxisXRange(minX, maxX);
}

void SurfaceGraph::adjustXMax(int max)
{
    float maxX = m_stepX * float(max) + m_rangeMinX;

    int min = m_axisMinSliderX->value();
    if (max <= min) {
        min = max - 1;
        m_axisMinSliderX->setValue(min);
    }
    float minX = m_stepX * min + m_rangeMinX;

    setAxisXRange(minX, maxX);
}

void SurfaceGraph::adjustZMin(int min)
{
    float minZ = m_stepZ * float(min) + m_rangeMinZ;

    int max = m_axisMaxSliderZ->value();
    if (min >= max) {
        max = min + 1;
        m_axisMaxSliderZ->setValue(max);
    }
    float maxZ = m_stepZ * max + m_rangeMinZ;

    setAxisZRange(minZ, maxZ);
}

void SurfaceGraph::adjustZMax(int max)
{
    float maxX = m_stepZ * float(max) + m_rangeMinZ;

    int min = m_axisMinSliderZ->value();
    if (max <= min) {
        min = max - 1;
        m_axisMinSliderZ->setValue(min);
    }
    float minX = m_stepZ * min + m_rangeMinZ;

    setAxisZRange(minX, maxX);
}

//! [5]
void SurfaceGraph::setAxisXRange(float min, float max)
{
    m_graph->axisX()->setRange(min, max);
}

void SurfaceGraph::setAxisZRange(float min, float max)
{
    m_graph->axisZ()->setRange(min, max);
}
//! [5]

//! [6]
void SurfaceGraph::changeTheme(int theme)
{
    m_graph->activeTheme()->setType(Q3DTheme::Theme(theme));
}
//! [6]

void SurfaceGraph::setBlackToYellowGradient()
{
    //! [7]
    QLinearGradient gr;
    gr.setColorAt(0.0, Qt::black);
    gr.setColorAt(0.33, Qt::blue);
    gr.setColorAt(0.67, Qt::red);
    gr.setColorAt(1.0, Qt::yellow);

    m_graph->seriesList().at(0)->setBaseGradient(gr);
    m_graph->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
    //! [7]
   // fillSqrtSinProxy();


}

void SurfaceGraph::setGreenToRedGradient()
{
    QLinearGradient gr;
    gr.setColorAt(0.0, Qt::darkGreen);
    gr.setColorAt(0.5, Qt::yellow);
    gr.setColorAt(0.8, Qt::red);
    gr.setColorAt(1.0, Qt::darkRed);

    m_graph->seriesList().at(0)->setBaseGradient(gr);
    m_graph->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
   // fillSqrtSinProxy();

}

