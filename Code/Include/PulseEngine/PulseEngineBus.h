
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace PulseEngine
{

    class PulseEngineRequests
    {
    public:
        AZ_RTTI(PulseEngineRequests, "{DC03323B-CB9F-4822-BCDE-56C87EAEDB75}");
        virtual ~PulseEngineRequests() = default;
        // Put your public methods here
    };
    
    class PulseEngineBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using PulseEngineRequestBus = AZ::EBus<PulseEngineRequests, PulseEngineBusTraits>;
    using PulseEngineInterface = AZ::Interface<PulseEngineRequests>;

} // namespace PulseEngine
