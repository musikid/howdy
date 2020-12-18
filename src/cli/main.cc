#include <cstdlib>
#include <iostream>

#include <CLI/App.hpp>
#include <CLI/Config.hpp>
#include <CLI/Formatter.hpp>

using namespace CLI;
int main(int argc, char *argv[]) {
  App app("Command line interface for Howdy face authentication.");
  app.require_subcommand(1);

  std::string user = std::getenv("SUDO_USER");
  app.add_option("-U,--user", user, "Set the user account to use");

  bool skip = false;
  app.add_flag("-y,--yes", skip, "Skip all questions");

  App *add = app.add_subcommand("add", "Add a new face model");
  App *clear = app.add_subcommand("clear", "Clear existing model");
  App *config =
      app.add_subcommand("config", "Open the configuration  file in an editor");
  App *disable = app.add_subcommand("disable", "Disable Howdy PAM module");
  App *enable = app.add_subcommand("enable", "Enable Howdy PAM module");
  App *list = app.add_subcommand("list", "List all models");
  App *remove = app.add_subcommand("remove", "Remove a model");
  App *snap = app.add_subcommand("snapshot", "Snapshot");
  App *test = app.add_subcommand("test", "Test if your face is recognized");

  try {
    app.parse(argc, argv);
  } catch (const CLI::ParseError &e) {
    return app.exit(e);
  }
}
