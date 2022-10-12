

#include <PulseEngineModuleInterface.h>
#include "PulseEngineSystemComponent.h"

namespace PulseEngine
{
    class PulseEngineModule
        : public PulseEngineModuleInterface
    {
    public:
        AZ_RTTI(PulseEngineModule, "{079E243D-F8EE-429D-B0A4-8434EDD09308}", PulseEngineModuleInterface);
        AZ_CLASS_ALLOCATOR(PulseEngineModule, AZ::SystemAllocator, 0);
    };
}// namespace PulseEngine

AZ_DECLARE_MODULE_CLASS(Gem_PulseEngine, PulseEngine::PulseEngineModule)
