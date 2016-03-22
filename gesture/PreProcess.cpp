/************************************************************************/
/*                    pre-processing                                    */
/*                    Input:Image  Output:Border                        */
/************************************************************************/

#include "head.h"

int PreProcess(Mat &Input,Mat &Output){
	Mat A=Input;
	Mat B;
	GaussianBlur(A,B,Size(7,7),0,0,BORDER_DEFAULT);
	//medianBlur(B,B,15);
	SkinDetective(B);
	Mat element=getStructuringElement(MORPH_RECT,Size(7,7));
	morphologyEx(B,B,MORPH_OPEN,element);//morphology
	medianBlur(B,B,25);//medianblur
	cvtColor(B,B,CV_BGR2GRAY);//BGR2GRAY
	//GaussianBlur(B,B,Size(5,5),0,0,BORDER_DEFAULT);
	//Canny(B,B,1,3);//extract border
	Output=B;
	return 1;
}