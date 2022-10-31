
#include <PulseEngineModuleInterface.h>

#include "PulseEngineEditorSystemComponent.h"
// #include "EditorPhysiologyEngineComponent.h"

namespace PulseEngine
{
    class PulseEngineEditorModule
        : public PulseEngineModuleInterface
    {
    public:
        AZ_RTTI(PulseEngineEditorModule, "{079E243D-F8EE-429D-B0A4-8434EDD09308}", PulseEngineModuleInterface);
        AZ_CLASS_ALLOCATOR(PulseEngineEditorModule, AZ::SystemAllocator, 0);

        PulseEngineEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                PulseEngineEditorSystemComponent::CreateDescriptor(),
                // EditorPhysiologyEngineComponent::CreateDescriptor()
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<PulseEngineEditorSystemComponent>(),
            };
        }
    };
}// namespace PulseEngine

AZ_DECLARE_MODULE_CLASS(Gem_PulseEngine, PulseEngine::PulseEngineEditorModule)
