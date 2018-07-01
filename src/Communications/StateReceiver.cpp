/*
 * This file is part of the VSS-SDK project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include <Helpers/CoordinateTransformer.h>
#include <Domain/Constants.h>
#include "Communications/StateReceiver.h"
#include "Helpers/StateMapper.h"

namespace vss{

    StateReceiver::StateReceiver(){
        address = Address(DEFAULT_STATE_RECEIVE_ADDRESS, DEFAULT_STATE_PORT);
    }

    void StateReceiver::createSocket(Address address) {
        this->address = address;
        context = new zmq::context_t( 1 );
        socket = new zmq::socket_t( *context, ZMQ_SUB );

        std::cout << "State Receiver Connected: " << this->address << std::endl;
        socket->connect(address.getFullAddress().c_str());

        socket->setsockopt( ZMQ_SUBSCRIBE, "", 0 );
    }

    void StateReceiver::createSocket(){
        context = new zmq::context_t( 1 );
        socket = new zmq::socket_t( *context, ZMQ_SUB );

        std::cout << "State Receiver Connected: " << address << std::endl;
        socket->connect(address.getFullAddress().c_str());

        socket->setsockopt( ZMQ_SUBSCRIBE, "", 0 );
    }

    State StateReceiver::receiveState(FieldTransformationType userTransformation){
        vss_state::Global_State globalState;
        zmq::message_t request;

        socket->recv(&request, 0);
        std::string msg_str( static_cast<char*>(request.data()), request.size());

        globalState.ParseFromString(msg_str);
        auto state = StateMapper::globalStateToState(globalState);

        if (userTransformation == FieldTransformationType::Flip180Degrees) {
            state = CoordinateTransformer::spinField180Degrees(state);
        }

        return state;
    }

}