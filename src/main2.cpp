//================================
// read central line data and filter to correct
//================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std ;

//===setting====
int pre = 5 ; //precision of out put file data
double len = 0.005 ; //filter length[unit mm]
//==============

int main(int argc, char* argv[])
{
    ifstream ifs("line.dat");
    ofstream ofs("line_filtered.dat");
	string str;
	if(ifs.fail()) {
		cerr << "Error on open file.\n";
		return -1 ;
	}

	while(getline(ifs, str)) {
		double a[6];
		sscanf(str.c_str(), "%lf %lf %lf %lf %lf %lf", &a[0], &a[1],&a[2], &a[3],&a[4], &a[5]);

        //get data
        double length = 0 ;
        for (size_t i = 0; i < 3; i++) {
            length += (a[i]-a[i+3])*(a[i]-a[i+3]) ;
        }
        length = sqrt(length);

        //filtered and output
        if(length > len){
            for (size_t i = 0; i < 5; i++) {
                ofs << scientific << setprecision(pre) << uppercase << a[i] << " " ;
            }
            ofs << scientific << setprecision(pre) << uppercase << a[5] << "\n" ;
        }
	}

    ifs.close();
    return 0;
}
