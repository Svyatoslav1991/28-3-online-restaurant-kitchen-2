#pragma once

#include <mutex>
#include <queue>
#include <vector>
#include <string>

static std::mutex order_mtx;
static std::mutex ready_mtx;
static std::mutex print_mtx;

static size_t counter = 0;
static std::queue<std::string> qOrderedFood;
static std::queue<std::string> qReadyFood;
static const std::vector<std::string> vFoods = { "pizza", "soup", "steak", "salad", "sushi" };

void foodOrder() noexcept;
void cooking() noexcept;
void delivery() noexcept;