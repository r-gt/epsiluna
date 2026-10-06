int l_create_map(lua_State *L){
	char *path = luaL_checkstring(L, 1);
	map *t = create_map(path);
	if (!t) return luaL_error(L, "could not load map '%s'", path);

	map **ud = lua_newuserdata(L, sizeof(map *));
	*ud = t;

	luaL_setmetatable(L, "map");
	return 1;
}

int l_select_map(lua_State *L){
	map **ud = luaL_checkudata(L, 1, "map");
	selected_map = *ud;
	return 0;
}


int l_get_tile_map(lua_State *L){
	lua_pushinteger(L, get_tile_map(luaL_checkinteger(L, 1), luaL_checkinteger(L, 2)));
	return 1;
}

int l_set_tile_map(lua_State *L){
	lua_pushinteger(L, set_tile_map(luaL_checkinteger(L, 1), luaL_checkinteger(L, 2), luaL_checkinteger(L, 3)));
	return 1;
}

int l_destroy_map(lua_State *L){
	destroy_map();
	return 1;

}
