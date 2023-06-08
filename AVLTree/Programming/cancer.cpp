#include "cancerdata.h"
#include <fstream>
#include <sstream>
#include "AVLTree.h"
#include <stdio.h>

/*ifs.rdbuf(); dumps all the information into a variable.*/

//explicit constructor.
cancerdata::cancerdata(std::string a, double b)
{
    
}

cancerdata::~cancerdata()
{

}

std::string cancerdata::getcountryname()
{    
    return pcountryname;
}

void cancerdata::setcountryname()
{
    
}

void cancerdata::ExtractingCancerMenFile()
{
    char delim =',';
   //cancerdata dat;
    
    int currentline;
    int line;
    int n;
    int get;
   
     std::string wholeline;
    
    std::ifstream datfile;
    datfile.open("mencancerdata2018.csv");
    if(datfile.is_open())
    {
     while(getline(datfile,pcountryname,delim))
     {
        std::cout<<"testing the file to see if it works:"<<std::endl;
        std::cout<<pcountryname<<"\n"<<std::endl;
     }
        
    }
    datfile.close();
/*
    while(getline(datfile,pcountryname,delim))
    {

       
       
        if(currentline == line)
        {
            getline (datfile, pcountryname,',');
           
        }
       currentline ++;
       
        
        
    }*/
    if(datfile.bad())//quick check to see if the file is bad.
    {
        std::cout<<"mencanerdata File failed to load"<<std::endl;
    }
}