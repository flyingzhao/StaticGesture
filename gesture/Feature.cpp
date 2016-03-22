#include "head.h"

/************************************************************************/
/*           Extract features of hand gesture                          */
/************************************************************************/

int FeatureExtract(Mat &Input,Mat FeaturePoints,Mat &Output){

	/*-----------------minAreaRect-----------------------*/

	RotatedRect box = minAreaRect(FeaturePoints); 
	Point2f vtx[4];
	box.points(vtx);//get the vertices of rectangle

	for( int i = 0; i < 4; i++ )  
	{
		line(Input, vtx[i], vtx[(i+1)%4], Scalar(255), 1, CV_AA);  
	}

	Output=Input;
	/*------------------Hu Moments----------------------*/
	Moments h;
	double hu[7];
	h=moments(Input,false);
	HuMoments(h,hu);
	
	/*-----------------------Area of Hand------------------*/
	double HandArea=FeaturePoints.total();


	/*-------------------Area of minRect--------------------*/
	double leng=sqrt((vtx[0].x-vtx[1].x)*(vtx[0].x-vtx[1].x)+(vtx[0].y-vtx[1].y)*(vtx[0].y-vtx[1].y));
	double width=sqrt((vtx[1].x-vtx[2].x)*(vtx[1].x-vtx[2].x)+(vtx[1].y-vtx[2].y)*(vtx[1].y-vtx[2].y));

	double MinrectArea=leng*width;

	double ratio=HandArea/MinrectArea;

	double feature[5]={hu[0],hu[1],hu[2],hu[3],ratio};
	
	/*----------------write into a txt file-------------------*/
	WriteIntoTxt(feature);

	return 1;
	
}