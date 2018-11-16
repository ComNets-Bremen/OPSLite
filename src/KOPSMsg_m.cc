//
// Generated file, do not edit! Created by nedtool 5.4 from KOPSMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "KOPSMsg_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(KDataMsg)

KDataMsg::KDataMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->msgType = 0;
    this->validUntilTime = 0;
    this->msgUniqueID = 0;
    this->realPayloadSize = 0;
    this->realPacketSize = 0;
    this->hopsTravelled = 0;
    this->injectedTime = 0;
    this->destinationOriented = false;
    this->goodnessValue = 50;
    this->hopCount = 255;
}

KDataMsg::KDataMsg(const KDataMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

KDataMsg::~KDataMsg()
{
}

KDataMsg& KDataMsg::operator=(const KDataMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void KDataMsg::copy(const KDataMsg& other)
{
    this->sourceAddress = other.sourceAddress;
    this->destinationAddress = other.destinationAddress;
    this->dataName = other.dataName;
    this->dummyPayloadContent = other.dummyPayloadContent;
    this->msgType = other.msgType;
    this->validUntilTime = other.validUntilTime;
    this->msgUniqueID = other.msgUniqueID;
    this->realPayloadSize = other.realPayloadSize;
    this->realPacketSize = other.realPacketSize;
    this->hopsTravelled = other.hopsTravelled;
    this->injectedTime = other.injectedTime;
    this->originatorNodeName = other.originatorNodeName;
    this->finalDestinationNodeName = other.finalDestinationNodeName;
    this->destinationOriented = other.destinationOriented;
    this->goodnessValue = other.goodnessValue;
    this->messageID = other.messageID;
    this->hopCount = other.hopCount;
}

void KDataMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->dataName);
    doParsimPacking(b,this->dummyPayloadContent);
    doParsimPacking(b,this->msgType);
    doParsimPacking(b,this->validUntilTime);
    doParsimPacking(b,this->msgUniqueID);
    doParsimPacking(b,this->realPayloadSize);
    doParsimPacking(b,this->realPacketSize);
    doParsimPacking(b,this->hopsTravelled);
    doParsimPacking(b,this->injectedTime);
    doParsimPacking(b,this->originatorNodeName);
    doParsimPacking(b,this->finalDestinationNodeName);
    doParsimPacking(b,this->destinationOriented);
    doParsimPacking(b,this->goodnessValue);
    doParsimPacking(b,this->messageID);
    doParsimPacking(b,this->hopCount);
}

void KDataMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->dataName);
    doParsimUnpacking(b,this->dummyPayloadContent);
    doParsimUnpacking(b,this->msgType);
    doParsimUnpacking(b,this->validUntilTime);
    doParsimUnpacking(b,this->msgUniqueID);
    doParsimUnpacking(b,this->realPayloadSize);
    doParsimUnpacking(b,this->realPacketSize);
    doParsimUnpacking(b,this->hopsTravelled);
    doParsimUnpacking(b,this->injectedTime);
    doParsimUnpacking(b,this->originatorNodeName);
    doParsimUnpacking(b,this->finalDestinationNodeName);
    doParsimUnpacking(b,this->destinationOriented);
    doParsimUnpacking(b,this->goodnessValue);
    doParsimUnpacking(b,this->messageID);
    doParsimUnpacking(b,this->hopCount);
}

const char * KDataMsg::getSourceAddress() const
{
    return this->sourceAddress.c_str();
}

