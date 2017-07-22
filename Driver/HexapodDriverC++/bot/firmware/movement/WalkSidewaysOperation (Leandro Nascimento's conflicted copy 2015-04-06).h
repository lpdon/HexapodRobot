/*
 * WalkSidewaysOperation.h
 *
 *  Created on: 05/04/2013
 */

#ifndef BOT_FIRMWARE_MOVEMENT_WALKSIDEWAYSOPERATION_H_
#define BOT_FIRMWARE_MOVEMENT_WALKSIDEWAYSOPERATION_H_

#include "../../../base.h"
#include "../../../bot/firmware/MovementOperation.h"

namespace bot
{
	namespace firmware
	{
		namespace movement
		{
			/**
			 * Classe definindo a operação de andar para um dos lados.
			 */
			class WalkSidewaysOperation :
					public MovementOperation
			{
				private:
					/* pool de objetos. */
					friend class base::ObjectPool<WalkSidewaysOperation, POOLSIZE_bot_firmware_movement_WalkSidewaysOperation>;
					static base::ObjectPool<WalkSidewaysOperation, POOLSIZE_bot_firmware_movement_WalkSidewaysOperation> m_pool;

				protected:
					/* construtor e destrutor. */
					WalkSidewaysOperation();
					~WalkSidewaysOperation();

					/* gerência de memória. */
					void initialize(int distance, bool isLeftToRight);
					void finalize();

				public:
					/* factory. */
					static WalkSidewaysOperation* create(bool isLeftToRight, int distance);

				protected:
					/* flag indicando se o sentido de movimento é da esquerda para a direita. */
					bool m_isLeftToRight;

					/* distância que deve ser percorrida. */
					int m_totalDistance;

					/* distância que deve ser percorrida. */
					int m_walkedDistance;

				public:
					/* implementação de MovementOperation. */
					int getLength();

					/* implementação de MovementOperation. */
					int getValue();

					/* implementação de MovementOperation. */
					void run(int id, LegPositions& position, _strong(MovementManager)& manager);
			};
		}
	}
}

#endif /* BOT_FIRMWARE_MOVEMENT_WALKSIDEWAYSOPERATION_H_ */
