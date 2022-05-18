/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "dbLib.h"

/* TODO: You can implement methods, functions that support your data structures here.
 * */




void LoadCities(L1List<TCity>*& pCities) {
	ifstream cities_file("cities.csv");
	pCities = new L1List<TCity>();
	string item;
	while (cities_file.good())
	{
		TCity each_cities;
		getline(cities_file, item, ',');
		stringstream id_cities(item);
		id_cities >> each_cities.id;
		getline(cities_file, item, ',');
		each_cities.Name = item;
		getline(cities_file, item, ',');
		each_cities.Coords = item;
		getline(cities_file, item, ',');
		stringstream startYear(item);
		startYear >> each_cities.Start_Year;
		getline(cities_file, item, ',');
		each_cities.url_Name = item;
		getline(cities_file, item, ',');
		each_cities.Country = item;
		getline(cities_file, item, '\n');
		each_cities.Country_State = item;
		pCities->insertHead(each_cities);
	}
	pCities->reverse();
	pCities->removeHead();
	pCities->removeLast();
}
void LoadStation(L1List<TStation>*& pStation) {
	ifstream station_file("stations.csv");
	pStation = new L1List<TStation>();
	string item;
	while (station_file.good()) {
		TStation each_station;
		getline(station_file, item, ',');
		stringstream id_station(item);
		id_station >> each_station.id;
		getline(station_file, item, ',');
		each_station.Name = item;
		getline(station_file, item, ',');
		each_station.Geometry = item;
		getline(station_file, item, ',');
		stringstream buildstart_station(item);
		buildstart_station >> each_station.Buildstart;
		getline(station_file, item, ',');
		stringstream open_station(item);
		open_station >> each_station.Opening;
		getline(station_file, item, ',');
		stringstream close_station(item);
		close_station >> each_station.Closure;
		getline(station_file, item, '\n');
		stringstream idcity_station(item);
		idcity_station >> each_station.City_id;
		pStation->insertHead(each_station);
	}
	pStation->reverse();
	pStation->removeHead();
	pStation->removeLast();
}
void LoadTrack(L1List<TTrack>*& pTrack) {
	ifstream track_file("tracks.csv");
	pTrack = new L1List<TTrack>();
	string item;
	getline(track_file, item, ',');
	getline(track_file, item, '\n');
	while (track_file.good()) {
		TTrack each_track;
		getline(track_file, item, ',');
		stringstream id_track(item);
		id_track >> each_track.id;
		getline(track_file, item, '"');
		getline(track_file, item, '"');
		each_track.Geometry = item;
		getline(track_file, item, ',');
		getline(track_file, item, ',');
		stringstream builstart_track(item);
		builstart_track >> each_track.Buildstart;
		getline(track_file, item, ',');
		stringstream open_track(item);
		open_track >> each_track.Opening;
		getline(track_file, item, ',');
		stringstream close_track(item);
		close_track >> each_track.Closure;
		getline(track_file, item, ',');
		stringstream length_track(item);
		length_track >> each_track.Length;
		getline(track_file, item, '\n');
		stringstream idcity_track(item);
		idcity_track >> each_track.City_id;
		pTrack->insertHead(each_track);
	}
	pTrack->reverse();
	pTrack->removeLast();
}
void LoadLine(L1List<TLine>*& pLine) {
	ifstream line_file("lines.csv");
	pLine = new L1List<TLine>();
	string item;
	while (line_file.good()) {
		TLine each_line;
		getline(line_file, item, ',');
		stringstream id_line(item);
		id_line >> each_line.id;
		getline(line_file, item, ',');
		stringstream idcity_line(item);
		idcity_line >> each_line.City_id;
		getline(line_file, item, ',');
		each_line.Name = item;
		getline(line_file, item, ',');
		each_line.url_Name = item;
		getline(line_file, item, ',');
		each_line.Color = item;
		getline(line_file, item, ',');
		stringstream idsystem_track(item);
		idsystem_track >> each_line.System_id;
		getline(line_file, item, '\n');
		stringstream Transportmodeid_track(item);
		Transportmodeid_track >> each_line.Transport_mode_id;
		pLine->insertHead(each_line);
	}
	pLine->reverse();
	pLine->removeHead();
	pLine->removeLast();
}

void Load_Station_Line(L1List<TStation_Lines>*& pStation_line) {
	ifstream station_line_file("station_lines.csv");
	pStation_line = new L1List<TStation_Lines>();
	string item;
	while (station_line_file.good())
	{
		TStation_Lines each_station_line;
		getline(station_line_file, item, ',');
		stringstream id(item);
		id >> each_station_line.id;
		getline(station_line_file, item, ',');
		stringstream station_id(item);
		station_id >> each_station_line.Station_id;
		getline(station_line_file, item, ',');
		stringstream line_id(item);
		line_id >> each_station_line.Line_id;
		getline(station_line_file, item, ',');
		stringstream city_id(item);
		city_id >> each_station_line.City_id;
		getline(station_line_file, item, ',');
		each_station_line.Created_at = item;
		getline(station_line_file, item, '\n');
		each_station_line.Updated_at = item;
		pStation_line->insertHead(each_station_line);
	}
	pStation_line->reverse();
	pStation_line->removeHead();
	pStation_line->removeLast();
}
void LoadData(void*& pData) {
	//TDataset* pDataset = static_cast<TDataset*>(pData);
	TDataset* pDataset = new TDataset();
	pData = pDataset;
	LoadCities(pDataset->cities);
	LoadStation(pDataset->station);
	LoadTrack(pDataset->track);
	LoadLine(pDataset->line);
	Load_Station_Line(pDataset->station_lines);
	
}
void ReleaseData(void*& pData) {
	TDataset* pDataset = static_cast<TDataset*>(pData);
	delete (pDataset->cities);
	pDataset->cities = NULL;
	delete (pDataset->line);
	pDataset->line = NULL;
	delete (pDataset->station);
	pDataset->station = NULL;
	delete (pDataset->station_lines);
	pDataset->station_lines = NULL;
	delete (pDataset->system);
	pDataset->system = NULL;
	delete (pDataset->track);
	pDataset->track = NULL;
	delete (pDataset->track_lines);
	pDataset->track_lines = NULL;
	delete pDataset;
	pDataset = NULL;
}


