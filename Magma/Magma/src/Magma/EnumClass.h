#pragma once
#include "mgpch.h"

static const std::vector<std::string> generateEnumNames(const char* element) {
	std::vector<std::string> items = std::vector<std::string>();
	std::string buffer = std::string();

	while (*element != '\0') {
		if (*element == ',') {
			items.push_back(buffer);
			buffer.clear();
		}
		else if (*element != ' ' && *element != '=') {
			buffer += *element;
		}
		++element;
	}

	if (!buffer.empty()) {
		items.push_back(buffer);
	}

	return items;
}

#define MAGMA_ENUM(EnumName, ...)																												\
enum class EnumName { __VA_ARGS__ };																											\
static const std::vector<std::string> EnumName##itemNames = generateEnumNames(#__VA_ARGS__);													\
																																				\
static std::ostream& operator << (std::ostream& os, const EnumName& element) {																	\
	os << EnumName##itemNames.at(int(element));																									\
	return os;																																	\
}																																				\
