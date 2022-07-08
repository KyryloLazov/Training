#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Train.h"

using namespace std;

void Createfile(const string& file_name);

Train* ReadFile(const string& file_name);
