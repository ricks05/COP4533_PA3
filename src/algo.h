#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#pragma once

using namespace std;

pair<unordered_map<char, int>, pair<string, string>> processInput(ifstream& fd);
pair<int, string> algo(string& A, string& B, unordered_map<char, int>& value);