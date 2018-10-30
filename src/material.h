//=================================================
//the class is defined as the shape of the material
//=================================================

#ifndef SP_H
#define SP_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string.h>
#include <stdlib.h>

using namespace std ;

//define
const int dim = 2 ;//dimension

//function and class prototype
class Node ;
class Elem ;

//main class
namespace equ{
class Shape{
    public:
        //data
        vector< Elem > elements ; //elements. index implay node number. values mean node numbaers.
        vector< Node > nodes ; //nodes. index implay node number. and Node class values means coordinations.
        vector< Aux > nauxes ; //auxiliary of nodes
        vector< Aux > nauxes ; //auxiliary of nodes
        string xml_ver ; //xml version
        string file_type ; //VTKFile type
        string file_type_ver ; //VTKFile type version
        string format ; //VTKFile format.

        //methods
        int export_vtk(string filename) ; //Export data.
        int import_vtk() ; //

        //initialize constructor
        Material(){
            xml_ver = '1.0' ;
            file_type = 'UnstructuredGrid' ;
            file_type_ver = '1.0' ;
        } ;
};

class Node{
    public:
        //data
        double coord[dim] ; //coordination

        //mothod
        double& operator[](int i){
            return coord[i] ;
        }
};

class Elem{
    public:
        //data
        vector< int > nodes ; //node nums
        string data_type ; //data type()

        //mothod
        double& operator[](int i){
            return coord[i] ;
        }
};

} //the end of the namespace "equ"

#endif
