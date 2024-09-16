#pragma once

#include "game/game.hpp"
#include <utils/info_string.hpp>

enum sort_types
{
	hostname,
	map,
	mode,
	players,
	ping,
	verified
};

namespace server_list
{
	struct server_info
	{
		// gotta add more to this
		int clients;
		int max_clients;
		int bots;
		int ping;
		std::string host_name;
		std::string map_name;
		std::string game_type;
		std::string mod_name;
		game::CodPlayMode play_mode;
		char in_game;
		game::netadr_s address;
		bool is_private;
		std::string connect_address;
	};

	void sort_serverlist(int sort_type);

	bool sl_key_event(int key, int down);

	int get_player_count();
	int get_server_count();
	int get_server_limit();
	void add_favourite(int server_index);
	void delete_favourite(int server_index);
	void sort_servers(int sort_type);

	namespace tcp {
		// TCP functions
		void populate_server_list();

		void populate_server_list_threaded();

		void add_server_to_list(const std::string &infoJson, const std::string &connect_address, int server_index);

		void parse_favourites_tcp();

		void parse_favourites_tcp_threaded();

		int get_server_limit_per_page();

		int get_current_page();

		int get_total_pages();

		int get_page_number(int serverIndex);

		void load_page(int pageNumber);

		void next_page();

		void previous_page();

		void add_server_to_page(int pageIndex, server_info &serverInfo);

		std::string get_notification_message();

		std::string get_error_message();

		std::string get_error_header();

		void display_error(std::string header, std::string message);

		bool check_can_join(std::string& connect_address);

	}
}