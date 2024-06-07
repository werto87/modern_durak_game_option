#pragma once

#include <confu_json/to_json.hxx>
#include <confu_json/to_object.hxx>
#include <confu_json/util.hxx>
#include <durak/gameOption.hxx>
#include <login_matchmaking_game_shared/gameOptionAsString.hxx>
#include <optional>
#include <sstream>
#include <string>

typedef std::vector<std::pair<std::string, long long int> > UserTimeMilliseconds;

namespace shared_class
{
enum struct TimerType
{
  noTimer,
  resetTimeOnNewRound,
  addTimeOnNewRound
};
}
BOOST_FUSION_DEFINE_STRUCT ((shared_class), TimerOption, (shared_class::TimerType, timerType) (uint64_t, timeAtStartInSeconds) (uint64_t, timeForEachRoundInSeconds))
namespace shared_class
{
enum struct OpponentCards
{
  showNumberOfOpponentCards,
  showOpponentCards,
};
}
BOOST_FUSION_DEFINE_STRUCT ((shared_class), GameOption, (durak::GameOption, gameOption) (shared_class::TimerOption, timerOption) (uint64_t, computerControlledPlayerCount) (shared_class::OpponentCards, opponentCards))

namespace user_matchmaking_game
{
[[nodiscard]] inline std::string
gameOptionDefaultValues ()
{
  auto ss = std::stringstream{};
  ss << confu_json::to_json (shared_class::GameOption{});
  return ss.str ();
}
[[nodiscard]] inline std::expected<void, std::string>
errorInGameOption (user_matchmaking_game::GameOptionAsString const &gameOptionAsString)
{
  auto ec = boost::system::error_code{};
  auto result = confu_json::read_json (gameOptionAsString.gameOptionAsString, ec);
  if (ec)
    {
      auto error = std::stringstream{};
      error << "error while parsing string: error code: " << ec << std::endl;
      error << "error while parsing string: stringToParse: " << gameOptionAsString.gameOptionAsString << std::endl;
      return std::unexpected (error.str ());
    }
  else
    {
      shared_class::GameOption const &gameOption = confu_json::to_object<shared_class::GameOption> (result);
      if (gameOption.computerControlledPlayerCount >= 2)
        {
          return std::unexpected ("'computerControlledPlayerCount >= 2' not more than one computer controlled player per game is allowed");
        }
      else
        {
          return {};
        }
    }
}
}