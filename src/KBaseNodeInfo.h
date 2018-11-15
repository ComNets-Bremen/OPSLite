
#ifndef KBASENODEINFO_H_
#define KBASENODEINFO_H_
#include "inet/mobility/contract/IMobility.h"

#include <omnetpp.h>
#include <cstdlib>
#include <string>


#include "KWirelessInterface.h"

using namespace omnetpp;

using namespace std;

class KWirelessInterface;

class KBaseNodeInfo
{
    public:
        string nodeAddress;

        cModule *nodeModule;
		inet::IMobility *nodeMobilityModule;
		KWirelessInterface *nodeWirelessIfcModule;
};

#endif /* KBASENODEINFO_H_ */
