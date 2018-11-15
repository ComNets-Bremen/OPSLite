//
// Generated file, do not edit! Created by nedtool 5.4 from KOPSMsg.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __KOPSMSG_M_H
#define __KOPSMSG_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>KOPSMsg.msg:16</tt> by nedtool.
 * <pre>
 * packet KDataMsg
 * {
 *     // common fields
 *     string sourceAddress;
 *     string destinationAddress;
 *     string dataName;
 *     string dummyPayloadContent;
 *     int msgType;
 *     double validUntilTime = 0;
 *     int msgUniqueID;
 * 
 *     int realPayloadSize;
 *     int realPacketSize;
 * 
 *     int hopsTravelled = 0;
 * 
 *     // destination oriented delivery specific fields
 *     string originatorNodeName;
 *     string finalDestinationNodeName;
 *     bool destinationOriented = false;
 * 
 *     // keetchi specific fields
 *     int goodnessValue = 50;
 * 
 *     // epidemic routing specific fields
 *     string messageID;
 *     int hopCount = 255;
 * }
 * 
 * //
 * // Summary vector exchange message (used with Epidemic Routing).
 * //
 * // \@author : Asanga Udugama (adu\@comnets.uni-bremen.de)
 * // \@date   : 02-may-2017
 * //
 * //
 * // example sizes in bytes
 * //
 * //                addrs | msg ID hashes  | total  |
 * //                s & d | 2 bytes x count| (bytes)|
 * // Epidemic  ->   6 + 6     2 x 10           32
 * </pre>
 */
class KDataMsg : public ::omnetpp::cPacket
{
  protected:
    ::omnetpp::opp_string sourceAddress;
    ::omnetpp::opp_string destinationAddress;
    ::omnetpp::opp_string dataName;
    ::omnetpp::opp_string dummyPayloadContent;
    int msgType;
    double validUntilTime;
    int msgUniqueID;
    int realPayloadSize;
    int realPacketSize;
    int hopsTravelled;
    ::omnetpp::opp_string originatorNodeName;
    ::omnetpp::opp_string finalDestinationNodeName;
    bool destinationOriented;
    int goodnessValue;
    ::omnetpp::opp_string messageID;
    int hopCount;

  private:
    void copy(const KDataMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const KDataMsg&);

