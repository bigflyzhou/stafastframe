// -------------------------------------------------------------------------
//    @FileName      :    NFCPropertyConfigModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-09-30
//    @Module           :    NFCPropertyConfigModule
//
// -------------------------------------------------------------------------

#ifndef _NFC_PROPERTY_CONFIG_MODULE_H_
#define _NFC_PROPERTY_CONFIG_MODULE_H_

#include "NFComm/Config/NFConfig.h"
#include "NFComm/RapidXML/rapidxml.hpp"
#include "NFComm/RapidXML/rapidxml_iterators.hpp"
#include "NFComm/RapidXML/rapidxml_print.hpp"
#include "NFComm/RapidXML/rapidxml_utils.hpp"
#include "NFComm/NFPluginModule/NFIPropertyConfigModule.h"

class NFCPropertyConfigModule
    : public NFIPropertyConfigModule
{
public:
    NFCPropertyConfigModule( NFIPluginManager* p )
    {
        pPluginManager = p;
    }
    virtual ~NFCPropertyConfigModule() {};

    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute( const float fLasFrametime, const float fStartedTime );
    virtual bool AfterInit();

    //����ֵ=�ȼ�+ϵ��+����
    //virtual int CalculateBaseValue(const NFJobType nJob, const int nLevel, NFRumTimeColIndex eProperty);
    virtual int CalculateBaseValue( const NFJobType nJob, const int nLevel, const std::string& strProperty );

    virtual bool NeedView(const std::string& strProperty);

protected:
    void Load();
    void InitViewPropertyList();
private:
    typedef std::map<std::string, int> JOB_PROPERTY_STRUCT;
    //�ȼ�->(������������ֵ)
    NFMap<int, JOB_PROPERTY_STRUCT> mhtCoefficienData[( int )NFJobType::NJT_MAX];

    NFList<std::string> mViewPropertyList; // �ͻ��˲鿴��ɫ���Ա�
};


#endif