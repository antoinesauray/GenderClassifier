#pragma once
#include <vector>
#include "operation.hpp"

class pipeline{
    public:
    pipeline(std::vector<operation>);
    ~pipeline();
    private:
    std::vector<operation>& m_operations;
};