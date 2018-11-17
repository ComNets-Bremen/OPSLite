# OPS
The Opportunistic Protocol Simulator, Light (OPSLite, pronounced as oops light!!!) is a set of
simulation models in OMNeT++ to simulate opportunistic networks. It has a
modular architecture where different protocols relevant to opportunistic networks
can be developed and plugged in. OPSLite is a scaled-down, light-weight version of  
[OPS](https://github.com/ComNets-Bremen/OPS), available at Github.

The following sections provides details of the models available and about
the installtion. Unlike [OPS](https://github.com/ComNets-Bremen/OPS), OPSLite
is meant to run in the OMNeT++ IDE.


Prerequisites
-------------

OPSLite requires OMNeT++ (version 5.4.1) and the INET Framework (version 4.0.0). 
The OMNeT++ simulator and the IDE can be found at the [OMNeT++ site](https://www.omnetpp.org). Once the
simulator and the IDE is installed, INET (version 4) has to be installed. It can be either 
installed through the IDE itself  or by downloading
from the [INET site](https://inet.omnetpp.org). Here are the 2 important prerequisites.

1. Install and build OMNeT++ (version 5.4.1)

2. Run the OMNet++ IDE and create a new workspace

3. Install and build INET4 (version 4.0.0) in the newly created workspace using
   option - `Help -> Install Simulation Models...`


Installing OPSLite
------------------
Once OMNeT++ IDE and INET4 are installed and built, follows the following steps to install
[OPSLite](https://github.com/ComNets-Bremen/OPSLite). 

1. Download the Github repository of [OPSLite](https://github.com/ComNets-Bremen/OPSLite)

2. If [OPSLite](https://github.com/ComNets-Bremen/OPSLite) downloaded as a ZIP file, expand the ZIP file

3. Run the OMNeT++ IDE, and import [OPSLite](https://github.com/ComNets-Bremen/OPSLite) (`File -> Import... -> General -> File System`) into the OMNeT++
   workspace (where INET4 is installed)

4. Build the OPSLite project using - `Project -> Build Project` (should not have any errors or warnings after building)


Running OPSLite
---------------
To run simulation, check the `omnetpp.ini` and the `OPSLiteNetwork.ned` given (in `simulations` folder), to create your own
scenario. Here are the basic steps

1. Run the OMNeT++ IDE and select the workspace where INET4 and OPSLite is installed and built

2. Modify the `omnetpp.ini` to suit your scenario parameters

3. Select the OPSLite folder (the top most folder of the OPSLite project) and run using - `Run -> Run As -> OMNeT++ Simulation`



Checking Results
----------------
Based on the standard configuration, the raw results (vector and scalar) collected after a simulation run 
are located in the `simulation/results` folder. Double-click on the `.vec` file to create the results
file (`.anf` file). For more information, check Chapter 10 of the [IDE User Guide](https://www.omnetpp.org/doc/omnetpp/UserGuide.pdf)



Available Results (Statistics)
------------------------------
There are a set of network-level results collected in every simulation run. Here are those results.

- Statistics from the Application Layer
1. `likedDataBytesReceivedSum` - Liked data bytes received by all nodes

2. `nonLikedDataBytesReceivedSum` - Non-liked data bytes received by all nodes

3. `duplicateDataBytesReceivedSum` - Duplicate (liked & non-liked) data bytes received by all nodes

4. `likedDataBytesReceivableByAllNodesSum` - Liked data bytes that are possible to be received by all nodes

5. `nonLikedDataBytesReceivableByAllNodesSum` - Non-liked data bytes that are possible to be received by all nodes

6. `dataDelay` - Delivery delay of data (liked and non-liked) by all nodes

7. `deliveryRatio` - Delivery ratio of data (liked and non-liked) by all nodes


- Statistics from the Forwarding Layer

1. `dataBytesReceivedSum` - Data bytes received by all nodes in the network 
        
2. `sumVecBytesReceivedSum` - Summary vectors bytes received by all nodes

3. `dataReqBytesReceivedSum` - Data request bytes received by all nodes

4. `totalBytesReceivedSum` - Total bytes received by all nodes

5. `cacheBytesRemovedSum` - Cache removals in bytes by all nodes

6. `cacheBytesAddedSum` - Cache additions in bytes by all nodes

7. `cacheBytesUpdatedSum` - Cache updates in bytes by all nodes




Node Architecture
-----------------

The architecture of a node uses a number of protocol layers which can be configured
based on the scenario considered. Generally, every node has the following layers.


                           +------------------------+
                           |  +------------------+  |
                           |  |Application Layer |  |
                           |  |                  |  |
                           |  +--------+---------+  |
                           |           |            |
                           |  +--------+---------+  |
                           |  |   Opportunistic  |  |
                           |  | Networking Layer |  |
                           |  +--------+---------+  |
                           |           |            |
                           |  +--------+---------+  |
                           |  | Link Adaptation  |  |
                           |  |     Layer        |  |
                           |  +--------+---------+  |
                           |           |            |
                           |  +--------+---------+  |
                           |  |    Link Layer    |  |
                           |  | +--------------+ |  |
                           |  | |   Mobility   | |  |
                           |  | +--------------+ |  |
                           |  +--------+---------+  |
                           +-----------|------------+
                                       |

Each of the above layers can be configured throufgh their parameters to behave as required. Here are the models
associated with each layer.

1. Application Layer consist of the `KHeraldApp` application that classifies data items as liked and non-liked
   and injects them uniformly over the simulation period.

2. Opportunistic Networking Layer conist of the `KEpidemicRoutingLayer` which is used to forward data
   in an opportunistic network

3. Link Adaptation Layer is a simple passthru-layer (`KLinkAdaptLayer`) intended to be extended in the future.

4. Link Layer consist of the `KWirelessInterface` model that performs simple wireless
   communications.
   
5. Mobility implements the movements of the mobile nodes in the scenarios. It can use any
   of the mobility models vailable in the INET4 Framework. In OPSLite, `omnetpp.ini` is
   configured to use 'Random Waypoint' mobility model. 



Help
----

If you have any question or clarifications related OMNeT++, please check the documentation provided at the OMNeT++ and
INET sites. Here are the important documents.

1. OMNeT++ - [Install Guide](https://www.omnetpp.org/doc/omnetpp/InstallGuide.pdf), 
   [Simulation Manual](https://www.omnetpp.org/doc/omnetpp/SimulationManual.pdf), 
   [IDE User Guide](https://www.omnetpp.org/doc/omnetpp/UserGuide.pdf)

2. INET - [Documentation](https://inet.omnetpp.org/Introduction.html)

3. Results processing in OMNeT++ IDE - Chapter 10 of the [IDE User Guide](https://www.omnetpp.org/doc/omnetpp/UserGuide.pdf)


Questions or Comments
---------------------

If you have any comments or suggestions, we are very glad to hear them. Please write to us using any of the e-mail adresses below.

  - Asanga Udugama (adu@comnets.uni-bremen.de)
  - Jens Dede (jd@comnets.uni-bremen.de)
  - Anna Förster (anna.foerster@comnets.uni-bremen.de)
  - Vishnupriya Parimalam (vp@fb1.uni-bremen.de)
 