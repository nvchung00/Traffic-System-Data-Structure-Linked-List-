/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DBLIB_H
#define DSA191_A1_DBLIB_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>

#include "dsaLib.h"

/* TODO: Please design your data structure carefully so that you can work with the given dataset
 *       in this assignment. The below structures are just some suggestions.
 */
struct TCity {
	// The structure to store city information
	int id;
	string Name;
	string Coords;//toa do
	int Start_Year;
	string url_Name;
	string Country;
	string Country_State;
	TCity() : id(0), Name(" "), Coords(" "), Start_Year(0),url_Name(" "), Country(" "), Country_State(" "){}
};




struct TLine {
    // The structure to store line information
	int id;
	int City_id;
	string Name;
	string url_Name;
	string Color;
	int System_id;
	int Transport_mode_id;
	TLine() : id(0), City_id(0), Name(" "), url_Name(" "), Color(" "), System_id(0), Transport_mode_id(0){}
};



struct TTrack {
    // The structure to store track information
	int id;
	string Geometry;
	int Buildstart;
	int Opening;
	int Closure;
	int Length;
	int City_id;
	TTrack() : id(0),Geometry(" "), Buildstart(0), Opening(0), Closure(0),Length(0), City_id(0){}
};



struct TStation {
	int id;
	string Name;
	string Geometry;
	int Buildstart;
	int  Opening;
	int Closure;
	int City_id;
	TStation() : id(0), Name(" "), Geometry(" "), Buildstart(0), Opening(0), Closure(0), City_id(0){}
};


struct TSystem {
	int  id;
	int  City_id;
	string Name;
	TSystem() : id(0), City_id(), Name(" "){}
};


struct TTrack_Lines {
	int id;
	int Section_id;
	int Line_id;
	string created_at;
	string updated_at;
	int city_id;
	TTrack_Lines(): id(0), Section_id(0), Line_id(0), created_at(" "), updated_at(" "), city_id(0){}
};


struct TStation_Lines {
	int id;
	int  Station_id;
	int Line_id;
	int City_id;
	string  Created_at;
	string Updated_at;
	TStation_Lines() : id(0), Station_id(0),Line_id(0), City_id(0), Created_at(" "), Updated_at(" "){}
};


class TDataset {
	// This class can be a container that help you manage your tables
public:
	L1List <TCity>* cities;
	L1List <TStation>* station;
	L1List <TTrack>* track;
	L1List <TLine>* line;
	L1List <TStation_Lines>* station_lines;
	L1List <TTrack_Lines>* track_lines;
	L1List <TSystem>* system;
	TDataset() : cities(NULL), station(NULL), track(NULL), line(NULL), station_lines(NULL), track_lines(NULL), system(NULL) {}
};


// Please add more or modify as needed

void LoadCities(L1List<TCity>*& pCities);
void LoadStation(L1List<TStation>*& pStation);
void LoadTrack(L1List<TTrack>*&);
void LoadLine(L1List<TLine>*&);
void Load_Station_Line(L1List<TStation_Lines>*&);
void LoadData(void* & );
void ReleaseData(void* &);

#endif //DSA191_A1_DBLIB_H
