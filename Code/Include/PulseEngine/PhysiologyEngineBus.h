#pragma once

#include <AzCore/Component/ComponentBus.h>
namespace PulseEngine {

class PhysiologyEvents : public AZ::EntityComponentBus {
public:
  AZ_RTTI(PhysiologyEvents, "{DF79B555-D9E9-489A-8A00-AD39C564E258}");

  // static const AZ::EBusHandlerPolicy HandlerPolicy =
  // AZ::EBusHandlerPolicy::MultipleAndOrdered;

  virtual void OnSimulationTimeStep(float deltaTime, float simTime);

  virtual void OnPatientDeath(float deltaTime, float simTime);
};

using PhysiologyNotificationEBus = AZ::EBus<PhysiologyEvents>;

} // namespace PulseEngine