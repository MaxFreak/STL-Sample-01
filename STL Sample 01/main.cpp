//
//  main.cpp
//  STL Sample 01
//
//  Created by Bernd Lappas on 04.03.13.
//  Copyright (c) 2013 Bernd Lappas. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";

    std::vector<int> v1,v2;
    
    v1.push_back(10);
    v1.push_back(11);
    v1.push_back(12);
    v1.push_back(13);

    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    
    v1.clear();
    for (std::vector<int>::const_iterator ci=v2.begin()+v2.size()/2; ci != v2.end(); ++ci)
    {
        v1.push_back(*ci);
    }
    
    v1.clear();
    
    v1.assign(v2.begin()+v2.size()/2, v2.end());
    
    for (std::vector<int>::const_iterator ci = v1.begin(); ci != v1.end(); ++ci)
    {
        std::cout << *ci << "\n";
    }
    return 0;
}