void KDataMsg::setSourceAddress(const char * sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

const char * KDataMsg::getDestinationAddress() const
{
    return this->destinationAddress.c_str();
}

void KDataMsg::setDestinationAddress(const char * destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

const char * KDataMsg::getDataName() const
{
    return this->dataName.c_str();
}

void KDataMsg::setDataName(const char * dataName)
{
    this->dataName = dataName;
}

const char * KDataMsg::getDummyPayloadContent() const
{
    return this->dummyPayloadContent.c_str();
}

void KDataMsg::setDummyPayloadContent(const char * dummyPayloadContent)
{
    this->dummyPayloadContent = dummyPayloadContent;
}

int KDataMsg::getMsgType() const
{
    return this->msgType;
}

void KDataMsg::setMsgType(int msgType)
{
    this->msgType = msgType;
}

double KDataMsg::getValidUntilTime() const
{
    return this->validUntilTime;
}

void KDataMsg::setValidUntilTime(double validUntilTime)
{
    this->validUntilTime = validUntilTime;
}

int KDataMsg::getMsgUniqueID() const
{
    return this->msgUniqueID;
}

void KDataMsg::setMsgUniqueID(int msgUniqueID)
{
    this->msgUniqueID = msgUniqueID;
}

int KDataMsg::getRealPayloadSize() const
{
    return this->realPayloadSize;
}

void KDataMsg::setRealPayloadSize(int realPayloadSize)
{
    this->realPayloadSize = realPayloadSize;
}

int KDataMsg::getRealPacketSize() const
{
    return this->realPacketSize;
}

void KDataMsg::setRealPacketSize(int realPacketSize)
{
    this->realPacketSize = realPacketSize;
}

int KDataMsg::getHopsTravelled() const
{
    return this->hopsTravelled;
}

void KDataMsg::setHopsTravelled(int hopsTravelled)
{
    this->hopsTravelled = hopsTravelled;
}

::omnetpp::simtime_t KDataMsg::getInjectedTime() const
{
    return this->injectedTime;
}

void KDataMsg::setInjectedTime(::omnetpp::simtime_t injectedTime)
{
    this->injectedTime = injectedTime;
}

const char * KDataMsg::getOriginatorNodeName() const
{
    return this->originatorNodeName.c_str();
}

void KDataMsg::setOriginatorNodeName(const char * originatorNodeName)
{
    this->originatorNodeName = originatorNodeName;
}

const char * KDataMsg::getFinalDestinationNodeName() const
{
    return this->finalDestinationNodeName.c_str();
}

void KDataMsg::setFinalDestinationNodeName(const char * finalDestinationNodeName)
{
    this->finalDestinationNodeName = finalDestinationNodeName;
}

bool KDataMsg::getDestinationOriented() const
{
    return this->destinationOriented;
}

void KDataMsg::setDestinationOriented(bool destinationOriented)
{
    this->destinationOriented = destinationOriented;
}

int KDataMsg::getGoodnessValue() const
{
    return this->goodnessValue;
}

void KDataMsg::setGoodnessValue(int goodnessValue)
{
    this->goodnessValue = goodnessValue;
}

const char * KDataMsg::getMessageID() const
{
    return this->messageID.c_str();
}

void KDataMsg::setMessageID(const char * messageID)
{
    this->messageID = messageID;
}

int KDataMsg::getHopCount() const
{
    return this->hopCount;
}

void KDataMsg::setHopCount(int hopCount)
{
    this->hopCount = hopCount;
}

class KDataMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    KDataMsgDescriptor();
    virtual ~KDataMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(KDataMsgDescriptor)

KDataMsgDescriptor::KDataMsgDescriptor() : omnetpp::cClassDescriptor("KDataMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

KDataMsgDescriptor::~KDataMsgDescriptor()
{
    delete[] propertynames;
}

bool KDataMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<KDataMsg *>(obj)!=nullptr;
}

const char **KDataMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *KDataMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int KDataMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 17+basedesc->getFieldCount() : 17;
}

unsigned int KDataMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<17) ? fieldTypeFlags[field] : 0;
}

const char *KDataMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceAddress",
        "destinationAddress",
        "dataName",
        "dummyPayloadContent",
        "msgType",
        "validUntilTime",
        "msgUniqueID",
        "realPayloadSize",
        "realPacketSize",
        "hopsTravelled",
        "injectedTime",
        "originatorNodeName",
        "finalDestinationNodeName",
        "destinationOriented",
        "goodnessValue",
        "messageID",
        "hopCount",
    };
    return (field>=0 && field<17) ? fieldNames[field] : nullptr;
}

int KDataMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddress")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataName")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "dummyPayloadContent")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "msgType")==0) return base+4;
    if (fieldName[0]=='v' && strcmp(fieldName, "validUntilTime")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "msgUniqueID")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "realPayloadSize")==0) return base+7;
    if (fieldName[0]=='r' && strcmp(fieldName, "realPacketSize")==0) return base+8;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopsTravelled")==0) return base+9;
    if (fieldName[0]=='i' && strcmp(fieldName, "injectedTime")==0) return base+10;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorNodeName")==0) return base+11;
    if (fieldName[0]=='f' && strcmp(fieldName, "finalDestinationNodeName")==0) return base+12;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationOriented")==0) return base+13;
    if (fieldName[0]=='g' && strcmp(fieldName, "goodnessValue")==0) return base+14;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageID")==0) return base+15;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+16;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *KDataMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
        "string",
        "int",
        "double",
        "int",
        "int",
        "int",
        "int",
        "simtime_t",
        "string",
        "string",
        "bool",
        "int",
        "string",
        "int",
    };
    return (field>=0 && field<17) ? fieldTypeStrings[field] : nullptr;
}

const char **KDataMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *KDataMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int KDataMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    KDataMsg *pp = (KDataMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *KDataMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KDataMsg *pp = (KDataMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string KDataMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KDataMsg *pp = (KDataMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSourceAddress());
        case 1: return oppstring2string(pp->getDestinationAddress());
        case 2: return oppstring2string(pp->getDataName());
        case 3: return oppstring2string(pp->getDummyPayloadContent());
        case 4: return long2string(pp->getMsgType());
        case 5: return double2string(pp->getValidUntilTime());
        case 6: return long2string(pp->getMsgUniqueID());
        case 7: return long2string(pp->getRealPayloadSize());
        case 8: return long2string(pp->getRealPacketSize());
        case 9: return long2string(pp->getHopsTravelled());
        case 10: return simtime2string(pp->getInjectedTime());
        case 11: return oppstring2string(pp->getOriginatorNodeName());
        case 12: return oppstring2string(pp->getFinalDestinationNodeName());
        case 13: return bool2string(pp->getDestinationOriented());
        case 14: return long2string(pp->getGoodnessValue());
        case 15: return oppstring2string(pp->getMessageID());
        case 16: return long2string(pp->getHopCount());
        default: return "";
    }
}

bool KDataMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    KDataMsg *pp = (KDataMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceAddress((value)); return true;
        case 1: pp->setDestinationAddress((value)); return true;
        case 2: pp->setDataName((value)); return true;
        case 3: pp->setDummyPayloadContent((value)); return true;
        case 4: pp->setMsgType(string2long(value)); return true;
        case 5: pp->setValidUntilTime(string2double(value)); return true;
        case 6: pp->setMsgUniqueID(string2long(value)); return true;
        case 7: pp->setRealPayloadSize(string2long(value)); return true;
        case 8: pp->setRealPacketSize(string2long(value)); return true;
        case 9: pp->setHopsTravelled(string2long(value)); return true;
        case 10: pp->setInjectedTime(string2simtime(value)); return true;
        case 11: pp->setOriginatorNodeName((value)); return true;
        case 12: pp->setFinalDestinationNodeName((value)); return true;
        case 13: pp->setDestinationOriented(string2bool(value)); return true;
        case 14: pp->setGoodnessValue(string2long(value)); return true;
        case 15: pp->setMessageID((value)); return true;
        case 16: pp->setHopCount(string2long(value)); return true;
        default: return false;
    }
}

