
#pragma once
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <list>
#include <time.h>
#include <stdlib.h>
#include <tchar.h>
#include <vector>
#include <string>
#include<d3d9.h>		//微软提供头文件

#include<d3dx9.h>		//微软提供头文件
#include <map>

#ifdef _UNICODE
#define TSTRING wstring
#define TCOUT	wcout
#else
#define  TSTRING string
#define TCOUT	cout
#endif
#include "Singleton.h"
using namespace std;