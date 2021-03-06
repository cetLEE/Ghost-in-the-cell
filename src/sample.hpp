#include "Logging.hpp"

#include "Program/Game.hpp"
#include "Player/Player.hpp"
#include "Player/DummyPlayer.hpp"
#include "Player/LazyPlayer.hpp"
#include "Player/HumanPlayer.hpp"

int runSample() {
    LOG_INFO("runSample is called with no args");
    PlayerPtr p1 = std::make_shared<DummyPlayer>();
    PlayerPtr p2 = std::make_shared<LazyPlayer>();
    try {
        Game g(p1, p2);
        g.Run();
    } catch (const char* msg) {
        LOG_ERROR("Exception occured: {}", msg);
    } catch (std::string& msg) {
        LOG_ERROR("Exception occured: {}", msg);
    }
    return 0;
}
