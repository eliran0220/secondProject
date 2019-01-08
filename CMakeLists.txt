cmake_minimum_required(VERSION 3.12)
project(secondProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(secondProject main.cpp serverPackage/Server.h serverPackage/MySerialServer.cpp serverPackage/MySerialServer.h clientPackage/ClientHandler.h clientPackage/MyTestClientHandler.cpp clientPackage/MyTestClientHandler.h solverPackage/Solver.h cachePackage/CacheManager.h cachePackage/FileCacheManager.cpp cachePackage/FileCacheManager.h solverPackage/StringReverser.cpp solverPackage/StringReverser.h searchPackage/Searcher.h searchPackage/BestFirstSearch.cpp searchPackage/BestFirstSearch.h searchPackage/Searchable.h searchPackage/State.cpp searchPackage/State.h searchPackage/ISearcher.h)

SET(CMAKE_CXX_FLAGS -pthread)