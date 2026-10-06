#ifndef LUA_AUDIO_H
#define LUA_AUDIO_H

int l_create_audio(lua_State *L){
	const char *path = luaL_checkstring(L, 1);
	int predecode = lua_toboolean(L, 2);

	audio *t = create_audio(path, predecode);
	if (!t) return luaL_error(L, "could not load audio '%s'", path);

	audio **ud = lua_newuserdata(L, sizeof(audio *));
	*ud = t;

	luaL_setmetatable(L, "audio");
	return 1;
}

int l_select_audio(lua_State *L){
	audio **ud = luaL_checkudata(L, 1, "audio");
	selected_audio = *ud;
	return 0;
}

int l_play_audio(lua_State *L){
	play_audio();
	return 1;
}

int l_stop_audio(lua_State *L){
	stop_audio();
	return 1;
}

int l_resume_audio(lua_State *L){
	resume_audio();
	return 1;
}



int l_set_speed(lua_State *L){
	set_speed(luaL_checknumber(L,1));
	return 1;
}


int l_set_volume(lua_State *L){
	set_volume(luaL_checknumber(L,1));
	return 1;
}


int l_unload_audio(lua_State *L){
	unload_audio();
	return 1;
}

int l_is_playing(lua_State *L){
	lua_pushboolean (L, (int)is_playing());
	return 1;
}

#endif
