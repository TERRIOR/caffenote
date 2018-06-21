#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <caffe/caffe.hpp>
#include <string>
#include <caffeclassify.h>
#include "header.h"
#include "mytime.h"
using namespace caffe;
using namespace std;

int main(int argc,char* argv[]) {
    /* 自行设置文件名 */
    string model_file   = "caffenet.prototxt";
    string trained_file = "oxford2_iter_40000.caffemodel";
    string mean_file    = "coffeemean.binaryproto";
    string label_file   = "lable2.txt";
    string img_file     = "./train/1/baxi05.bmp";
    Classifier classifier(model_file, trained_file,mean_file,label_file);
    /* 自行调整获取图像的方式，格式，数据 */
    cv::Mat img = cv::imread(img_file,-1);
    cv::resize(img,img,cv::Size(227,227),(0,0),(0,0),3);
    CHECK(!img.empty()) << "Unable to decode image "<<endl;
    mytime timer;
    timer.TimerStart();
    std::vector<Prediction> predictions = classifier.Classify(img);
    cout<<"time: "<<timer.TimerFinish()<<endl;
    /* Print the top N predictions. */
    for (size_t i = 0; i < predictions.size(); ++i) {
      Prediction p = predictions[i];
      std::cout << std::fixed << std::setprecision(4) << p.second << " - \""
                << p.first << "\"" << std::endl;
    }
    return 0;
}