const char *KDataMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *KDataMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    KDataMsg *pp = (KDataMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(KSummaryVectorMsg)

KSummaryVectorMsg::KSummaryVectorMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->realPacketSize = 0;
    messageIDHashVector_arraysize = 0;
    this->messageIDHashVector = 0;
}

KSummaryVectorMsg::KSummaryVectorMsg(const KSummaryVectorMsg& other) : ::omnetpp::cPacket(other)
{
    messageIDHashVector_arraysize = 0;
    this->messageIDHashVector = 0;
    copy(other);
}

KSummaryVectorMsg::~KSummaryVectorMsg()
{
    delete [] this->messageIDHashVector;
}

KSummaryVectorMsg& KSummaryVectorMsg::operator=(const KSummaryVectorMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void KSummaryVectorMsg::copy(const KSummaryVectorMsg& other)
{
    this->sourceAddress = other.sourceAddress;
    this->destinationAddress = other.destinationAddress;
    this->realPacketSize = other.realPacketSize;
    delete [] this->messageIDHashVector;
    this->messageIDHashVector = (other.messageIDHashVector_arraysize==0) ? nullptr : new ::omnetpp::opp_string[other.messageIDHashVector_arraysize];
    messageIDHashVector_arraysize = other.messageIDHashVector_arraysize;
    for (unsigned int i=0; i<messageIDHashVector_arraysize; i++)
        this->messageIDHashVector[i] = other.messageIDHashVector[i];
}

void KSummaryVectorMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->realPacketSize);
    b->pack(messageIDHashVector_arraysize);
    doParsimArrayPacking(b,this->messageIDHashVector,messageIDHashVector_arraysize);
}

void KSummaryVectorMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->realPacketSize);
    delete [] this->messageIDHashVector;
    b->unpack(messageIDHashVector_arraysize);
    if (messageIDHashVector_arraysize==0) {
        this->messageIDHashVector = 0;
    } else {
        this->messageIDHashVector = new ::omnetpp::opp_string[messageIDHashVector_arraysize];
        doParsimArrayUnpacking(b,this->messageIDHashVector,messageIDHashVector_arraysize);
    }
}

const char * KSummaryVectorMsg::getSourceAddress() const
{
    return this->sourceAddress.c_str();
}

