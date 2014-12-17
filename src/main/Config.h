#ifndef __CONFIG__
#define __CONFIG__

#include "generated/StellarXDR.h"

// Copyright 2014 Stellar Development Foundation and contributors. Licensed
// under the ISC License. See the COPYING file at the top-level directory of
// this distribution or at http://opensource.org/licenses/ISC

namespace stellar
{
class Config
{

  public:
    // application config
    bool RUN_STANDALONE;
    int PROTOCOL_VERSION;
    std::string VERSION_STR;
    std::string LOG_FILE_PATH;
    uint32_t DESIRED_BASE_FEE; // in stroops
    int HTTP_PORT;         // what port to listen for commands on. 0 for don't
    bool PUBLIC_HTTP_PORT; // if you accept commands from not localhost

    // overlay config
    int PEER_PORT;
    unsigned TARGET_PEER_CONNECTIONS;
    unsigned MAX_PEER_CONNECTIONS;
    // Peers we will always try to stay connected to
    std::vector<std::string> PREFERRED_PEERS;
    std::vector<std::string> KNOWN_PEERS;

    // FBA config
    stellarxdr::uint256 VALIDATION_SEED;
    int QUORUM_THRESHOLD;
    std::vector<stellarxdr::uint256> QUORUM_SET;

    Config();

    void load(const std::string& filename);
};
}

#endif
