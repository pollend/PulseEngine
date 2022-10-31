#include "PhysiologyEngineComponent.h"
#include <AzCore/Component/Component.h>

namespace PulseEngine {

    void PhysiologyEngineComponent::Reflect(AZ::ReflectContext *context) {
        PhysiologyEngineComponentBase::Reflect(context);
    }

    PhysiologyEngineComponent::PhysiologyEngineComponent(const PhysiologyEngineComponentConfig& config) :
        PhysiologyEngineComponentBase(config)
    {
    }

} // namespace PulseEngine