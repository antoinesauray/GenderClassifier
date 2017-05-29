#pragma once
#include <opencv2/core.hpp>
#include "math.h"

#define N 25

std::vector<cv::Mat> window(cv::Mat img){
    std::vector<cv::Mat> ret;
    for (int r = 0; r < img.rows; r += N){
        for (int c = 0; c < img.cols; c += N){
            cv::Mat tile = img(cv::Range(r, std::min(r + N, img.rows)),
                        cv::Range(c, std::min(c + N, img.cols)));//no data copying here
            ret.push_back(tile);
        }
    }
    return ret;
}