#pragma once
#include <opencv2/core.hpp>

typedef cv::Mat* (*operation_func)(cv::Mat*);

class operation{
    public:
    operation(operation_func, std::string);
    ~operation();
    private:
    operation_func m_f;
    std::string m_desc;
};