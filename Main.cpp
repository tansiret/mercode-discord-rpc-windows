// Internal Header Files
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <cstring>

// External Header Files
#include <discord_rpc.h>
#include "Utils/StringUtils.h"


void onReady(const DiscordUser* discordUser) {
	printf("[Mercode Discord RPC] Client Connected!\n");
	printf("Username: %s#%s\n", discordUser->username, discordUser->discriminator);
	printf("User ID: %s\n", discordUser->userId);
	printf("\n");
}

void onDisconnected(int errorCode, const char* message) {
	printf("[Mercode Discord RPC] Client Disconnected!\n");
	printf("Error Message (Errno: #%d): %s\n", errorCode, message);
	printf("\n");
}

void onErrored(int errorCode, const char* message) {
	printf("[Mercode Discord RPC] Error Occurred!\n");
	printf("Error Message (Errno: #%d): %s\n", errorCode, message);
	printf("\n");
}

void onJoinGame(const char* joinSecret) {
	printf("[Mercode Discord RPC] Another Client Try To Join Game With Secret - %s!\n", joinSecret);
	printf("[Mercode Discord RPC] That Action Has Been Cancelled Because It's Disable!\n");
	printf("\n");
}

void onSpectateGame(const char* spectateSecret) {
	printf("[Mercode Discord RPC] Another Client Try To Spectate Game With Secret - %s!\n", spectateSecret);
	printf("[Mercode Discord RPC] That Action Has Been Cancelled Because It's Disable!\n");
	printf("\n");
}

void onJoinRequest(const DiscordUser* discordUser) {
	printf("[Mercode Discord RPC] Received Join Request!\n");
	printf("From: %s#%s\n", discordUser->username, discordUser->discriminator);
	printf("\n");
}

static void InitDiscordAPI() {
	printf("Initializing Discord API . . . \n");
	DiscordEventHandlers eventHandlers;
	memset(&eventHandlers, 0 , sizeof(eventHandlers));

	eventHandlers.ready = onReady;
	eventHandlers.disconnected = onDisconnected;
	eventHandlers.errored = onErrored;
	eventHandlers.joinGame = onJoinGame;
	eventHandlers.spectateGame = onSpectateGame;
	eventHandlers.joinRequest = onJoinRequest;

	Discord_Initialize("593720276798144544", &eventHandlers, 1, NULL);
	printf("Initialized Discord API!\n");
	printf("\n");
}

static void UpdateDiscordRPC() {
	printf("Updating Discord RPC . . . \n");
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));

	discordPresence.state = "Coding | Idling | AFKing";
	discordPresence.details = "Making Products";
	discordPresence.startTimestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	discordPresence.largeImageKey = "logo";
	discordPresence.largeImageText = "Programming";
	discordPresence.partyId = "0";
	discordPresence.partySize = 0;
	discordPresence.partyMax = 0;
	discordPresence.joinSecret = "1";

	Discord_UpdatePresence(&discordPresence);
	printf("Updated Discord RPC!\n");
	printf("\n");
}

static void ClearDiscordRPC() {
	printf("Cleaning Discord RPC . . . \n");
	Discord_ClearPresence();
	printf("Cleanned Discord RPC . . . \n");
	printf("\n");
}

static void ShutdownDiscordAPI() {
	printf("Shutting Down Discord API . . . \n");
	Discord_Shutdown();
	printf("Shutted Down Discord API!\n");
}

static void LaunchCustomConsole() {
	while (true) {
		printf("Console Manager > ");
		
		std::string arg;
		std::cin >> arg;
		arg = StringUtils::tolower(arg);

		if (arg == "update") {
			UpdateDiscordRPC();
		}

		if (arg == "clear") {
			ClearDiscordRPC();
		}

		if (arg == "exit" || arg == "kill" || arg == "shutdown") {
			printf("Exiting . . . ");
			ShutdownDiscordAPI();
			printf("Exited!");

			exit(0);
		}
	}
}

int main() {
	InitDiscordAPI();
	LaunchCustomConsole();
	ShutdownDiscordAPI();

	return 0;
}