#pragma once
#include<deque>
#include<set>
#include<chrono>
#ifdef _WIN32
#define _WIN32_WINNT 0X0A00
#endif
#define ASIO_STANDALONE
#include <iostream>
#include<asio.hpp>
#include<asio/ts/buffer.hpp>
#include<asio/ts/internet.hpp>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;