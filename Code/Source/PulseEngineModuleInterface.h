
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include <Clients/PulseEngineSystemComponent.h>
#include <Clients/PhysiologyEngineComponent.h>

namespace PulseEngine
{
    class PulseEngineModuleInterface
        : public AZ::Module
    {
    public:
        AZ_RTTI(PulseEngineModuleInterface, "{E5527E6D-2935-4830-9D18-EBB72E09FC12}", AZ::Module);
        AZ_CLASS_ALLOCATOR(PulseEngineModuleInterface, AZ::SystemAllocator, 0);

        PulseEngineModuleInterface()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                PulseEngineSystemComponent::CreateDescriptor(),
                PhysiologyEngineComponent::CreateDescriptor()
                });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<PulseEngineSystemComponent>(),
            };
        }
    };
}// namespace PulseEngine
