
#pragma once

#include <AzCore/Component/Component.h>
#include <AzCore/Component/ComponentBus.h>
#include <AzCore/base.h>
#include <AzCore/Asset/AssetCommon.h>
#include <AzCore/Component/ComponentBus.h>
#include <AzCore/RTTI/RTTI.h>
#include <AzCore/Serialization/EditContext.h>

#include <engine/PulseEngine.h>

namespace PulseEngine {
class PhysiologyEngineComponentConfig final : public AZ::ComponentConfig {
public:
  AZ_RTTI(PhysiologyEngineComponentConfig,
          "{A70A5D7A-3DF6-4682-8CD1-C05A66205184}");

  static void Reflect(AZ::ReflectContext *context);

  eModelType m_modelType = eModelType::HumanAdultWholeBody;
};
} // namespace PulseEngine