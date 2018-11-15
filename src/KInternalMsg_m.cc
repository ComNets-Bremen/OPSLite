//
// Generated file, do not edit! Created by nedtool 5.4 from KInternalMsg.msg.
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
#include "KInternalMsg_m.h"

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

Register_Class(KRegisterAppMsg)

KRegisterAppMsg::KRegisterAppMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
}

KRegisterAppMsg::KRegisterAppMsg(const KRegisterAppMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

KRegisterAppMsg::~KRegisterAppMsg()
{
}

KRegisterAppMsg& KRegisterAppMsg::operator=(const KRegisterAppMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void KRegisterAppMsg::copy(const KRegisterAppMsg& other)
{
    this->appName = other.appName;
    this->prefixName = other.prefixName;
}

void KRegisterAppMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->appName);
    doParsimPacking(b,this->prefixName);
}

void KRegisterAppMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->appName);
    doParsimUnpacking(b,this->prefixName);
}

const char * KRegisterAppMsg::getAppName() const
{
    return this->appName.c_str();
}

void KRegisterAppMsg::setAppName(const char * appName)
{
    this->appName = appName;
}

const char * KRegisterAppMsg::getPrefixName() const
{
    return this->prefixName.c_str();
}

void KRegisterAppMsg::setPrefixName(const char * prefixName)
{
    this->prefixName = prefixName;
}

class KRegisterAppMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    KRegisterAppMsgDescriptor();
    virtual ~KRegisterAppMsgDescriptor();

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

Register_ClassDescriptor(KRegisterAppMsgDescriptor)

KRegisterAppMsgDescriptor::KRegisterAppMsgDescriptor() : omnetpp::cClassDescriptor("KRegisterAppMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

KRegisterAppMsgDescriptor::~KRegisterAppMsgDescriptor()
{
    delete[] propertynames;
}

bool KRegisterAppMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<KRegisterAppMsg *>(obj)!=nullptr;
}

const char **KRegisterAppMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *KRegisterAppMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int KRegisterAppMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int KRegisterAppMsgDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *KRegisterAppMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "appName",
        "prefixName",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int KRegisterAppMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "appName")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixName")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *KRegisterAppMsgDescriptor::getFieldTypeString(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **KRegisterAppMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *KRegisterAppMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int KRegisterAppMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    KRegisterAppMsg *pp = (KRegisterAppMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *KRegisterAppMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KRegisterAppMsg *pp = (KRegisterAppMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string KRegisterAppMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KRegisterAppMsg *pp = (KRegisterAppMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getAppName());
        case 1: return oppstring2string(pp->getPrefixName());
        default: return "";
    }
}

bool KRegisterAppMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    KRegisterAppMsg *pp = (KRegisterAppMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setAppName((value)); return true;
        case 1: pp->setPrefixName((value)); return true;
        default: return false;
    }
}

const char *KRegisterAppMsgDescriptor::getFieldStructName(int field) const
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

void *KRegisterAppMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    KRegisterAppMsg *pp = (KRegisterAppMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(KNeighbourListMsg)

KNeighbourListMsg::KNeighbourListMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    neighbourNameList_arraysize = 0;
    this->neighbourNameList = 0;
    this->neighbourNameCount = 0;
}

KNeighbourListMsg::KNeighbourListMsg(const KNeighbourListMsg& other) : ::omnetpp::cPacket(other)
{
    neighbourNameList_arraysize = 0;
    this->neighbourNameList = 0;
    copy(other);
}

KNeighbourListMsg::~KNeighbourListMsg()
{
    delete [] this->neighbourNameList;
}

KNeighbourListMsg& KNeighbourListMsg::operator=(const KNeighbourListMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void KNeighbourListMsg::copy(const KNeighbourListMsg& other)
{
    delete [] this->neighbourNameList;
    this->neighbourNameList = (other.neighbourNameList_arraysize==0) ? nullptr : new ::omnetpp::opp_string[other.neighbourNameList_arraysize];
    neighbourNameList_arraysize = other.neighbourNameList_arraysize;
    for (unsigned int i=0; i<neighbourNameList_arraysize; i++)
        this->neighbourNameList[i] = other.neighbourNameList[i];
    this->neighbourNameCount = other.neighbourNameCount;
}

void KNeighbourListMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    b->pack(neighbourNameList_arraysize);
    doParsimArrayPacking(b,this->neighbourNameList,neighbourNameList_arraysize);
    doParsimPacking(b,this->neighbourNameCount);
}

void KNeighbourListMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    delete [] this->neighbourNameList;
    b->unpack(neighbourNameList_arraysize);
    if (neighbourNameList_arraysize==0) {
        this->neighbourNameList = 0;
    } else {
        this->neighbourNameList = new ::omnetpp::opp_string[neighbourNameList_arraysize];
        doParsimArrayUnpacking(b,this->neighbourNameList,neighbourNameList_arraysize);
    }
    doParsimUnpacking(b,this->neighbourNameCount);
}

void KNeighbourListMsg::setNeighbourNameListArraySize(unsigned int size)
{
    ::omnetpp::opp_string *neighbourNameList2 = (size==0) ? nullptr : new ::omnetpp::opp_string[size];
    unsigned int sz = neighbourNameList_arraysize < size ? neighbourNameList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        neighbourNameList2[i] = this->neighbourNameList[i];
    for (unsigned int i=sz; i<size; i++)
        neighbourNameList2[i] = 0;
    neighbourNameList_arraysize = size;
    delete [] this->neighbourNameList;
    this->neighbourNameList = neighbourNameList2;
}

unsigned int KNeighbourListMsg::getNeighbourNameListArraySize() const
{
    return neighbourNameList_arraysize;
}

const char * KNeighbourListMsg::getNeighbourNameList(unsigned int k) const
{
    if (k>=neighbourNameList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", neighbourNameList_arraysize, k);
    return this->neighbourNameList[k].c_str();
}

void KNeighbourListMsg::setNeighbourNameList(unsigned int k, const char * neighbourNameList)
{
    if (k>=neighbourNameList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", neighbourNameList_arraysize, k);
    this->neighbourNameList[k] = neighbourNameList;
}

int KNeighbourListMsg::getNeighbourNameCount() const
{
    return this->neighbourNameCount;
}

void KNeighbourListMsg::setNeighbourNameCount(int neighbourNameCount)
{
    this->neighbourNameCount = neighbourNameCount;
}

class KNeighbourListMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    KNeighbourListMsgDescriptor();
    virtual ~KNeighbourListMsgDescriptor();

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

Register_ClassDescriptor(KNeighbourListMsgDescriptor)

KNeighbourListMsgDescriptor::KNeighbourListMsgDescriptor() : omnetpp::cClassDescriptor("KNeighbourListMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

KNeighbourListMsgDescriptor::~KNeighbourListMsgDescriptor()
{
    delete[] propertynames;
}

bool KNeighbourListMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<KNeighbourListMsg *>(obj)!=nullptr;
}

const char **KNeighbourListMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *KNeighbourListMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int KNeighbourListMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int KNeighbourListMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *KNeighbourListMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "neighbourNameList",
        "neighbourNameCount",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int KNeighbourListMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighbourNameList")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighbourNameCount")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *KNeighbourListMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **KNeighbourListMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *KNeighbourListMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int KNeighbourListMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    KNeighbourListMsg *pp = (KNeighbourListMsg *)object; (void)pp;
    switch (field) {
        case 0: return pp->getNeighbourNameListArraySize();
        default: return 0;
    }
}

const char *KNeighbourListMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KNeighbourListMsg *pp = (KNeighbourListMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string KNeighbourListMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KNeighbourListMsg *pp = (KNeighbourListMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getNeighbourNameList(i));
        case 1: return long2string(pp->getNeighbourNameCount());
        default: return "";
    }
}

bool KNeighbourListMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    KNeighbourListMsg *pp = (KNeighbourListMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setNeighbourNameList(i,(value)); return true;
        case 1: pp->setNeighbourNameCount(string2long(value)); return true;
        default: return false;
    }
}

const char *KNeighbourListMsgDescriptor::getFieldStructName(int field) const
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

void *KNeighbourListMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    KNeighbourListMsg *pp = (KNeighbourListMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


