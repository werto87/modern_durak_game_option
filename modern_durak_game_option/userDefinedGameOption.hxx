#pragma once

#include <confu_json/to_json.hxx>
#include <confu_json/to_object.hxx>
#include <confu_json/util.hxx>
#include <durak/gameOption.hxx>
#include <login_matchmaking_game_shared/gameOptionAsString.hxx>
#include <optional>
#include <sstream>
#include <string>
#include <expected>

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
[[nodiscard]] std::string gameOptionDefaultValues ();
[[nodiscard]] std::expected<void, std::string> errorInGameOption (user_matchmaking_game::GameOptionAsString const &gameOptionAsString);
}