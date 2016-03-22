#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> 
#include <stdio.h> 

using namespace cv;
using namespace std;

void CleanTxt();

int SkinDetective(Mat &Input);
int PreProcess(Mat &Input,Mat &Output);
int FindPoint(Mat Input,Mat &FeaturePoints);
int FeatureExtract(Mat &Input,Mat FeaturePoints,Mat &Output);
int WriteIntoTxt(double filetowrite[5]);