
#include <AzCore/Serialization/SerializeContext.h>
#include "PulseEngineEditorSystemComponent.h"

namespace PulseEngine
{
    void PulseEngineEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<PulseEngineEditorSystemComponent, PulseEngineSystemComponent>()
                ->Version(0);
        }
    }

    PulseEngineEditorSystemComponent::PulseEngineEditorSystemComponent() = default;

    PulseEngineEditorSystemComponent::~PulseEngineEditorSystemComponent() = default;

    void PulseEngineEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("PulseEngineEditorService"));
    }

    void PulseEngineEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("PulseEngineEditorService"));
    }

    void PulseEngineEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void PulseEngineEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void PulseEngineEditorSystemComponent::Activate()
    {
        PulseEngineSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void PulseEngineEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        PulseEngineSystemComponent::Deactivate();
    }

} // namespace PulseEngine