void KSummaryVectorMsg::setSourceAddress(const char * sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

const char * KSummaryVectorMsg::getDestinationAddress() const
{
    return this->destinationAddress.c_str();
}

void KSummaryVectorMsg::setDestinationAddress(const char * destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

int KSummaryVectorMsg::getRealPacketSize() const
{
    return this->realPacketSize;
}

void KSummaryVectorMsg::setRealPacketSize(int realPacketSize)
{
    this->realPacketSize = realPacketSize;
}

void KSummaryVectorMsg::setMessageIDHashVectorArraySize(unsigned int size)
{
    ::omnetpp::opp_string *messageIDHashVector2 = (size==0) ? nullptr : new ::omnetpp::opp_string[size];
    unsigned int sz = messageIDHashVector_arraysize < size ? messageIDHashVector_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        messageIDHashVector2[i] = this->messageIDHashVector[i];
    for (unsigned int i=sz; i<size; i++)
        messageIDHashVector2[i] = 0;
    messageIDHashVector_arraysize = size;
    delete [] this->messageIDHashVector;
    this->messageIDHashVector = messageIDHashVector2;
}

unsigned int KSummaryVectorMsg::getMessageIDHashVectorArraySize() const
{
    return messageIDHashVector_arraysize;
}

const char * KSummaryVectorMsg::getMessageIDHashVector(unsigned int k) const
{
    if (k>=messageIDHashVector_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", messageIDHashVector_arraysize, k);
    return this->messageIDHashVector[k].c_str();
}

void KSummaryVectorMsg::setMessageIDHashVector(unsigned int k, const char * messageIDHashVector)
{
    if (k>=messageIDHashVector_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", messageIDHashVector_arraysize, k);
    this->messageIDHashVector[k] = messageIDHashVector;
}

class KSummaryVectorMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    KSummaryVectorMsgDescriptor();
    virtual ~KSummaryVectorMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(KSummaryVectorMsgDescriptor)

KSummaryVectorMsgDescriptor::KSummaryVectorMsgDescriptor() : omnetpp::cClassDescriptor("KSummaryVectorMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

KSummaryVectorMsgDescriptor::~KSummaryVectorMsgDescriptor()
{
    delete[] propertynames;
}

bool KSummaryVectorMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<KSummaryVectorMsg *>(obj)!=nullptr;
}

const char **KSummaryVectorMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *KSummaryVectorMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int KSummaryVectorMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int KSummaryVectorMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *KSummaryVectorMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceAddress",
        "destinationAddress",
        "realPacketSize",
        "messageIDHashVector",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int KSummaryVectorMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddress")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "realPacketSize")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageIDHashVector")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *KSummaryVectorMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "int",
        "string",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **KSummaryVectorMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *KSummaryVectorMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int KSummaryVectorMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    KSummaryVectorMsg *pp = (KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        case 3: return pp->getMessageIDHashVectorArraySize();
        default: return 0;
    }
}

const char *KSummaryVectorMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KSummaryVectorMsg *pp = (KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string KSummaryVectorMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KSummaryVectorMsg *pp = (KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSourceAddress());
        case 1: return oppstring2string(pp->getDestinationAddress());
        case 2: return long2string(pp->getRealPacketSize());
        case 3: return oppstring2string(pp->getMessageIDHashVector(i));
        default: return "";
    }
}

bool KSummaryVectorMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    KSummaryVectorMsg *pp = (KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceAddress((value)); return true;
        case 1: pp->setDestinationAddress((value)); return true;
        case 2: pp->setRealPacketSize(string2long(value)); return true;
        case 3: pp->setMessageIDHashVector(i,(value)); return true;
        default: return false;
    }
}

const char *KSummaryVectorMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *KSummaryVectorMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    KSummaryVectorMsg *pp = (KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(KDataRequestMsg)

KDataRequestMsg::KDataRequestMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->realPacketSize = 0;
    messageIDHashVector_arraysize = 0;
    this->messageIDHashVector = 0;
}

KDataRequestMsg::KDataRequestMsg(const KDataRequestMsg& other) : ::omnetpp::cPacket(other)
{
    messageIDHashVector_arraysize = 0;
    this->messageIDHashVector = 0;
    copy(other);
}

KDataRequestMsg::~KDataRequestMsg()
{
    delete [] this->messageIDHashVector;
}

KDataRequestMsg& KDataRequestMsg::operator=(const KDataRequestMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void KDataRequestMsg::copy(const KDataRequestMsg& other)
{
    this->sourceAddress = other.sourceAddress;
    this->destinationAddress = other.destinationAddress;
    this->realPacketSize = other.realPacketSize;
    delete [] this->messageIDHashVector;
    this->messageIDHashVector = (other.messageIDHashVector_arraysize==0) ? nullptr : new ::omnetpp::opp_string[other.messageIDHashVector_arraysize];
    messageIDHashVector_arraysize = other.messageIDHashVector_arraysize;
    for (unsigned int i=0; i<messageIDHashVector_arraysize; i++)
        this->messageIDHashVector[i] = other.messageIDHashVector[i];
}

void KDataRequestMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->realPacketSize);
    b->pack(messageIDHashVector_arraysize);
    doParsimArrayPacking(b,this->messageIDHashVector,messageIDHashVector_arraysize);
}

void KDataRequestMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->realPacketSize);
    delete [] this->messageIDHashVector;
    b->unpack(messageIDHashVector_arraysize);
    if (messageIDHashVector_arraysize==0) {
        this->messageIDHashVector = 0;
    } else {
        this->messageIDHashVector = new ::omnetpp::opp_string[messageIDHashVector_arraysize];
        doParsimArrayUnpacking(b,this->messageIDHashVector,messageIDHashVector_arraysize);
    }
}

