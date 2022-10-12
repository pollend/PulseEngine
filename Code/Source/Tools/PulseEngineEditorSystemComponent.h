
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <Clients/PulseEngineSystemComponent.h>

namespace PulseEngine
{
    /// System component for PulseEngine editor
    class PulseEngineEditorSystemComponent
        : public PulseEngineSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = PulseEngineSystemComponent;
    public:
        AZ_COMPONENT(PulseEngineEditorSystemComponent, "{AA6CAEED-07F2-468A-A623-780280BC6996}", BaseSystemComponent);
        static void Reflect(AZ::ReflectContext* context);

        PulseEngineEditorSystemComponent();
        ~PulseEngineEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace PulseEngine
