#include "epsilon/lua/lua.h"
#include "epsilon/lua/lualib.h"
#include "epsilon/lua/lauxlib.h"
#include "epsilon/engine.h"


lua_State *L;
#include "epsilon/luacompat/luacompat.h"


int main(int argc, char *argv[]){


	L = luaL_newstate();

	if(L==NULL){
		printf("error creating a new LUA state\n");
		return 1;
	}

	luaL_openlibs(L);
	setup_epsilon();

	bind_lua();




	bind_lua();

	if(!argv[1])
		luaL_dostring(L, nogame_demo);

	else if (luaL_dofile(L, argv[1]) != LUA_OK) {

		fprintf(stderr, "Lua error: %s\n", lua_tostring(L, -1));

	}


	lua_close(L);

	
	return 0;
}
