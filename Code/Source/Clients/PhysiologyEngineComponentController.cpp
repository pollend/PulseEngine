#include "PhysiologyEngineComponentController.h"

#include <AzCore/Component/TickBus.h>
#include <AzCore/Console/ILogger.h>

#include <PulseEngine/PhysiologyEngineBus.h>

#include <cdm/PhysiologyEngine.h>
#include <cdm/properties/SEScalarTime.h>
#include <cdm/utils/Logger.h>
#include <engine/PulseEngine.h>

namespace PulseEngine
{
    class PulseLogger : public LoggerForward
    {
        void ForwardDebug(const std::string& msg, const std::string& origin) override
        {
            AZLOG_DEBUG("PhysiologyEngine: %s%s", msg.c_str(), origin.c_str());
        }
        void ForwardInfo(const std::string& msg, const std::string& origin) override
        {
            AZLOG_INFO("PhysiologyEngine: %s%s", msg.c_str(), origin.c_str());
        }
        void ForwardWarning(const std::string& msg, const std::string& origin) override
        {
            AZLOG_WARN("PhysiologyEngine: %s%s", msg.c_str(), origin.c_str());
        }
        void ForwardError(const std::string& msg, const std::string& origin) override
        {
            AZLOG_ERROR("PhysiologyEngine: %s%s", msg.c_str(), origin.c_str());
        }
        void ForwardFatal(const std::string& msg, const std::string& origin) override
        {
            AZLOG_FATAL("PhysiologyEngine: %s%s", msg.c_str(), origin.c_str());
        }
    };

    void PhysiologyEngineComponentController::Reflect(AZ::ReflectContext* context)
    {
        PhysiologyEngineComponentConfig::Reflect(context);

        if (auto serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PhysiologyEngineComponentController>()
                ->Field("Config", &PhysiologyEngineComponentController::m_config)
                ->Version(1);
        }
    }

    PhysiologyEngineComponentController::PhysiologyEngineComponentController(const PhysiologyEngineComponentConfig& config)
    {
        SetConfiguration(config);
    }

    void PhysiologyEngineComponentController::OnTick(float deltaTime, AZ::ScriptTimePoint time)
    {
        if (m_pulseEngine)
        {
            m_CurrentTime_s += deltaTime;
            if(m_CurrentTime_s >= m_TimeStep_s) {
                int count = (int)(m_CurrentTime_s / m_TimeStep_s);
                if (count > 2) count = 2; // Push off remaining updats until next frame
                for (int i = 0; i < count; i++)
                {
                    if (!m_pulseEngine->AdvanceModelTime())
                    {
                        break;
                    }
                    PhysiologyNotificationBus::Event(m_entityId.GetEntityId(), &PhysiologyEvents::OnSimulationTimeStep, m_pulseEngine->GetSimulationTime(TimeUnit::s));   
                }
                m_CurrentTime_s = m_CurrentTime_s - (count * m_TimeStep_s);
            }
        }
    }

    void PhysiologyEngineComponentController::Init()
    {
    }

    const PhysiologyEngineComponentConfig& PhysiologyEngineComponentController::GetConfiguration() const
    {
        return m_config;
    }

    void PhysiologyEngineComponentController::SetConfiguration(const PhysiologyEngineComponentConfig& config)
    {
        m_config = config;
        m_pulseEngine.reset(CreatePulseEngine(config.m_modelType).release());
        m_pulseLogger.reset(new PulseLogger());
        m_pulseEngine->GetLogger()->LogToConsole(false);
        m_pulseEngine->GetLogger()->AddForward(m_pulseLogger.get());
        m_TimeStep_s = m_pulseEngine->GetTimeStep(TimeUnit::s);
    }

    void PhysiologyEngineComponentController::Activate(AZ::EntityComponentIdPair entityId)
    {
        m_entityId = entityId;
        AZ::TickBus::Handler::BusConnect();
    }

    void PhysiologyEngineComponentController::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
    }

} // namespace PulseEngine