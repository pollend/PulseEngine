#pragma once

#include <AzFramework/Components/ComponentAdapter.h>

#include <AzCore/Component/Component.h>
#include <AzCore/std/smart_ptr/unique_ptr.h>

#include "PhysiologyEngineComponentController.h"

class LoggerForward;
class PhysiologyEngine;

namespace PulseEngine {

using PhysiologyEngineComponentBase = AzFramework::Components::ComponentAdapter<PhysiologyEngineComponentController, PhysiologyEngineComponentConfig>;
class PhysiologyEngineComponent : public PhysiologyEngineComponentBase {
public:
  AZ_COMPONENT(PhysiologyEngineComponent,
               "{E13A67CA-50BC-4C04-A502-DD62BDE8BDB7}", AZ::Component)
  static void Reflect(AZ::ReflectContext *context);

  PhysiologyEngineComponent() = default;
  explicit PhysiologyEngineComponent(const PhysiologyEngineComponentConfig& config);

protected:
private:

};

} // namespace PulseEngine