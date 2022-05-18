/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : processData.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : Implementation of main features in the assignment
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "processData.h"


/* TODO: You can implement methods, functions that support your data structures here.
 * */
using namespace std;

int sum_line;
int id_city;
int id_city1;
int id_station;
int sum_station;
int* arr_station;
int j;
int* arr_line;
int sum_station_line;
int* arr_station_line;
int id_line_station;
int* arr_station_of_line;
int city_id_station;
int city_id_track;
int k;
int m;
int l;
int idx_station;
int idx_station_line;
int idx;
int id_line;
int max_station;
int max_city;
string linestring;
int id_city2;

void Initialization() {
	// If you use global variables, please initialize them explicitly in this function.
	
	arr_station = new int[16000];
	arr_station_of_line = new int[16000];
	arr_line = new int[16000];
	arr_station_line = new int[16000];
	id_city = 0;
	id_city1 = 0;
	sum_line = 0;
	id_station = 0;
	sum_station = 0;
	sum_station_line = 0;
	id_line_station = 0;
	city_id_station = 0;
	city_id_track = 0;
	idx_station = 0;
	idx_station_line = 0;
	j = 0;
	k = 0;
	idx_station = 0;
	idx = 0;
	id_line = 0;
	m = 0;
	l = 0;
	max_station = 0;
	max_city = 0;
	linestring = " ";
	id_city2 = 0;
}

void Finalization() {
    // Release your data before exiting
	delete[] arr_station;
	delete[] arr_line;
	delete[] arr_station_line;
	delete[] arr_station_of_line;
}


void search_city(TCity& pCity, void* data) {
	string dataset_city = *static_cast<string*>(data);
	if (pCity.Name == dataset_city) {
		id_city = pCity.id;
		j++;
		return;
	}
}



void total_line(TLine& pLine, void* data) {
	int dataset_line = *static_cast<int*>(data);
	if (pLine.City_id == dataset_line) {
		sum_line = sum_line + 1;
		arr_line[m] = pLine.id;
		m++;
	}
}


void search_station(TStation& pStation, void* data) {
	string dataset_station = *static_cast<string*>(data);
	if (pStation.Name == dataset_station) {
		arr_station[m] = pStation.id;
		m++;
	}
}

void total_station(TStation& pStation, void* data) {
	int dataset_station = *static_cast<int*>(data);
	if (pStation.City_id == dataset_station) {
		sum_station = sum_station + 1;
		arr_station[m] = pStation.id;
		idx_station = k;
		m++;
	}
	k++;
}

void total_station_line(TStation_Lines& pStation_line, void* data) {
	int dataset_line_station = *static_cast<int*>(data);
	if (pStation_line.Line_id == dataset_line_station) {
		sum_station_line = sum_station_line + 1;
		arr_station_line[m] = pStation_line.Station_id;
		m++;
	}
}

void find_station(TStation& pStation, void* data) {
	int dataset_station = *static_cast<int*>(data);
	if (pStation.id == dataset_station) {
		idx_station = k;
		j++;
	}
	k++;
}

void search_station_line(TStation_Lines& pStation_line, void* data) {
	int dataset_line_station = *static_cast<int*>(data);
	if (pStation_line.Line_id == dataset_line_station && pStation_line.Station_id == id_station) {
		id_line_station = pStation_line.id;
		j++;
		idx_station_line = k;
	}
	k++;
}

void find_station_line(TStation_Lines& pStation_line, void* data) {
	int dataset_station_line = *static_cast<int*>(data);
	if (pStation_line.Station_id == dataset_station_line) {
		arr_station_line[m] = k;
		m++;
	}
	k++;
}

void search_city_station(TStation& pStation, void* data) {
	int dataset_city_station = *static_cast<int*>(data);
	if (pStation.id == dataset_city_station) {
		city_id_station = pStation.City_id;
	}
}

void find_index_station_line(TStation_Lines& pStation_line, void* data) {
	int dataset_line_station = *static_cast<int*>(data);
	if (k==idx && pStation_line.Line_id == id_line && pStation_line.Station_id == id_station) {
		idx_station_line = 10;
	}
	k++;
}
void max_id_station(TStation& pStation ) {
	if (pStation.id >= max_station) max_station = pStation.id;
}

