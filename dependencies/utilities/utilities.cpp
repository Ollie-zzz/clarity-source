#include "utilities.hpp"
#include "../common_includes.hpp"
#include <psapi.h>

std::uint8_t* utilities::pattern_scan(void* module, const char* signature) {
	static auto pattern_to_byte = [](const char* pattern) {
		auto bytes = std::vector<int>{};
		auto start = const_cast<char*>(pattern);
		auto end = const_cast<char*>(pattern) + strlen(pattern);

		for (auto current = start; current < end; ++current) {
			if (*current == '?') {
				++current;
				if (*current == '?')
					++current;
				bytes.push_back(-1);
			}
			else {
				bytes.push_back(strtoul(current, &current, 16));
			}
		}
		return bytes;
	};

	auto dos_headers = reinterpret_cast<PIMAGE_DOS_HEADER>(module);
	auto nt_headers = reinterpret_cast<PIMAGE_NT_HEADERS>((std::uint8_t*)module + dos_headers->e_lfanew);

	auto size_of_image = nt_headers->OptionalHeader.SizeOfImage;
	auto pattern_bytes = pattern_to_byte(signature);
	auto scan_bytes = reinterpret_cast<std::uint8_t*>(module);

	auto s = pattern_bytes.size();
	auto d = pattern_bytes.data();

	for (auto i = 0ul; i < size_of_image - s; ++i) {
		bool found = true;
		for (auto j = 0ul; j < s; ++j) {
			if (scan_bytes[i + j] != d[j] && d[j] != -1) {
				found = false;
				break;
			}
		}
		if (found) {
			return &scan_bytes[i];
		}
	}
	return nullptr;


}

void utilities::apply_clan_tag(const char* name) {
	using Fn = int(__fastcall*)(const char*, const char*);
	static auto apply_clan_tag_fn = reinterpret_cast<Fn>(utilities::pattern_scan(GetModuleHandleA("engine.dll"), "53 56 57 8B DA 8B F9 FF 15"));
	apply_clan_tag_fn(name, name);
};

void utilities::load_named_sky(const char* sky_name) {
	using Fn = void(__fastcall*)(const char*);
	static auto load_named_sky_fn = reinterpret_cast<Fn>(utilities::pattern_scan(GetModuleHandleA("engine.dll"), "55 8B EC 81 EC ? ? ? ? 56 57 8B F9 C7 45"));
	load_named_sky_fn(sky_name);
}