#include <iostream>

int main(int argc, char** argv){
    if(argc>1){
        std::cout << "Training with " << argv[1] << std::endl;
        return EXIT_SUCCESS;
    }
    else{
        std::cout << "Please provide a training set as argument" << std::endl;
        return EXIT_FAILURE;
    }
}