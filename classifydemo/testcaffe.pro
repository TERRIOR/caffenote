QT += core
QT -= gui
DEFINES+=USE_OPENCV
#DEFINES+=CPU_ONLY
CONFIG += c++11

INCLUDEPATH += E:\caffe\cudainclude\include
INCLUDEPATH += C:\Users\zhuojun\.caffe\dependencies\libraries_v120_x64_py27_1.1.0\libraries\include\opencv
INCLUDEPATH += E:\caffe\caffe\include
INCLUDEPATH += E:\caffe\caffe\scripts\build
INCLUDEPATH += E:\caffe\caffe\scripts\build\include
INCLUDEPATH += C:\Users\zhuojun\.caffe\dependencies\libraries_v120_x64_py27_1.1.0\libraries\include
INCLUDEPATH += C:\Users\zhuojun\.caffe\dependencies\libraries_v120_x64_py27_1.1.0\libraries\include\boost-1_61

LIBS += -LE:\caffe\caffe\scripts\build\lib\Release
LIBS += -lcaffe -lcaffeproto

LIBS += -LC:\Users\zhuojun\.caffe\dependencies\libraries_v120_x64_py27_1.1.0\libraries\lib
LIBS += -lglog -lgflags  -llmdb -lleveldb -llibprotobuf -llmdb
LIBS += -lsnappy -lcaffehdf5_hl -lcaffehdf5 -lcaffezlib
LIBS += libopenblas.dll.a

LIBS += -LC:\Users\zhuojun\.caffe\dependencies\libraries_v120_x64_py27_1.1.0\libraries\lib

LIBS += -LE:\caffe\boost_1_61_0\lib64-msvc-12.0
LIBS += -lboost_chrono-vc120-mt-1_61
LIBS += -lboost_filesystem-vc120-mt-1_61
LIBS += -lboost_system-vc120-mt-1_61
LIBS += -lboost_thread-vc120-mt-1_61
LIBS += -lboost_python-vc120-mt-1_61


LIBS += -L'C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v8.0\lib\x64'
LIBS += -lcublas -lcublas_device -lcuda -lcudadevrt -lcudart -lcudart_static -lcudnn -lcufft -lcufftw
LIBS += -lcurand -lcusolver -lcusparse -lnppc -lnppi -lnpps -lnvblas -lnvcuvid -lnvrtc -lOpenCL

LIBS += -LE:\Anaconda2\libs
LIBS += -lpython27

win32:CONFIG(debug, debug|release): {
LIBS += -LE:\opencv\opencv\build\x64\vc12\lib \
-lopencv_objdetect2412d\
-lopencv_ts2412d\
-lopencv_video2412d\
-lopencv_nonfree2412d\
-lopencv_ocl2412d\
-lopencv_photo2412d\
-lopencv_stitching2412d\
-lopencv_superres2412d\
-lopencv_videostab2412d\
-lopencv_calib3d2412d\
-lopencv_contrib2412d\
-lopencv_core2412d\
-lopencv_features2d2412d\
-lopencv_flann2412d\
-lopencv_gpu2412d\
-lopencv_highgui2412d\
-lopencv_imgproc2412d\
-lopencv_legacy2412d\
-lopencv_ml2412

} else:win32:CONFIG(release, debug|release): {
LIBS += -LE:\opencv310\opencv\build\x64\vc12\lib
LIBS += -lopencv_world310
}

TARGET = testcaffe
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mytime.cpp \
    caffeclassify.cpp

HEADERS += \
    header.h \
    mytime.h \
    caffeclassify.h
