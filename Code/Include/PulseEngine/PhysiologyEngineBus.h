#pragma once

#include <AzCore/Component/ComponentBus.h>
namespace PulseEngine
{

    class PhysiologyEvents : public AZ::ComponentBus
    {
    public:
        AZ_RTTI(PhysiologyEvents, "{DF79B555-D9E9-489A-8A00-AD39C564E258}");

        virtual void OnSimulationTimeStep(double simTime);

        virtual void OnSimulationReady();
    };

    using PhysiologyNotificationBus = AZ::EBus<PhysiologyEvents>;

    class PhysiologyEngineRequest : public AZ::ComponentBus
    {
    };
    using PhysiologyEngineRequestBus = AZ::EBus<PhysiologyEngineRequest>;

} // namespace PulseEngine