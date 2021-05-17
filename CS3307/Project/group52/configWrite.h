//
// Created by Gerrid on 2020-11-11.
//

#ifndef GROUP52_CONFIGWRITE_H
#define GROUP52_CONFIGWRITE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>



class configWrite {
    private:
        std::string fileName, delimeter;
        int linesCount;
            
    public:
        template<typename T>
        void addDatainRow(T first, T last);
        int configwrite();
        std::vector<std::string> dataList_1;
};


#endif //GROUP52_CONFIGWRITE_H
