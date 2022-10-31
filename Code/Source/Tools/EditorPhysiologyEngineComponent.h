#pragma once

#include <AzToolsFramework/ToolsComponents/EditorComponentAdapter.h>

#include <Clients/PhysiologyEngineComponent.h>
#include <Clients/PhysiologyEngineComponentConfig.h>
#include <Clients/PhysiologyEngineComponentController.h>
namespace PulseEngine
{

using EditorPhysiologyEngineComponentBase = AzToolsFramework::Components::EditorComponentAdapter<PhysiologyEngineComponentController,
            PhysiologyEngineComponent, PhysiologyEngineComponentConfig>
class EditorPhysiologyEngineComponent
    : EditorPhysiologyEngineComponentBase {

};

}