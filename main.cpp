#include <iostream>
#include <init.hpp>
#include <dpp/dpp.h>
int main() {
    dpp::cluster bot("OTExMjU5NjIyODYwNTM3ODY2.GkOVdZ.KvyV3hAecM9td-vuKnr3KH4JFI_NsHDN1Kkf6c");

    bot.on_slashcommand([](auto event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
    });

    bot.on_ready([&bot](auto event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(
                    dpp::slashcommand("ping", "Ping pong!", bot.me.id)
            );
        }
    });
    std::hash<std::basic_string<char>> hash;
    hash("abc");
    bot.start(dpp::st_wait);
}