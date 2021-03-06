package opslite;

import inet.mobility.contract.IMobility;

module OPSNode
{
    parameters:
		@networkNode();
		
        // unique node identifier
        int nodeID;

        // build own address from nodeID (in the form of a MAC address)
        int digit1 = int((nodeID - (nodeID % 10000)) / 10000);
        int digit2 = int(((nodeID - (this.digit1 * 10000)) - ((nodeID - (this.digit1 * 10000)) % 1000)) / 1000);
        int digit3 = int(((nodeID - (this.digit1 * 10000) - (this.digit2 * 1000)) - ((nodeID - (this.digit1 * 10000) - (this.digit2 * 1000)) % 100)) / 100);
        int digit4 = int(((nodeID - (this.digit1 * 10000) - (this.digit2 * 1000) - (this.digit3 * 100)) - ((nodeID - (this.digit1 * 10000) - (this.digit2 * 1000) - (this.digit3 * 100)) % 10)) / 10);
        int digit5 = int(nodeID - (this.digit1 * 10000) - (this.digit2 * 1000) - (this.digit3 * 100) - (this.digit4 * 10));
        string ownAddress = "02:0" + string(this.digit1) + ":0" + string(this.digit2) + ":0" + string(this.digit3) + ":0" + string(this.digit4) + ":0" + string(this.digit5);
        *.ownMACAddress = ownAddress;

        // mobility model used
        string mobilityType = default("StationaryMobility");

        // icon
        @display("i=device/palm2;bgb=250,340");

    gates:
        input radioIn @directIn;

    submodules:

        // application layer
        application: KHeraldApp {
            nodeIndex = nodeID;
            @display("p=122,28");
        }

        // Forwarding layer
        forwarding: KEpidemicRoutingLayer {
            @display("p=122,105");
        }

        // link adaptation layer
        linkAdapt: KLinkAdaptLayer {
            @display("p=122,179");
        }

        // wifi adhoc interface
        wirelessIfc: KWirelessInterface {
            @display("p=122,253");
        }

        // mobility
        mobility: <mobilityType> like IMobility {

            @display("p=31,253");
        }
    connections allowunconnected:

        // gate connections between application and forwarding layer
        application.lowerLayerIn <-- forwarding.upperLayerOut;
        application.lowerLayerOut --> forwarding.upperLayerIn;

        // gate connections forwarding layer and link adaptation layer
        forwarding.lowerLayerIn <-- linkAdapt.upperLayerOut;
        forwarding.lowerLayerOut --> linkAdapt.upperLayerIn;

        // gate connections between link adaptation layer and the wireless interface
        linkAdapt.lowerLayerIn <-- wirelessIfc.upperLayerOut;
        linkAdapt.lowerLayerOut --> wirelessIfc.upperLayerIn;

        // gate connections between wireless interface and physical layer
        // only considered receipts as @directIn is specified and nodes send
        // directly to other nodes
        wirelessIfc.lowerLayerIn <-- radioIn;
}
