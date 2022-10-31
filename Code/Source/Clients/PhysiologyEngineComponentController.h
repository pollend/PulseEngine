#pragma once

#include <AzCore/Component/Component.h>
#include <AzCore/base.h>

#include "PhysiologyEnginComponentConfig.h"
#include <AzCore/Component/TickBus.h>

namespace PulseEngine {

class PhysiologyEngineComponentController : public AZ::TickBus::Handler {
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
    void Activate(AZ::EntityId entityId);
    void Deactivate();
protected:

  // AZ::TickBus
  void OnTick(float deltaTime, AZ::ScriptTimePoint time) override;

private:
  AZ_DISABLE_COPY(PhysiologyEngineComponentController);

    PhysiologyEngineComponentConfig m_config;

  AZStd::unique_ptr<PhysiologyEngine> m_pulseEngine;
  AZStd::unique_ptr<LoggerForward> m_pulseLogger;
};

} // namespace PulseEngine