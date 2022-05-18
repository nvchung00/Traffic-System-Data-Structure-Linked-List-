/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : processData.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : Declaration of main features in the assignment
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_PROCESSDATA_H
#define DSA191_A1_PROCESSDATA_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cassert>
#include"dsaLib.h"
#include"dbLib.h"

using namespace std;
/// Prototype declaration

void Initialization();
void Finalization();
void search_city(TCity& pCity, void* data);
void total_line(TLine& pLine, void* data);
void search_station(TStation& pStation, void* data);
void find_station(TStation& pStation, void* data);
void total_station(TStation& pStation, void* data);
void total_station_line(TStation_Lines& pStation_line, void* data);
void search_station_line(TStation_Lines& pStation_line, void* data);
void search_city_station(TStation& pStation, void* data);
void find_station_line(TStation_Lines& pStation_line, void* data);
void find_index_station_line(TStation_Lines& pStation_line, void* data);
void max_id_station(TStation& pStation );
void max_id_city(TCity& pCity);
void find_id_city(TStation& pStation, void* data);
void find_geometry(TTrack& pTrack, void* data);
void find_id_city1(TTrack& pTrack, void* data);

void ProcessRequest(const char* pRequest, void* pData, void*& pOutput, int&);


template <typename T>
void PrintReqOutput(const char* pRequest, T* pOutput, int N) {
	cout << pRequest << ":";
	if (pOutput == nullptr) {
		cout << " error\n";
		return;
	}
	for (int i = 0; i < N; ++i) {
		cout << ' ' << *pOutput++;
	}
	cout << '\n';
}


#endif //DSA191_A1_PROCESSDATA_H
