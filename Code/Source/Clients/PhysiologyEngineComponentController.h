#pragma once

#include <AzCore/Component/Component.h>
#include <AzCore/base.h>

#include "AzCore/Component/ComponentBus.h"
#include "PhysiologyEngineComponentConfig.h"
#include <AzCore/Component/TickBus.h>

namespace PulseEngine {

class PhysiologyEngineComponentController : 
  public AZ::TickBus::Handler,
  public PhysiologyEngineRequestBus::Handler {
public:
    AZ_TYPE_INFO(PhysiologyEngineComponentController,
                "{FF36A760-7CB9-4C91-BFA1-A6094804E564}");

    static void Reflect(AZ::ReflectContext* context);

    PhysiologyEngineComponentController() = default;
    explicit PhysiologyEngineComponentController(
    const PhysiologyEngineComponentConfig &config);

    void SetConfiguration(const PhysiologyEngineComponentConfig &config);
    const PhysiologyEngineComponentConfig& GetConfiguration() const;
    
    void Init();
    void Activate(AZ::EntityComponentIdPair entityId);
    void Deactivate();
protected:

  // AZ::TickBus
  void OnTick(float deltaTime, AZ::ScriptTimePoint time) override;

private:
  AZ_DISABLE_COPY(PhysiologyEngineComponentController);

  PhysiologyEngineComponentConfig m_config;

  AZStd::unique_ptr<PhysiologyEngine> m_pulseEngine = nullptr;
  AZStd::unique_ptr<LoggerForward> m_pulseLogger = nullptr;
  double m_TimeStep_s = 0;
  double m_CurrentTime_s = 0;
  AZ::EntityComponentIdPair m_entityId;
};

} // namespace PulseEngine