const char * KDataRequestMsg::getSourceAddress() const
{
    return this->sourceAddress.c_str();
}

void KDataRequestMsg::setSourceAddress(const char * sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

const char * KDataRequestMsg::getDestinationAddress() const
{
    return this->destinationAddress.c_str();
}

void KDataRequestMsg::setDestinationAddress(const char * destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

int KDataRequestMsg::getRealPacketSize() const
{
    return this->realPacketSize;
}

void KDataRequestMsg::setRealPacketSize(int realPacketSize)
{
    this->realPacketSize = realPacketSize;
}

void KDataRequestMsg::setMessageIDHashVectorArraySize(unsigned int size)
{
    ::omnetpp::opp_string *messageIDHashVector2 = (size==0) ? nullptr : new ::omnetpp::opp_string[size];
    unsigned int sz = messageIDHashVector_arraysize < size ? messageIDHashVector_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        messageIDHashVector2[i] = this->messageIDHashVector[i];
    for (unsigned int i=sz; i<size; i++)
        messageIDHashVector2[i] = 0;
    messageIDHashVector_arraysize = size;
    delete [] this->messageIDHashVector;
    this->messageIDHashVector = messageIDHashVector2;
}

unsigned int KDataRequestMsg::getMessageIDHashVectorArraySize() const
{
    return messageIDHashVector_arraysize;
}

const char * KDataRequestMsg::getMessageIDHashVector(unsigned int k) const
{
    if (k>=messageIDHashVector_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", messageIDHashVector_arraysize, k);
    return this->messageIDHashVector[k].c_str();
}

void KDataRequestMsg::setMessageIDHashVector(unsigned int k, const char * messageIDHashVector)
{
    if (k>=messageIDHashVector_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", messageIDHashVector_arraysize, k);
    this->messageIDHashVector[k] = messageIDHashVector;
}

class KDataRequestMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    KDataRequestMsgDescriptor();
    virtual ~KDataRequestMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(KDataRequestMsgDescriptor)

KDataRequestMsgDescriptor::KDataRequestMsgDescriptor() : omnetpp::cClassDescriptor("KDataRequestMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

KDataRequestMsgDescriptor::~KDataRequestMsgDescriptor()
{
    delete[] propertynames;
}

bool KDataRequestMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<KDataRequestMsg *>(obj)!=nullptr;
}

const char **KDataRequestMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *KDataRequestMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int KDataRequestMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int KDataRequestMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *KDataRequestMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceAddress",
        "destinationAddress",
        "realPacketSize",
        "messageIDHashVector",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int KDataRequestMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddress")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "realPacketSize")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageIDHashVector")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *KDataRequestMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "int",
        "string",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **KDataRequestMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *KDataRequestMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int KDataRequestMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    KDataRequestMsg *pp = (KDataRequestMsg *)object; (void)pp;
    switch (field) {
        case 3: return pp->getMessageIDHashVectorArraySize();
        default: return 0;
    }
}

const char *KDataRequestMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KDataRequestMsg *pp = (KDataRequestMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string KDataRequestMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KDataRequestMsg *pp = (KDataRequestMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSourceAddress());
        case 1: return oppstring2string(pp->getDestinationAddress());
        case 2: return long2string(pp->getRealPacketSize());
        case 3: return oppstring2string(pp->getMessageIDHashVector(i));
        default: return "";
    }
}

bool KDataRequestMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    KDataRequestMsg *pp = (KDataRequestMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceAddress((value)); return true;
        case 1: pp->setDestinationAddress((value)); return true;
        case 2: pp->setRealPacketSize(string2long(value)); return true;
        case 3: pp->setMessageIDHashVector(i,(value)); return true;
        default: return false;
    }
}

const char *KDataRequestMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *KDataRequestMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    KDataRequestMsg *pp = (KDataRequestMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


