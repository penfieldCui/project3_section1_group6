#ifndef ComputerH
#define ComputerH

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Component {
public:

	Component(string type, double cpuUsage, double ramUsage);
	void PowerOn();
	void PowerOff();
	bool IsPoweredOn() const;

	double GetCpuUsage() const;
	double GetRamUsage() const;

//	void SetCpuUsage(double usage);
//	void SetRamUsage(double usage);


	string GetType() const;

	void UpdateUsageComponent(bool computerPoweredOn);
	void RandomlyFluctuateUsage();


	// New methods for saving/loading component
	void SaveToFile(ofstream &out) const;
	void LoadFromFile(ifstream &in);

private:
	string type;
	bool poweredOn;
	double cpuUsage; // of single component
	double ramUsage; //

	double MaxCpuUsage;
	double MaxRamUsage;
};

class Computer {
public:

	Computer(const string &ipAddress, const string &name, int totalRam = 16384, bool poweredOn = false);

	// Use Timer to update
	void UpdateUsage();

	// components
	void AddComponent(const Component& component);

	vector<Component> GetComponents();

	string GetStatusReport() const;

	// power
    void PowerOn();
    void PowerOff();
	bool IsPoweredOn() const;
	// network
	void Connect();
	void Disconnect();
	bool IsConnected() const;

	//
//	void AdjustBrightness(int level);
//    int GetBrightness() const;



	void SetName(const string &newName);
	void SetIp(const string &newIp);

	// Accessor methods
	string GetIpAddress() const;
    string GetName() const;
	int GetTotalRam() const;


	double GetCpuUsage() const;
	double GetRamUsage() const;

	vector<Component> components; // List of components


	// New methods for saving/loading computer
	void SaveToFile(ofstream &out) const;
	void LoadFromFile(ifstream &in);

private:
	string ipAddress;  // IP address of the computer
	string name;       // Name of the computer
	int totalRam;           // Total RAM size (in MB)
//	int usedRam;            // Currently used RAM (in MB)

    // usage in %
	double cpuUsage;
	double ramUsage;


	bool poweredOn;         // Power state
    bool connected;         // Network connection state
//    int brightness;         // Screen brightness (percentage)


	void CalculateUsage();  // Calculate total CPU and RAM usage


};

#endif