void max_id_city(TCity& pCity) {
	if (pCity.id >= max_city) max_city = pCity.id;
}
void find_id_city(TStation& pStation, void* data) {
	int dataset_station = *static_cast<int*>(data);
	if (pStation.id == dataset_station) {
		id_city1 = pStation.City_id;
	}
}
void find_geometry(TTrack& pTrack, void* data) {
	string dataset_geometry = *static_cast<string*>(data);
	if (pTrack.Geometry == dataset_geometry) {
		l=k;
		return;
	}
	k++;
}
void find_id_city1(TTrack& pTrack, void* data) {
	int dataset_track = *static_cast<int*>(data);
	if (pTrack.id== dataset_track) {
		id_city2 = pTrack.City_id;
		linestring = pTrack.Geometry;
	}
}





void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int &N) {
    // TODO: Implement this function for processing a request
    // NOTE: You can add other functions to support this main process.
    //       pData is a pointer to a data structure that manages the dataset
    //       pOutput is a pointer reference. It is set to nullptr and student must allocate data for it in order to save the required output
    //       N is the size of output, must be a non-negative number

	TDataset* _pDataset = (TDataset*)pData;
	int* ipOutput = static_cast<int*>(pOutput);
    ipOutput = new int[16000];
	pOutput = ipOutput;
	string req(pRequest);
	int size_line;
	string name_city;
	string name_station;
	string name_line;
	int input_line_id;
	int input_station_id;
	string id_station_line;
	int id_s;
	int id_t;
	if (req.substr(0, 2) == "CL" && req.length() == 2) {
		N = 1;
		size_line = (int)_pDataset->line->getSize();
		*ipOutput = size_line;
		
	}
	if (req.substr(0, 2) == "CL" && req.length() != 2) {
		N = 1;
		name_city = req.substr(3, req.length());
		_pDataset->cities->traverse(search_city,&name_city);
		_pDataset->line->traverse(total_line, &id_city);
		if (id_city == 0)*ipOutput = -1;
		else *ipOutput = sum_line;
				
	}
	if (req.substr(0, 3) == "LSC" ) {

		name_city = req.substr(4, req.length());
		_pDataset->cities->traverse(search_city, &name_city);
		_pDataset->station->traverse(total_station, &id_city);
		N = sum_station;
		for (int i = 0;  i < N; i++)
		{
			ipOutput[i] = arr_station[i];
		}
		
	}
	if (req.substr(0, 3) == "LLC") {
		name_city = req.substr(4, req.length());
		_pDataset->cities->traverse(search_city, &name_city);
		_pDataset->line->traverse(total_line, &id_city);
		N = sum_line;
		for (int i = 0; i < N; i++)
		{
			ipOutput[i] = arr_line[i];
		}
		
	}
	if (req.substr(0, 3) == "LSL") {
		name_line = req.substr(4, req.length());
		stringstream id(name_line);
		id >> input_line_id;
		_pDataset->station_lines->traverse(total_station_line, &input_line_id);
		N = sum_station_line;
		for (int i = 0; i < N; i++)
		{
			ipOutput[i] = arr_station_line[i];
		}
		
	}
	if (req.substr(0, 2) == "FC") {
		N = 1;
		name_city = req.substr(3, req.length());
		_pDataset->cities->traverse(search_city, &name_city);
		if (j != 0) *ipOutput = id_city;
		else *ipOutput = -1;
	}
	if (req.substr(0, 2) == "FS") {
		N = 1;
		name_station = req.substr(3, req.length());
		_pDataset->station->traverse(search_station, &name_station);
		if (m!=0) *ipOutput = arr_station[0];
		else *ipOutput = -1;		
	}
	if (req.substr(0, 3) == "SLP") {
		N = 1;
		string input = req.substr(4, req.length());
		string s_id_station;
		string s_id_track;		
		stringstream info(input);
		getline(info, s_id_station,' ');
		stringstream convert_id_s(s_id_station);
		convert_id_s >> id_s;
		getline(info, s_id_track, '\n');
		stringstream convert_id_t(s_id_track);
		convert_id_t >> id_t;
		_pDataset->track->traverse(find_id_city1, &id_t);
		_pDataset->station->traverse(find_id_city, &id_s);
		if (id_city2 == id_city1) {
			_pDataset->track->traverse(find_geometry, &linestring);
			*ipOutput = l;
		}
		else *ipOutput = -1;
		
		
	}
	if (req.substr(0, 2) == "IS") {
		N = 1;
		string input = req.substr(3, req.length());
		stringstream data(input);
		string item1;
		string item2;
		string item3;
		string item4;
		string item5;
		TStation update_station;
		getline(data, item1, ',');
		update_station.Name = item1;
		getline(data, item2, ',');
		update_station.Geometry = item2;
		getline(data, item3, ',');
		stringstream buildstart_station(item3);
		buildstart_station >> update_station.Buildstart;
		getline(data, item4, ',');
		stringstream open_station(item4);
		open_station >> update_station.Opening;
		getline(data, item5, '\n');
		stringstream close_station(item5);
		close_station >> update_station.Closure;								
		_pDataset->station->traverse(max_id_station);
		_pDataset->cities->traverse(max_id_city);
		update_station.City_id = max_city + 1;
		update_station.id = max_station + 1;
		_pDataset->station->push_back(update_station);
		*ipOutput = max_station+1;
	}
	if (req.substr(0, 2) == "RS") {
		N = 1;
		string item = req.substr(3, req.length());
		stringstream info(item);
		info >> id_station;
		_pDataset->station->traverse(find_station, &id_station);
		k = 0;
		if (j != 0) {
			_pDataset->station->remove(idx_station);
			j = 0;
			_pDataset->station_lines->traverse(find_station_line, &id_station);
			for (int i = 0; i < m; i++)
			{
				_pDataset->station_lines->remove(arr_station_line[i]);
			}
			*ipOutput = 0;
		}
		else *ipOutput = -1;	

	}
	if (req.substr(0, 2) == "US") {
		N = 1;
		string input = req.substr(3, req.length());	
		string s_id_station;
		string s_file;
		stringstream info(input);
		getline(info, s_id_station, ' ');
		stringstream convert_id_station(s_id_station);
		convert_id_station >> input_station_id;
		getline(info, s_file, '\n');
		string item;
		_pDataset->station->traverse(find_station, &input_station_id);
		if (j != 0) {
			stringstream data(s_file);
			_pDataset->station->remove(idx_station);
			TStation update_station;
			update_station.id = input_station_id;
			getline(data, item, ',');
			update_station.Name = item;
			getline(data, item, ',');
			update_station.Geometry = item;
			getline(data, item, ',');
			stringstream buildstart_station(item);
			buildstart_station >> update_station.Buildstart;
			getline(data, item, ',');
			stringstream open_station(item);
			open_station >> update_station.Opening;
			getline(data, item, ',');
			stringstream close_station(item);
			close_station >> update_station.Closure;
			getline(data, item, '\n');
			stringstream idcity_station(item);
			idcity_station >> update_station.City_id;
			_pDataset->station->insert(idx_station, update_station);									
			*ipOutput = 0;
		}
		else *ipOutput = -1;		
	}
	if (req.substr(0, 3) == "ISL") {
		N = 1;
		string input = req.substr(4, req.length());
		string s_id_station;
		string s_id_line;
		string input_idx;
		stringstream  info(input);
		getline(info, s_id_station, ' ');
		stringstream convert_id_station(s_id_station);
		convert_id_station >> input_station_id;
		id_station = input_station_id;
		getline(info, s_id_line, ' ');
		stringstream convert_id_line(s_id_line);
		convert_id_line >> input_line_id;
		id_line = input_line_id;
		getline(info, input_idx, '\n');
		stringstream convert_idx(input_idx);
		convert_idx >> idx;
		TStation_Lines more_note;
		more_note.Station_id = id_station;
		more_note.Line_id = input_line_id;
		_pDataset->station_lines->traverse(find_index_station_line, &idx);
		if (idx_station_line != 0) *ipOutput = -1;
		else {
			_pDataset->station_lines->insert(idx, more_note);
			*ipOutput = 0;
		}
	}
	if (req.substr(0, 3) == "RSL") {
		N = 1;
		id_station_line = req.substr(4, req.length());
		string s_id_station;
		string s_id_line;
		stringstream info(id_station_line);
		getline(info, s_id_station, ' ');
		stringstream convert_id_station(s_id_station);
		convert_id_station >> input_station_id;
		id_station = input_station_id;
		getline(info, s_id_line, '\n');
		stringstream conver_id_line(s_id_line);
		conver_id_line >> input_line_id;
		_pDataset->station_lines->traverse(search_station_line, &input_line_id);
		if (id_line_station != 0) {
			_pDataset->station_lines->remove(idx_station_line);
			*ipOutput = 0;
		}
		else *ipOutput = -1;
	}	
	id_city = 0;
	id_city1 = 0;
	sum_line = 0;
	id_station = 0;
	sum_station = 0;
	sum_station_line = 0;
	id_line_station = 0;
	city_id_station = 0;
	city_id_track = 0;
	idx_station = 0;
	j = 0;
	k = 0;
	idx_station = 0;
	idx_station_line = 0;
	idx = 0;
	id_line = 0;
	m = 0;
	l = 0;
	max_station = 0;
	max_city = 0;
	linestring = " ";
	id_city2 = 0;
}

