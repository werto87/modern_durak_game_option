#pragma once

#include <boost/fusion/adapted/struct/define_struct.hpp>
#include <durak/gameOption.hxx>
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

}
BOOST_FUSION_DEFINE_STRUCT ((shared_class), GameOption, (durak::GameOption, gameOption) (shared_class::TimerOption, timerOption) (uint64_t, computerControlledPlayerCount) (shared_class::OpponentCards, opponentCards))

namespace shared_class
{
std::optional<std::string> inline errorInGameOption (shared_class::GameOption const &gameOption)
{
  if (gameOption.computerControlledPlayerCount >= 2)
    {
      return "only one computer controlled player per game";
    }
  else
    {
      return std::nullopt;
    }
}
}