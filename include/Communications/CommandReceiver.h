//
// Created by johnathan on 28/05/18.
//

#ifndef VSS_CORE_COMMANDRECEIVER_H
#define VSS_CORE_COMMANDRECEIVER_H

#include <Interfaces/ICommandReceiver.h>
#include <zmq.hpp>

namespace vss {

    class CommandReceiver : public ICommandReceiver {
    public:
        CommandReceiver();
        ~CommandReceiver() override;

        void createSocket(ExecutionConfig&) override;
        void createSocket(Address) override;
        void createSocket(TeamType) override;
        void closeSocket() override;
        Command receiveCommand() override;

    protected:
        void setupAddress(TeamType);
        void setupAddress(ExecutionConfig&);
        void connect();
    };

}

#endif //VSS_CORE_COMMANDRECEIVER_H
