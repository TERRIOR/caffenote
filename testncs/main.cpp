#include <opencv2/opencv.hpp>

#include <iostream>
#include <fstream>
#include <ctime>

#include <iomanip>
//Neural compute stick
#include <mvnc.h>
#include <ncs_wrapper.hpp>

using namespace std;
using namespace cv;
//修改配置
#define NETWORK_INPUT_SIZE  224
#define NETWORK_OUTPUT_SIZE 1000

//NCS的使用流程
//1，读取ncs的设备名称
//2，打开ncs设备
//3，读取graph
//3.1 graph需要预处理
//4，运行
//5，获取结果

int main()
{
    string img_file     = "./nps_electric_guitar.png";
    string graph_file     = "./graph";
    string mean_file     = "./mean.jpg";

    //NCS interface 初始化
    NCSWrapper NCS(NETWORK_INPUT_SIZE, NETWORK_OUTPUT_SIZE,3,true,false);
    //Start communication with NCS 读取graph
    if (!NCS.load_file(graph_file.c_str()))
      return 0;
    //读取文件
    Mat frame=imread(img_file);
    cout<<frame.size()<<endl;
    if(frame.empty())
        return 0;
    Mat resized16f;
    float* result;
    //Capture-Render cycle 计数
    //transform frame 转换 可选择是否运行
    Mat meanImg(NETWORK_INPUT_SIZE, NETWORK_INPUT_SIZE, CV_32FC3, Scalar(0.40787054*255.0, 0.45752458*255.0, 0.48109378*255.0));
    NCS.setmean(meanImg);
//    double scale=1/255;
//    NCS.setscale(scale);

    //此处开始分类
    int64 start = getTickCount();
    //图片处理
    NCS.process(frame,resized16f);
    //加载图片
    if(!NCS.load_tensor((float*)resized16f.data, result))
    {
      if (NCS.ncsCode == MVNC_MYRIAD_ERROR)
      {
        char* err;
        unsigned int len;
        mvncGetGraphOption(NCS.ncsGraph, MVNC_DEBUG_INFO, (void*)&err, &len);
        cout<<string(err, len)<<endl;
      }
    }
    //读取 result 排序即可获取最大概率的分类 不需要后续函数
    float maxResult = 0.0;
    int maxIndex=0;
    for (size_t i = 0; i <NETWORK_OUTPUT_SIZE ; ++i) {
        if (result[i] > maxResult)
        {
            maxResult = result[i];
            maxIndex = i;
        }
    }
    printf("Index of top result is: %d\n", maxIndex);
    printf("Probability of top result is: %f\n", result[maxIndex]);
    double time = (getTickCount()-start)/getTickFrequency();
    cout<<"time: "<<time<<endl;
}
