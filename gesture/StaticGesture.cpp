/************************************************************************/
/*            Static Hand Gesture Recognition System with OpenCV       */
/************************************************************************/


#include "head.h"


int main(){
	printf("This is a program for hand gesture processing\n");
	printf("The input is a image,the output is the feature\n");
	printf("Now,let's start\n\n");
	
	Mat A,B,C;   
	Mat FeaturePoints;

	
	//CleanTxt();


	for(int i=0;i<3;i++){
		
	double start = (double)getTickCount();
		


	char in[4];
	itoa(i,in,10);
	string filename="E:/HandGesture/images/1/";
	filename.append(in).append(".jpg");
	cout<<filename<<"  "<<"is processing"<<" ";
	
	
	
	A=imread(filename);
	if (A.data)
	{
	//imshow("in",A);
	PreProcess(A,B);
	FindPoint(B,FeaturePoints);
	FeatureExtract(B,FeaturePoints,C);
	//imshow("out",B);
	//waitKey();

	}
	double count = ((double)getTickCount() - start)/getTickFrequency();
	cout<<"time "<<count<<"\n";

	
	}

	

	return 1;
	//imshow("out",C);
	//waitKey();

}