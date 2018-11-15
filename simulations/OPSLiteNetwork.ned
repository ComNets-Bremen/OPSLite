package opslite.simulations;

import opslite.*;

network OPSLiteNetwork
{
    parameters:
        int numNodes = default(20);

        // statistics
        // from application layer
        @statistic[likedDataBytesReceivedSum](source=sum(likedDataBytesReceived);record=max,last,vector,histogram);
        @statistic[nonLikedDataBytesReceivedSum](source=sum(nonLikedDataBytesReceived);record=max,last,vector,histogram);
        @statistic[duplicateDataBytesReceivedSum](source=sum(duplicateDataBytesReceived);record=max,last,vector,histogram);
        
        // from forwarding layer
        @statistic[dataBytesReceivedSum](source=sum(dataBytesReceived);record=max,last,vector,histogram);
        @statistic[sumVecBytesReceivedSum](source=sum(sumVecBytesReceived);record=max,last,vector,histogram);
        @statistic[dataReqBytesReceivedSum](source=sum(dataReqBytesReceived);record=max,last,vector,histogram);
        @statistic[totalBytesReceivedSum](source=sum(totalBytesReceived);record=max,last,vector,histogram);
        @statistic[cacheBytesRemovedSum](source=sum(cacheBytesRemoved);record=max,last,vector,histogram);
        @statistic[cacheBytesAddedSum](source=sum(cacheBytesAdded);record=max,last,vector,histogram);
        @statistic[cacheBytesUpdatedSum](source=sum(cacheBytesUpdated);record=max,last,vector,histogram);         

    submodules:

        // nodes of the network
        node[numNodes]: OPSNode {
            nodeID = index;
        }

}
