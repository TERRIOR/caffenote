QT += core
QT -= gui

CONFIG += c++11

TARGET = testncs
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ncs_wrapper.cpp \
    fp16.cpp


HEADERS += \
    fp16.h \
    ncs_wrapper.hpp

INCLUDEPATH += /usr/local/include/opencv
INCLUDEPATH += /usr/local/include/opencv2

#pay attention that libopencv_core.so\ is"\"
LIBS +=-L/usr/local/lib
LIBS +=-lopencv_calib3d\
-lopencv_core\
-lopencv_highgui\
-lopencv_imgproc\
-lopencv_contrib\
-lopencv_video\
-lopencv_objdetect\
-lopencv_features2d
LIBS +=-lmvnc
