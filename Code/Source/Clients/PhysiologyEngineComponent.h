#pragma once

#include <AzCore/std/smart_ptr/unique_ptr.h>
#include <AzCore/Component/Component.h>

#include <cdm/PhysiologyEngine.h>

namespace PulseEngine 
{
    class PhysiologyEngineComponent : 
        public AZ::Component 
    {
    public:
        AZ_COMPONENT(PulseEngineComponent, "{E13A67CA-50BC-4C04-A502-DD62BDE8BDB7}",
                    AZ::Component)
        static void Reflect(AZ::ReflectContext* context);

        PulseEngineComponent() = default;
        // PulseEngineComponent(const PulseEngineComponent &component);

    private:
        // AZ::Component ...
        void Activate() override;
        void Deactivate() override;

        AZStd::unique_ptr<PhysiologyEngine> m_pulseEngine;
    };
} // namespace PulseEngine