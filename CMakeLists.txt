cmake_minimum_required (VERSION 3.8)
project (mercode-discord-rpc)

set (CMAKE_BUILD_TYPE Release)

include_directories (${PROJECT_SOURCE_DIR}/lib/discord-rpc/include)
add_executable (mercode-discord-rpc 
	"Main.cpp" 
	"Utils/StringUtils.cpp" 
	"Utils/StringUtils.h"
)
target_link_libraries(mercode-discord-rpc ${PROJECT_SOURCE_DIR}/lib/discord-rpc/lib/discord-rpc.lib)