#ifndef LUA_EASELIB_H
#define LUA_EASELIB_H

int l_ease(lua_State *L){
	lua_pushnumber(L, ease(luaL_checknumber(L, 1), luaL_checkinteger(L, 2), luaL_checkinteger(L, 2) ) );
	return 1;
}

#endif
