#pragma once

namespace hooks {
	bool initialize();
	void release();

	namespace create_move {
		using fn = bool(__stdcall*)(float, c_usercmd*);
		bool __fastcall hook(void* ecx, void* edx, int input_sample_frametime, c_usercmd* cmd);
	};

	namespace paint_traverse {
		using fn = void(__thiscall*)(i_panel*, unsigned int, bool, bool);
		void __stdcall hook(unsigned int panel, bool force_repaint, bool allow_force);
	}


	namespace frame_stage_notify {
		using fn = void(__thiscall*)(void*, client_frame_stage_t);
		void __stdcall hook(client_frame_stage_t frame_stage);
	}
	namespace lock_cursor {
		using fn = void(__thiscall*)(void*);
		void __stdcall hook(c_usercmd* cmd);
	}

	namespace in_key_event {
		using fn = int(__stdcall*)(int, int, const char*);
		int __fastcall hook(void* ecx, int edx, int event_code, int key_num, const char* current_binding);
	}

	namespace scene_end {
		using fn = void(__thiscall*)(void*);
		void __stdcall hook();
	}

	namespace fire_game_event {
		using fn = bool(__thiscall*)(i_game_event_manager2* manager, i_game_event* event);
		bool __stdcall hook(i_game_event* event);
	}

}