#include "SimObjectBuilder.h"
#include "utils/JsonUtil.h"
#include "sim/BaseObject.h"
#include "sim/SoftBody.h"
cBaseObjectPtr BuildSimObj(const Json::Value &conf, int id_)
{
    eObjectType type = cBaseObject::BuildObjectType(cJsonUtil::ParseAsString("object_type", conf));
    cBaseObjectPtr object = nullptr;
    switch (type)
    {
    case eObjectType::ACOUSTIC_TYPE:
    {
        SIM_ERROR("do not support acoustic type");
        break;
    }
    case eObjectType::SOFTBODY_TYPE:
    {
        object = std::make_shared<cSoftBody>(id_);
        break;
    }
    default:
        SIM_ERROR("unrecognized object type {}", type);
        break;
    };
    if (object)
        object->Init(conf);
    return object;
}