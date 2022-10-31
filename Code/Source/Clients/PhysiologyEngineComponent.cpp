#include "PhysiologyEngineComponent.h"

#include <AzCore/Component/Component.h>

namespace PulseEngine {

    void PhysiologyEngineComponent::Reflect(AZ::ReflectContext *context) {
        PhysiologyEngineComponentBase::Reflect(context);

        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<PhysiologyEngineComponent, PhysiologyEngineComponentBase>()
                ->Version(1);
        }

    }

    PhysiologyEngineComponent::PhysiologyEngineComponent(const PhysiologyEngineComponentConfig& config) :
        PhysiologyEngineComponentBase(config)
    {
    }

} // namespace PulseEngine