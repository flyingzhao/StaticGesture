/************************************************************************/
/*        SkinDetective        H<1.6||H>5.6&&I>100&&S<0.88&&S>0.1       */
/************************************************************************/


#include "head.h"
#include<math.h>
const double pi=3.1416;
double minab(double a,double b){
	if (a<b)
	{return a;
	} 
	else
	{return b;
	}
}
int SkinDetective(Mat &Input){
	int nr= Input.rows; // number of rows
	int nc= Input.cols; // total number of elements per line
	for (int j=0; j<nr; j++) {
		uchar* data= Input.ptr<uchar>(j);
		for (int i=0; i<nc; i++) {
			/************************************************************************/
			/*        RGB2HSI                                                     */
			/************************************************************************/
			double B= data[3*i];//B
			double G=data[3*i+1];//G
			double R=data[3*i+2]; //R 
			double num=0.5*((R-G)+(R-B));
			double den=sqrt((R-G)*(R-G)+(R-B)*(G-B));
			double theta=acos(num/den);
			double H;
			if(B<=G){H=theta;}
			else{H=2*pi-theta;}
			double I=(R+G+B)/3;
			double minrgb=minab(minab(R,G),B);
			double S=1-3/(R+G+B)*minrgb;
		
			/************************************************************************/
			/*        SkinDetective        H<1.6||H>5.6&&I>100&&S<0.88&&S>0.1       */
			/************************************************************************/

			if (H<1.6||H>5.6&&I>100&&S<0.88&&S>0.1) {I=255;S=0;H=0;}//white
			else {I=0;S=0;H=0;}//black



			/************************************************************************/
			/*              HSI2RGB                                                 */
			/************************************************************************/
			if(H<2*pi/3){
				B=I*(1-S);
				num=S*cos(H);
				den=cos(pi/3-H);
				R=I*(1+num/den);
				G=3*I-(R+B);
			}
			else if(H<pi*4/3){
				H=H-2*pi/3;
				R=I*(1-S);
				num=S*cos(H);
				den=cos(pi/3-H);
				G=I*(1+num/den);
				B=3*I-(R+B);
			}
			else if(H<2*pi){
				H=H-4*pi/3;
				G=I*(1-S);
				num=S*cos(H);
				den=cos(pi/3-H);
				B=I*(1+num/den);
				R=3*I-(R+B);
			}
			data[3*i]=(uchar) B;
			data[3*i+1]=(uchar) G;
			data[3*i+2]=(uchar) R;
		}
	}
	return 1;
}