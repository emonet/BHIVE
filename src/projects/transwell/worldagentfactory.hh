/*
 * worldagentfactory.hh
 *
 *  Created on: Dec 8, 2009
 *      Author: jentsch
 */

#ifndef WORLDAGENTFACTORY_HH_
#define WORLDAGENTFACTORY_HH_

#include "../../agent/agentFactory/agent_factory.hh"
#include "../../agent/data/grid/nvoxel.hh"
#include "../../agent/data/grid/grid.hh"
#include "../../agent/data/template/tdata.hh"
#include "../../agent/messageGenerator/transwellMessageGenerator/transwellMessageGenerator.hh"
#include "../../agent/action/transwellAction/transwellAction.hh"
#include "transwellgeometryconstructor.hh"
#include "../../simulators/pde/cranknicolson.hh"
#include "../../util/rand/rand.hh"

using namespace std;
using namespace Hive;

namespace Transwell {
	/**
	 * @brief world agent factory of the transwell world. it creates
	 *
	 * @author Garrit Jentsch
	 *
	 * @date Dec 8, 2009 last edited Dez 8, 2009
	 */
	class WorldAgentFactory : public AgentFactory {
	public:
		WorldAgentFactory();
		WorldAgentFactory(InputSystemReader *isr);
		~WorldAgentFactory();

		Agent* createAgent();
		Agent* createAgent(Action **as);

		Agent* duplicateAgent(Agent *ag);

		void finalise();

		void setNumberCells(int i);

	protected:
		void addActionsToAgentsActionSet(Agent *ag);
		void addSimulatorToAgent(Agent *ag);
		void addMessageGeneratorsToAgent(Agent *ag);

	private:
		int numbercells;
		TranswellGeometryConstructor *tgc;
	};
}

#endif /* WORLDAGENTFACTORY_HH_ */
