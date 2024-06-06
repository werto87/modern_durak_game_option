#pragma once

#include <durak/gameOption.hxx>
#include <login_matchmaking_game_shared/gameOptionBase.hxx>
#include <optional>
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

class GameOption : public user_matchmaking_game::GameOptionBase
{
public:
  durak::GameOption gameOption{};
  TimerOption timerOption{};
  uint64_t computerControlledPlayerCount{};
  shared_class::OpponentCards opponentCards{};
};

}
BOOST_FUSION_ADAPT_STRUCT (shared_class::GameOption, gameOption, timerOption, computerControlledPlayerCount, opponentCards)

namespace user_matchmaking_game
{

std::expected<void, std::string>
errorInGameOption (user_matchmaking_game::GameOptionBase const &gameOptionBase)
{
  shared_class::GameOption const &gameOption = dynamic_cast<shared_class::GameOption const &> (gameOptionBase);
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