
#include "PulseEngineSystemComponent.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

namespace PulseEngine
{
    void PulseEngineSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PulseEngineSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PulseEngineSystemComponent>("PulseEngine", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PulseEngineSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("PulseEngineService"));
    }

    void PulseEngineSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("PulseEngineService"));
    }

    void PulseEngineSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void PulseEngineSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    PulseEngineSystemComponent::PulseEngineSystemComponent()
    {
        if (PulseEngineInterface::Get() == nullptr)
        {
            PulseEngineInterface::Register(this);
        }
    }

    PulseEngineSystemComponent::~PulseEngineSystemComponent()
    {
        if (PulseEngineInterface::Get() == this)
        {
            PulseEngineInterface::Unregister(this);
        }
    }

    void PulseEngineSystemComponent::Init()
    {
    }

    void PulseEngineSystemComponent::Activate()
    {
        PulseEngineRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void PulseEngineSystemComponent::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        PulseEngineRequestBus::Handler::BusDisconnect();
    }

    void PulseEngineSystemComponent::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }

} // namespace PulseEngine
