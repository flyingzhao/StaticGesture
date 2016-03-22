
/************************************************************************/
/*           clean the txt before write                                 */
/************************************************************************/

#include "head.h"
#include <fstream>




void CleanTxt(){
	ofstream ofile;
	ofile.open("1.txt",ios::trunc|ios::out);
	ofile.close();

}