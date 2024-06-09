#include "modern_durak_game_option/userDefinedGameOption.hxx"

std::expected<void, std::string>
user_matchmaking_game::errorInGameOption (user_matchmaking_game::GameOptionAsString const &gameOptionAsString)
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
std::string
user_matchmaking_game::gameOptionDefaultValues ()
{
  auto ss = std::stringstream{};
  ss << confu_json::to_json (shared_class::GameOption{});
  return ss.str ();
}
