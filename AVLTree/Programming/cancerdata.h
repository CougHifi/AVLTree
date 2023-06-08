#pragma once
#include<iostream>
#include<string>



class cancerdata
{
    public:
    cancerdata();
    explicit cancerdata(std::string a, double b);
    ~cancerdata();
    void ExtractingCancerMenFile();
    void ExtractingCancerWomenFile();
    void ExtractingMenandWomenFile();
    std::string getcountryname();
    void setcountryname();
    private:
    std::string pcountryname;
    float pcancerRate;
};