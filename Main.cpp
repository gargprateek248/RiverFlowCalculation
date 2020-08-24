#include "StreamFlow.h"
#include <iostream>
#include <sstream>

int main(int argc, char *argv[])
{
	if(argc < 2 || argc > 3)
	{
		cerr << "Program expects at least one argument\n";
		cout << "usage-\n"
		     << "    " << argv[0] << " <stream width> [stream type]\n"
		     << "    stream width - width of stream\n"
                     << "    stream type - optional, possible values 1 or 2.\n"
		     << "                  1 is for rocky bottom stream\n"
		     << "                  2 is for muddy bottom stream\n";
		return 1;
	}
       	
	double streamWidth = 0.0;
	if (argc >= 2)
    	{
        	std::istringstream iss( argv[1] );

        	if(!(iss >> streamWidth))
        	{
			cerr << "Invalid stream width\n";
			return 1;
        	}
    	}

        int streamType = 1;
	if(argc == 3)
	{
        	std::istringstream iss( argv[2] );

        	if(!(iss >> streamType) || (streamType < 1) || (streamType >2))
        	{
			cerr << "Invalid stream type\n";
                	cout << "    stream type - optional, possible values 1 or 2.\n"
			     << "                  1 is for rocky bottom stream\n"
			     << "                  2 is for muddy bottom stream\n";
			return 1;
        	}
	}

	StreamFlow streamFlowInstance(streamWidth, (StreamType)streamType);
	const auto streamFlowVol = streamFlowInstance.CalculateStreamFlowVol();
	cout << "Stream flow volume at given point is " << streamFlowVol << " cubic feet per second" << endl;
	return 0;
}
