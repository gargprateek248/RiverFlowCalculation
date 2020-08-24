#include <vector>
#include <string>

using namespace std;

const auto DEPTH_MEASUREMENTS_FILE                = "DepthMeasurements.dat";
const auto VELOCITY_MEASUREMENTS_FILE             = "VelocityMeasurements.dat";
const auto COEFF_ROCKY_BOTTOM_STREAM              = 0.8;
const auto COEFF_MUDDY_BOTTOM_STREAM              = 0.9;

enum class StreamType
{
	ROCKY_BOTTOM = 1,
	MUDDY_BOTTOM = 2
};

class StreamFlow
{
private:
	double streamWidth;
	StreamType streamType;
	vector<double> depthValues;
	vector<double> velocityValues;
	
protected:
	void GetMeasurements(string dataFile, vector<double>& dataValues);

public:
	explicit StreamFlow(double streamWidth, StreamType sType);
	double CalculateStreamFlowVol() const;
};
