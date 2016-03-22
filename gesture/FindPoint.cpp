#include "head.h"

int FindPoint(Mat Input,Mat &FeaturePoints){
	vector<Point> points;  // a set of points
	int nr= Input.rows; // number of rows
	int nc= Input.cols; // total number of elements per line
	for (int j=0; j<nr; j++) {
		uchar* data= Input.ptr<uchar>(j);
		for (int i=0; i<nc; i++) {
			if (data[i]==255){ //count white points
				Point pt;
				pt.x=i;//x is col
				pt.y=j;//y is row
				points.push_back(pt);
			}
		}
	}

	FeaturePoints=Mat(points);
		cout<<FeaturePoints;
	return 1;
}