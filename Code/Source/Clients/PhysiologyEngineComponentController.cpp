#include "PhysiologyEngineComponentController.h"
#include <AzCore/Component/TickBus.h>

#include <cdm/PhysiologyEngine.h>
#include <cdm/properties/SEScalarTime.h>
#include <engine/PulseEngine.h>

namespace PulseEngine {

    void PhysiologyEngineComponentController::Reflect(AZ::ReflectContext* context)
    {

    }

    PhysiologyEngineComponentController::PhysiologyEngineComponentController(const PhysiologyEngineComponentConfig &config)
    {
        SetConfiguration(config);
    }

    void PhysiologyEngineComponentController::OnTick(float deltaTime, AZ::ScriptTimePoint time)
    {
        if(m_pulseEngine) 
        {
            // m_pulseEngine->GetSimulationTime(TimeUnit::s);
        }
    }

    void PhysiologyEngineComponentController::Init()
    {

    }
    
    const PhysiologyEngineComponentConfig& PhysiologyEngineComponentController::GetConfiguration() const
    {
        return m_config;
    }

    void PhysiologyEngineComponentController::SetConfiguration(const PhysiologyEngineComponentConfig &config)
    {
        m_config = config;
        m_pulseEngine.reset(CreatePulseEngine(config.m_modelType).release());
    }

    void PhysiologyEngineComponentController::Activate(AZ::EntityId entityId)
    {
        AZ::TickBus::Handler::BusConnect();
    }

    void PhysiologyEngineComponentController::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
    }

}