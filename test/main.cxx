#include "modern_durak_game_option/src.hxx"
#include "modern_durak_game_option/userDefinedGameOption.hxx"
#include <boost/json/src.hpp>
#include <confu_json/to_json.hxx>
#include <sstream>
int
main ()
{
  auto gameOption = shared_class::GameOption{};
  gameOption.computerControlledPlayerCount = 2;
  auto gameOptionAsString = user_matchmaking_game::GameOptionAsString{};
  auto ss = std::stringstream{};
  ss << confu_json::to_json (gameOption);
  gameOptionAsString.gameOptionAsString = ss.str ();
  if (auto result = user_matchmaking_game::errorInGameOption (gameOptionAsString))
    {
      std::cout << "okay" << std::endl;
    }
  else
    {
      std::cout << result.error () << std::endl;
    }
  return 0;
}