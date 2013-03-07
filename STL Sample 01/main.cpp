//
//  main.cpp
//  STL Sample 01
//
//  Created by Bernd Lappas on 04.03.13.
//  Copyright (c) 2013 Bernd Lappas. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

void map01();
void map02();
void map03();
void map04();
void unordered_map01();
void vector01();

template<class T> unsigned int levenshtein_distance(const T &s1, const T & s2)
{
    const size_t len1 = s1.size(), len2 = s2.size();
    std::vector<unsigned int> col(len2+1), prevCol(len2+1);
    
    for (unsigned int i = 0; i < prevCol.size(); i++)
    {
        prevCol[i] = i;
    }
    
    for (unsigned int i = 0; i < len1; i++)
    {
        col[0] = i+1;
        
        for (unsigned int j = 0; j < len2; j++)
        {
            col[j+1] = std::min( std::min( 1 + col[j], 1 + prevCol[1 + j]), prevCol[j] + (s1[i]==s2[j] ? 0 : 1) );
        }
        
        col.swap(prevCol);
    }
    
    return prevCol[len2];
}

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    
    map01();
    map02();
    map03();
    map04();
    unordered_map01();
    vector01();
    
    unsigned int uiEdit_dist = levenshtein_distance<std::string> ("Hallo", "Hal");
    std::cout << "uiEdit_dist: " << uiEdit_dist << '\n';
    
    return 0;
}

void map04()
{
    std::cout << "\n\nmap03()\n";

    const char* messages[] =
    {
        "Beginning",
        "Working",
        "Finishing",
        "Done"
    };
    
    const char *str;
    
    std::map<std::string, const char *> strings;
    std::map<int, const char *> stringids;
    
    strings["NanuKey"] = messages[0];
    strings["HalloKey"] = messages[1];
    strings["HuhuKey"] = messages[2];
    strings["HelloKey"] = messages[3];
    
    stringids[8] = messages[0];
    stringids[12] = messages[1];
    stringids[14] = messages[2];
    stringids[15] = messages[3];
    
    str = strings["NanuKey"];
    str = stringids[12];
    
    std::cout << "strings: " << strings.size() << '\n';
}

void map03()
{
    std::cout << "\n\nmap03()\n";
    
    std::map<std::string, std::string> strings {{"Hallo", "Hallo"}, {"Huhu", "Huhu"}, {"Hello", "Hello"}};
    
    std::cout << "strings: " << strings.size() << '\n';
}

void display_sizes(const std::map<int, int> &nums1,
                   const std::map<int, int> &nums2,
                   const std::map<int, int> &nums3)
{
    std::cout << "nums1: " << nums1.size()
    << " nums2: " << nums2.size()
    << " nums3: " << nums3.size() << '\n';
}

void map01()
{
    std::cout << "\n\nmap01()\n";

    std::map<int, int> nums1 {{3, 1}, {4, 1}, {5, 9}};
    std::map<int, int> nums2;
    std::map<int, int> nums3;

    std::cout << "Initially:\n";
    display_sizes(nums1, nums2, nums3);

    // copy assignment copies data from nums1 to nums2
    nums2 = nums1;

    std::cout << "After assigment:\n";
    display_sizes(nums1, nums2, nums3);

    // move assignment moves data from nums1 to nums3,
    // modifying both nums1 and nums3
    nums3 = std::move(nums1);

    std::cout << "After move assigment:\n";
    display_sizes(nums1, nums2, nums3);
}

void map02()
{
    std::cout << "\n\nmap02()\n";

    typedef std::map<std::string,int>  mapT;

    mapT my_map;
    my_map["x"] = 11;
    my_map["x"] = 14;
    my_map["y"] = 23;
    for (int i = 0 ; i < 10000 ; ++i)
    {
        my_map["x" + std::to_string(i)] = i;
    }
    
    std::cout << "size: " << my_map.size() << "\n";
    
    //for (auto& x: my_map) std::cout << " " << x.first << ":" << x.second << "\n";
    //for (mapT::const_iterator ci = my_map.begin() ; ci != my_map.end() ; ++ci);
    for (std::map<std::string,int>::const_iterator ci = my_map.begin() ; ci != my_map.end() ; ++ci)
    {
        std::cout << " " << ci->first << ":::" << ci->second << "\n";
    }
    
    mapT::iterator  it= my_map.find("x");
    if( it != my_map.end() ) std::cout << "A: " << it->second << "\n";

    it= my_map.find("z");
    if( it != my_map.end() ) std::cout << "B: " << it->second << "\n";

    // Accessing a non-existing element creates it
    if( my_map["z"] == 42 ) std::cout << "Oha!\n";

    it= my_map.find("z");
    if( it != my_map.end() ) std::cout << "C: " << it->second << "\n";
}

typedef std::unordered_map<std::string,std::string> stringmap;

stringmap merge (stringmap a,stringmap b)
{
    stringmap temp(a); temp.insert(b.begin(),b.end()); return temp;
}

void unordered_map01()
{
    std::cout << "\n\nunordered_map01()\n";
    
    // constructing unordered_maps
    
    stringmap first;                              // empty
    stringmap second ( {{"apple","red"},{"lemon","yellow"}} );       // init list
    stringmap third ( {{"orange","orange"},{"strawberry","red"}} );  // init list
    stringmap fourth (second);                    // copy
    stringmap fifth (merge(third,fourth));        // move
    stringmap sixth (fifth.begin(),fifth.end());  // range
    
    std::cout << "sixth contains:";
    for (auto& x: sixth) std::cout << " " << x.first << ":" << x.second;
    std::cout << std::endl;
}

void vector01()
{
    std::cout << "\n\nvector01()\n";

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
}