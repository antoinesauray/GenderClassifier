#include "pipeline.hpp"

pipeline::pipeline(std::vector<operation>& operations){
    this->m_operations=operations;
}

pipeline::~pipeline(){
    
}