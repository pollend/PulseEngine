#include "AzCore/RTTI/RTTI.h"

#include "PhysiologyEngineComponentConfig.h"

namespace PulseEngine {

    void PhysiologyEngineComponentConfig::Reflect(AZ::ReflectContext *context) {
        if (auto* serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<PhysiologyEngineComponentConfig>()
                ->Version(1)
                ->Field("ModelType", &PhysiologyEngineComponentConfig::m_modelType);
        }
    }
}