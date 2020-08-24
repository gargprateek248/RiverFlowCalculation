#include <fstream>
#include <iostream>
#include <numeric>
#include "StreamFlow.h"

StreamFlow::StreamFlow(double width, StreamType type)
{
	streamWidth = width;
	streamType = type;
	GetMeasurements(DEPTH_MEASUREMENTS_FILE, depthValues);
	GetMeasurements(VELOCITY_MEASUREMENTS_FILE, velocityValues);
}

void StreamFlow::GetMeasurements(string dataFile, vector<double>& dataValues)
{
	ifstream inData(dataFile, ios::in);
	if(!inData.is_open())
	{
		//file couldn't be opened
		cerr << "Error: " << dataFile << " file could not be opened" << endl;
		exit(1);
	}

        auto val = 0.0;
	cout << "The values read from " << dataFile << " - ";	
	while (inData >> val) 
	{ 
		// keep reading until end-of-file
		cout << val << " ";
		dataValues.emplace_back(val);
	}
        cout << endl;
	inData.close();
}

double StreamFlow::CalculateStreamFlowVol() const
{
	const auto avgCrossSectionalArea = accumulate(depthValues.begin(), depthValues.end(), 0.0) / (depthValues.size() + 1) * streamWidth;
	cout << "avg cross sectional area is " << avgCrossSectionalArea << " sq ft" << endl;

	const auto avgVelocity = accumulate(velocityValues.begin(), velocityValues.end(), 0.0) / velocityValues.size();
	cout << "avg velocity is " << avgVelocity << " ft per second" << endl;
	
	auto coeffStreamType = COEFF_ROCKY_BOTTOM_STREAM;
	if(streamType == StreamType::MUDDY_BOTTOM)
		coeffStreamType = COEFF_MUDDY_BOTTOM_STREAM;

	const auto streamFlowVol = coeffStreamType * avgCrossSectionalArea * avgVelocity;

	return streamFlowVol;
}
