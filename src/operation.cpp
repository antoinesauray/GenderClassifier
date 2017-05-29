#include "operation.hpp"

operation::operation(operation_func f, std::string desc){
    m_f = f
    m_desc = desc;
}

operation::~operation(){
    
}