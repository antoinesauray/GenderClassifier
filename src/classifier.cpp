#include <iostream>
#include <opencv2/highgui.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "pipeline.hpp"
#include "operation.hpp"
#include "window.h"
#include "lbp.h"

#define DEBUG
#define WIDTH 100
#define HEIGHT 100

using namespace cv;
using namespace std;

void display_image(Mat image){
    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", image );                   // Show our image inside it.
    waitKey(0);
}

int main(int argc, char** argv){
    if(argc>1){
        cout << "Classifying " << argv[1] << endl;
        Mat image;
        image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
        if(!image.data){
            cout <<  "Could not open or find the image" << std::endl ;
            return EXIT_FAILURE;
        }
        //cvtColor( image, image, CV_BGR2GRAY );
        #ifdef DEBUG
        display_image(image);
        #endif
        cv::Mat resized_image;
        resize(image, resized_image, Size(WIDTH,HEIGHT));
        #ifdef DEBUG
        display_image(resized_image);
        #endif
        std::vector<cv::Mat> blocks = window(resized_image);
        for(auto &block : blocks){
            #ifdef DEBUG
            display_image(block);
            #endif
            cv::Mat hist;
            ELBP_<unsigned int>(block, hist, 2, 8);
            //equalizeHist(hist, hist);
            #ifdef DEBUG
            display_image(hist);
            #endif
        }
    }
    else {
        std::cout << "Please provide a path to an image for applying classification" << std::endl;
    }
}