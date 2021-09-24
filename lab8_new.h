#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

// чтение из файла
std::string read_from_file(std::string filename)
{
    std::string line;
    std::string text;
    std::ifstream myfile(filename);
    if (myfile.is_open())
    {
        std::ostringstream sstr;
        sstr << myfile.rdbuf();
        return sstr.str();
        myfile.close();
    }
    else
    {
        std::cout << "Невозможно открыть файл";
    }
    return text;
}

void write_to_file(std::string filename, std::string data)
{
    std::ofstream file;
    file.open(filename);

    file << data << '\n';

    file.close();
}

std::vector<std::string> split(std::string str, char separator)
{
    std::vector<std::string> arr;
    std::stringstream ss(str);
    std::string word;

    while (ss >> word)
    {
        arr.push_back(word);
    }

    return arr;
}

int len(std::string str)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    auto cringe = converter.from_bytes(str);
    return cringe.length();
}

bool compare(std::string a, std::string b)
{
    return (len(a) < len(b));
}
