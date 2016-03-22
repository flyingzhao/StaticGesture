/************************************************************************/
/*               write the feature into txt file                       */
/************************************************************************/



#include "head.h"
#include "fstream"
#include <iomanip>

int WriteIntoTxt(double filetowrite[5]){
	std::ofstream ofile;
	ofile.open("1.txt",ios::out|ios::app);
	for(int i=0;i<5;i++){
		if(i==0) ofile<<"1 "<<i<<":"<<filetowrite[i]<<" ";
		if(i!=4&&i!=0) ofile<<i<<":"<<filetowrite[i]<<" ";
		if(i==4) {ofile<<i<<":"<<filetowrite[i]<<'\n';}
	}
	ofile.close();
	return 1;
}