  public:
    KDataMsg(const char *name=nullptr, short kind=0);
    KDataMsg(const KDataMsg& other);
    virtual ~KDataMsg();
    KDataMsg& operator=(const KDataMsg& other);
    virtual KDataMsg *dup() const override {return new KDataMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const char * getSourceAddress() const;
    virtual void setSourceAddress(const char * sourceAddress);
    virtual const char * getDestinationAddress() const;
    virtual void setDestinationAddress(const char * destinationAddress);
    virtual const char * getDataName() const;
    virtual void setDataName(const char * dataName);
    virtual const char * getDummyPayloadContent() const;
    virtual void setDummyPayloadContent(const char * dummyPayloadContent);
    virtual int getMsgType() const;
    virtual void setMsgType(int msgType);
    virtual double getValidUntilTime() const;
    virtual void setValidUntilTime(double validUntilTime);
    virtual int getMsgUniqueID() const;
    virtual void setMsgUniqueID(int msgUniqueID);
    virtual int getRealPayloadSize() const;
    virtual void setRealPayloadSize(int realPayloadSize);
    virtual int getRealPacketSize() const;
    virtual void setRealPacketSize(int realPacketSize);
    virtual int getHopsTravelled() const;
    virtual void setHopsTravelled(int hopsTravelled);
    virtual const char * getOriginatorNodeName() const;
    virtual void setOriginatorNodeName(const char * originatorNodeName);
    virtual const char * getFinalDestinationNodeName() const;
    virtual void setFinalDestinationNodeName(const char * finalDestinationNodeName);
    virtual bool getDestinationOriented() const;
    virtual void setDestinationOriented(bool destinationOriented);
    virtual int getGoodnessValue() const;
    virtual void setGoodnessValue(int goodnessValue);
    virtual const char * getMessageID() const;
    virtual void setMessageID(const char * messageID);
    virtual int getHopCount() const;
    virtual void setHopCount(int hopCount);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const KDataMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, KDataMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>KOPSMsg.msg:58</tt> by nedtool.
 * <pre>
 * packet KSummaryVectorMsg
 * {
 *     // common fields
 *     string sourceAddress;
 *     string destinationAddress;
 * 
 *     int realPacketSize;
 * 
 *     // epidemic routing specific fields
 *     string messageIDHashVector[];  // summary vector
 * }
 * 
 * //
 * // Data request message (used with Epidemic Routing).
 * //
 * // \@author : Asanga Udugama (adu\@comnets.uni-bremen.de)
 * // \@date   : 02-may-2017
 * //
 * //
 * // example sizes in bytes
 * //
 * //                addrs | msg ID hashes  | total  |
 * //                s & d | 2 bytes x count| (bytes)|
 * // Epidemic  ->   6 + 6     2 x 5            32
 * </pre>
 */
class KSummaryVectorMsg : public ::omnetpp::cPacket
{
  protected:
    ::omnetpp::opp_string sourceAddress;
    ::omnetpp::opp_string destinationAddress;
    int realPacketSize;
    ::omnetpp::opp_string *messageIDHashVector; // array ptr
    unsigned int messageIDHashVector_arraysize;

  private:
    void copy(const KSummaryVectorMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const KSummaryVectorMsg&);

  public:
    KSummaryVectorMsg(const char *name=nullptr, short kind=0);
    KSummaryVectorMsg(const KSummaryVectorMsg& other);
    virtual ~KSummaryVectorMsg();
    KSummaryVectorMsg& operator=(const KSummaryVectorMsg& other);
    virtual KSummaryVectorMsg *dup() const override {return new KSummaryVectorMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const char * getSourceAddress() const;
    virtual void setSourceAddress(const char * sourceAddress);
    virtual const char * getDestinationAddress() const;
    virtual void setDestinationAddress(const char * destinationAddress);
    virtual int getRealPacketSize() const;
    virtual void setRealPacketSize(int realPacketSize);
    virtual void setMessageIDHashVectorArraySize(unsigned int size);
    virtual unsigned int getMessageIDHashVectorArraySize() const;
    virtual const char * getMessageIDHashVector(unsigned int k) const;
    virtual void setMessageIDHashVector(unsigned int k, const char * messageIDHashVector);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const KSummaryVectorMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, KSummaryVectorMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>KOPSMsg.msg:83</tt> by nedtool.
 * <pre>
 * packet KDataRequestMsg
 * {
 *     // common fields
 *     string sourceAddress;
 *     string destinationAddress;
 * 
 *     int realPacketSize;
 * 
 *     // epidemic routing specific fields
 *     string messageIDHashVector[];  // request vector
 * }
 * </pre>
 */
class KDataRequestMsg : public ::omnetpp::cPacket
{
  protected:
    ::omnetpp::opp_string sourceAddress;
    ::omnetpp::opp_string destinationAddress;
    int realPacketSize;
    ::omnetpp::opp_string *messageIDHashVector; // array ptr
    unsigned int messageIDHashVector_arraysize;

  private:
    void copy(const KDataRequestMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const KDataRequestMsg&);

  public:
    KDataRequestMsg(const char *name=nullptr, short kind=0);
    KDataRequestMsg(const KDataRequestMsg& other);
    virtual ~KDataRequestMsg();
    KDataRequestMsg& operator=(const KDataRequestMsg& other);
    virtual KDataRequestMsg *dup() const override {return new KDataRequestMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const char * getSourceAddress() const;
    virtual void setSourceAddress(const char * sourceAddress);
    virtual const char * getDestinationAddress() const;
    virtual void setDestinationAddress(const char * destinationAddress);
    virtual int getRealPacketSize() const;
    virtual void setRealPacketSize(int realPacketSize);
    virtual void setMessageIDHashVectorArraySize(unsigned int size);
    virtual unsigned int getMessageIDHashVectorArraySize() const;
    virtual const char * getMessageIDHashVector(unsigned int k) const;
    virtual void setMessageIDHashVector(unsigned int k, const char * messageIDHashVector);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const KDataRequestMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, KDataRequestMsg& obj) {obj.parsimUnpack(b);}


#endif // ifndef __KOPSMSG_M_H
